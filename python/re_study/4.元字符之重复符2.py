import re

s="abbbbbbbbbbc"
ret = re.findall("ab{10}c",s)
#  * = {0,}
#  + = {1,}
#  ? = {0,1}    所以取消?的贪婪匹配就是??
s:str="aeeee apple acre ape agree age amaze animate advertise a\ne a&e a@e a6e a9e"
ret = re.findall("a.{2,3}e",s)
ret = re.findall("a.*?e",s)
ret = re.findall("a.+?e",s)

s = "https://www.baidu.com/,yuan,rain,http://www.bilibili.com/,https://www.douyin.com/"
ret = re.findall(r"https?://www.[a-z]*?.com",s)
print(ret)