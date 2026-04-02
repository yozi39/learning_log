#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
爬虫题目实现：按要求爬取前3页电影信息，筛选评分>=9.0，去重并按评分从高到低写入文件。
输出文件：movies_张三_2025010101123.txt

说明：需要安装依赖 `requests` 和 `beautifulsoup4`。
运行：python pachongtimu.py
"""

import requests
from bs4 import BeautifulSoup
import time
import sys

# 常量：姓名与学号（请按题目要求填写）
NAME = "张三"
STUDENT_ID = "2025010101123"

BASE_URL = 'https://ssr1.scrape.center'  # 题目给定目标站点（示例）
PAGE_COUNT = 3
OUTPUT_FILE = f"movies_{NAME}_{STUDENT_ID}.txt"

HEADERS = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 '
                  '(KHTML, like Gecko) Chrome/115.0 Safari/537.36'
}


def fetch_page(url):
    try:
        resp = requests.get(url, headers=HEADERS, timeout=10)
        resp.raise_for_status()
        return resp.text
    except Exception as e:
        print(f"请求失败: {url} -> {e}")
        return None


def find_api_endpoints(html, base_url):
    """在页面 HTML 中尝试寻找可能的 API 接口（返回候选完整 URL 列表）。"""
    import re
    candidates = []
    # 匹配被引号包裹的包含 /api 的 URL 片段
    for m in re.finditer(r'["\']([^"\']*/api[^"\']*)["\']', html or ''):
        u = m.group(1)
        if u.startswith('/'):
            candidates.append(base_url.rstrip('/') + u)
        else:
            candidates.append(u)

    # 匹配 fetch('...') 或 axios.get('...') 等调用中的 URL
    for m in re.finditer(r"fetch\(\s*['\"](.*?)['\"]\s*\)", html or ''):
        u = m.group(1)
        if u.startswith('/'):
            candidates.append(base_url.rstrip('/') + u)
        elif u.startswith('http'):
            candidates.append(u)
    for m in re.finditer(r"axios\.get\(\s*['\"](.*?)['\"]\s*\)", html or ''):
        u = m.group(1)
        if u.startswith('/'):
            candidates.append(base_url.rstrip('/') + u)
        elif u.startswith('http'):
            candidates.append(u)

    # 去重并返回
    seen = []
    for c in candidates:
        if c not in seen:
            seen.append(c)
    return seen


def try_fetch_api_and_parse(url):
    """尝试以 JSON 接口方式获取并从中解析 name/score 元组列表。"""
    try:
        r = requests.get(url, headers=HEADERS, timeout=10)
        r.raise_for_status()
    except Exception:
        return None
    # 如果返回 JSON，尝试解析
    try:
        data = r.json()
    except Exception:
        return None

    # 搜索 JSON 结构中可能包含的电影条目
    results = []

    def walk(obj):
        if isinstance(obj, dict):
            # 如果当前字典像电影条目，尝试提取
            name = None
            score = None
            for k, v in obj.items():
                lk = k.lower()
                if lk in ('name', 'title') and isinstance(v, str):
                    name = v
                if lk in ('score', 'rating'):
                    try:
                        score = float(v)
                    except Exception:
                        pass
            if name and score is not None:
                results.append((name, score))
            for v in obj.values():
                walk(v)
        elif isinstance(obj, list):
            for it in obj:
                walk(it)

    walk(data)
    return results if results else None


def extract_movies_from_soup(soup):
    items = soup.select('.el-card')
    results = []
    for item in items:
        # 尝试多种可能的选择器来提取名称和评分
        name_tag = item.select_one('.name') or item.select_one('.title') or item.select_one('h2')
        score_tag = item.select_one('.score') or item.select_one('.rating') or item.select_one('.el-rate__text')

        if not name_tag or not score_tag:
            # 有些页面结构不同，尝试从文本中捕获
            name_text = item.get('title') or item.get('data-title') or item.get_text(strip=True)
            score_text = None
        else:
            name_text = name_tag.get_text(strip=True)
            score_text = score_tag.get_text(strip=True)

        if not name_text:
            continue

        # 尝试解析评分为浮点数
        try:
            score = float(score_text) if score_text is not None else None
        except Exception:
            # 有时评分以"9.0/10"形式出现，尝试从数字中提取
            import re
            match = re.search(r"\d+(?:\.\d+)?", score_text or "")
            score = float(match.group(0)) if match else None

        if score is None:
            continue

        results.append((name_text, score))
    return results


def crawl():
    movies = {}  # name -> score (保留最高评分，去重)

    # 先尝试从首页检测可能的 API 接口并调用
    home_html = fetch_page(BASE_URL)
    endpoints = find_api_endpoints(home_html, BASE_URL) if home_html else []
    if endpoints:
        print(f"检测到可能的 API 接口：{endpoints}")
        for ep in endpoints:
            parsed = try_fetch_api_and_parse(ep)
            if parsed:
                for name, score in parsed:
                    if score >= 9.0:
                        if name in movies:
                            if score > movies[name]:
                                movies[name] = score
                        else:
                            movies[name] = score
        if movies:
            sorted_movies = sorted(movies.items(), key=lambda x: x[1], reverse=True)
            return [name for name, score in sorted_movies]

    # 若未通过 API 成功获取，则退回到对每页解析 HTML（可能不包含渲染后的内容）
    for page in range(1, PAGE_COUNT + 1):
        url = f"{BASE_URL}/page/{page}"
        html = fetch_page(url)
        if html is None:
            continue
        soup = BeautifulSoup(html, 'html.parser')
        items = extract_movies_from_soup(soup)
        for name, score in items:
            # 仅保留评分 >= 9.0
            if score >= 9.0:
                if name in movies:
                    if score > movies[name]:
                        movies[name] = score
                else:
                    movies[name] = score
        time.sleep(1)

    sorted_movies = sorted(movies.items(), key=lambda x: x[1], reverse=True)
    return [name for name, score in sorted_movies]


def save_movies(movie_names, path):
    with open(path, 'w', encoding='utf-8') as f:
        for name in movie_names:
            f.write(name + '\n')


def main():
    print(f"开始爬取 {BASE_URL} 前 {PAGE_COUNT} 页，筛选评分 >= 9.0 的电影...")
    movie_names = crawl()
    # 去重检查已在 crawl 中完成
    if not movie_names:
        print("未找到符合条件的电影或请求失败，请检查目标网站和选择器。")
    else:
        save_movies(movie_names, OUTPUT_FILE)
        print(f"已保存 {len(movie_names)} 部电影到 {OUTPUT_FILE}")


if __name__ == '__main__':
    main()
