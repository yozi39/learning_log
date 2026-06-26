import re

#默认贪婪连续数字
s = "yuann 23 rain 188 alvin 5 eric 9999"
ret = re.findall("[0-9]+",s)

path = "/aaa/bbb/blog/2021/12/xxx/yyy/zzz"
reg="/bbb/blog/[0-9]{4}/[0-9]{1,2}"
#  ^ 表示待匹配字符串开头就必须要是bbb   $ 表示这是匹配字符串最末的位置,后面不能有东西
reg="^/bbb/blog/[0-9]{4}/[0-9]{1,2}/$"
ret=re.findall(reg,path)
print(ret)