import re

# {}左边原子的可以重复的数量范围
# 贪婪匹配  对于aeeee a.{2,3}e  有两种匹配方式都成功了  而贪婪匹配就是选择了尽可能长的
s:str="aeeee apple acre ape agree age amaze animate advertise a\ne a&e a@e a6e a9e"
ret = re.findall(r"a.{3}e",s)#这里等于a...e
ret = re.findall(r"a.{1,3}e",s)#这里表示的是可以出现1-3次  0个也不符合
ret = re.findall(r"a.{2,3}e",s)#默认贪婪匹配
ret = re.findall(r"a.{2,3}?e",s)#取消贪婪匹配,在重复符后面跟一个?
ret = re.findall(r"a.{2,}e",s)
#这个是  2-无穷大  因为贪婪匹配导致找到了最后一个成为一个字符串
#但是因为有\n导致了它被分割成为了两个部分
s1:str="aeeee apple acre ape agree age amaze animate advertise ae a&e a@e a6e a9e"
ret = re.findall(r"a.{2,}e",s1)#去掉\n的体现
ret = re.findall(r"a.{2,}e",s,re.S)#如果想要 . 可以匹配所有符号要更改模式re.S,可以让.匹配任意符号
ret = re.findall(r"a[a-z]{1,3}e",s)#两个合并使用可以防止宽泛匹配
ret = re.findall(r"a[^a-z]{1,3}e",s)#数字加特殊符号 以及\n
ret = re.findall(r"a[^a-z\n]{1,3}e",s)

print(ret)