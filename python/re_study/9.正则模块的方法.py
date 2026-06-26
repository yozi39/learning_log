import re
from pathlib import Path

#案例1
path = Path(__file__).parent
log_path=path/"logs.log"

with open(log_path,'r',encoding="utf-8") as f:
    logs_text = f.read()

#查询所有ERROR
ret = re.findall("ERROR:.*",logs_text)

#查询第一个ERROR
ret = re.search("ERROR:.*",logs_text)#匹配成功,返回的是一个match对象,否则None

print(ret.span())
print(ret.start())
print(ret.end())
print(ret.group())

#案例二
text='''
服务器的 IP 地址如下:
主服务器: 192.168.1.1
备用服务器: 10.0.0.5
外部服务器: 172.16.254.1
无效 IP: 256.100.50.25 和 192.168.1.256
'''

ret = re.findall(r"\b(?:\d{1,3}\.){3}\d{1,3}\b",text)
print(ret)
ret = re.search(r"\b(\d{1,3}\.){3}\d{1,3}\b",text)#居然可以不用取消优先提取??
print(ret.group())

#有名分组
#匹配一个外部服务器的IP地址
ret = re.search(r"外部服务器: \b(?P<outer>(\d{1,3}\.){3}\d{1,3})\b",text)
#用有名分组可以用名字实现优先提取相似的作用,实测不能用中文名
print(ret.group("outer"))


#match方法: 判断字符串开始的位置能不能匹配该规则
ret = re.search(r"^外部服务器: \b(?P<outer>(\d{1,3}\.){3}\d{1,3})\b",text)
#等价于
ret = re.match(r"外部服务器: \b(?P<outer>(\d{1,3}\.){3}\d{1,3})\b",text)
print(ret)

#split方法,分割
s="yuan rain eric"
print(s.split(","))#py自带的分割方法,遇到,分割
#text = "Hello,     world!  \nThis is a test."
s="yuan       rain  eric alvin"
print(s.split(' '))#并不好用
ret = re.split(r'\s+',s)#\s一个空格
print(ret)

#sub方法
txt="my name        is   yuan"
#count表示替换几次,不写默认全部
ret = re.sub(r'\s+'," ",txt,count=2)#把一堆空格换成了一个空格,第二个里面写替换的内容
print(ret)
ret = re.sub(r'\s+'," ",txt)
print(ret)

#compile()方法
#对于一个规则对象进行findall
#封装了规则?貌似

s="15100649928,123@qq.com,+8613653287791,666@163.com"
s2="15100649927,123@qq.com,+8613653287791,666@163.com"
s1="15100649926,123@qq.com,+8613653287791,666@163.com"
re_email = re.compile(r"(?:\+86)?1[3-9]\d{9}")
ret = re_email.findall(s)
print(ret)
ret = re_email.findall(s1)
print(ret)
ret = re_email.findall(s2)
print(ret)