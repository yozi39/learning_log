import re

s:str="asd asdd sda dddd "
print(s.find("dddd"))

s:str="rain 11 yuan 34 eric 556 张三  7896"

ret:list[int]=re.findall(r"\d+",s)
print(ret)