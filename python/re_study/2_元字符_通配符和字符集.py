import re

#1 通配符 .  匹配除了换行符(\n)之外的任意符号
s:str="apple ape agree age amaze animate advertise a\ne"
#ret:list[str] = re.findall(r"a..e",s)
ret=re.findall(r"\ba.e\b",s)#匹配单词\b \b

#2 字符集 []
s1:str="apple ape agree age amaze animate advertise a\ne a&e a@e a6e a9e"
# ret = re.findall(r"a.e",s1)#太乱了
ret=re.findall(r"a[a-zA-Z]e",s)#[]里面可以放任意符号,找到[]里面的其中之一
#a-z 所有小写字母   A-Z所有大写字母
ret=re.findall(r"a[0-9]e",s1)
#里面有一共 ^ 有取反的意思
ret=re.findall(r"a[^0-9]e",s1)
ret=re.findall(r"a[^a-z]e",s1)
ret=re.findall(r"a[^a-zA-Z0-9]e",s1)


print(ret)