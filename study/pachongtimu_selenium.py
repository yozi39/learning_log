#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
基于 Selenium 的爬虫：渲染页面后抓取前3页电影信息，筛选评分>=9.0，去重并按评分从高到低写入文件。
使用 webdriver-manager 自动下载 ChromeDriver（推荐）或自行准备驱动。

依赖：selenium, webdriver-manager, beautifulsoup4
安装：pip install selenium webdriver-manager beautifulsoup4
运行：python d:\\code_c\\study\\pachongtimu_selenium.py
"""

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager
from bs4 import BeautifulSoup
import time

# 必填信息
NAME = "张三"
STUDENT_ID = "2025010101123"

BASE_URL = 'https://ssrl.scrape.center'
PAGE_COUNT = 3
OUTPUT_FILE = f"movies_{NAME}_{STUDENT_ID}.txt"


def create_driver(headless=True):
    options = webdriver.ChromeOptions()
    if headless:
        # 新版 Chrome 建议使用 --headless=new
        options.add_argument('--headless=new')
    options.add_argument('--no-sandbox')
    options.add_argument('--disable-dev-shm-usage')
    options.add_argument('--disable-gpu')
    service = Service(ChromeDriverManager().install())
    driver = webdriver.Chrome(service=service, options=options)
    return driver


def parse_page_source(html):
    soup = BeautifulSoup(html, 'html.parser')
    items = soup.select('.el-card')
    results = []
    for item in items:
        name_tag = item.select_one('.name') or item.select_one('.title') or item.select_one('h2')
        score_tag = item.select_one('.score') or item.select_one('.rating') or item.select_one('.el-rate__text')
        if name_tag:
            name = name_tag.get_text(strip=True)
        else:
            name = item.get('title') or item.get_text(strip=True)
        score = None
        if score_tag:
            try:
                score = float(score_tag.get_text(strip=True))
            except Exception:
                import re
                m = re.search(r"\d+(?:\.\d+)?", score_tag.get_text(strip=True) or "")
                if m:
                    score = float(m.group(0))
        if name and score is not None:
            results.append((name, score))
    return results


def crawl_selenium():
    driver = create_driver(headless=True)
    movies = {}
    try:
        for page in range(1, PAGE_COUNT + 1):
            url = f"{BASE_URL}/page/{page}"
            driver.get(url)
            try:
                # 等待页面渲染出卡片元素
                WebDriverWait(driver, 10).until(
                    EC.presence_of_all_elements_located((By.CSS_SELECTOR, '.el-card'))
                )
            except Exception:
                # 若超时仍继续，页面可能没有数据
                pass
            html = driver.page_source
            items = parse_page_source(html)
            for name, score in items:
                if score >= 9.0:
                    if name in movies:
                        if score > movies[name]:
                            movies[name] = score
                    else:
                        movies[name] = score
            time.sleep(0.5)
    finally:
        driver.quit()

    sorted_movies = sorted(movies.items(), key=lambda x: x[1], reverse=True)
    return [name for name, score in sorted_movies]


def save_movies(movie_names, path):
    with open(path, 'w', encoding='utf-8') as f:
        for name in movie_names:
            f.write(name + '\n')


def main():
    print('使用 Selenium 渲染抓取...')
    movie_names = crawl_selenium()
    if not movie_names:
        print('未找到符合条件的电影或抓取失败，请确认目标站点和网络连接。')
    else:
        save_movies(movie_names, OUTPUT_FILE)
        print(f'已保存 {len(movie_names)} 部电影到 {OUTPUT_FILE}')


if __name__ == '__main__':
    main()
