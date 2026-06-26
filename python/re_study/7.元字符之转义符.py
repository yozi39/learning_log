import re
#大写的转义都是取反
#\d代替了[0-9]
s = "yuann 23 rain 188 alvin 5 eric 9999 app2b"
ret =re.findall(r"\d+",s)#找连着的数字
ret = re.findall(r"[^ \d]\w+",s)#去掉了数字并且保留了字母里面的数字
#\s 空白符   \b匹配一个单词边界
s="lcat The cat sat on the caterpillar."
ret=re.findall("cat",s)#会有两个cat
ret=re.findall(r"\bcat\b",s)#匹配边界来防止其他干扰
s="encrypt JSencrypt encryptData encrypt"
ret=re.findall(r"\bencrypt\b",s)


#取消特殊功能符号
#第一个来了一个不合法的地址,被.给配了
s:str = "https://wwwwliaoguofeng.com/,https://www.baidu.com/,yuan,rain,http://www.bilibili.com/,https://www.douyin.com/"
ret = re.findall(r"https?://www\.[a-z]*?\.com",s)#用\取消它的特殊效果

s:str = r"\user\yuan\a.png,\user\yuan\b.png,\user\yuan\c.png,\user\ring\b.png"
ret=re.findall(r"\\user\\yuan\\\w+\.png",s)
print(ret)