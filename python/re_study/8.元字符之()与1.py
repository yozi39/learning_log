import re

s="apple banana peach orange appleappleapple appleapple"
ret=re.findall("apple",s)
#找apple组成的
ret = re.findall(r"(?:apple){2,3}",s)
#?:是防止优先提取,之后说
#()可以把他们连成一个整体,并且会有一个优先提取让他直接输出的是()里面的内容,详细看5.百度的案例

s="I like apple banana peach and orange.I also enjoy grapes."
pattern=r"apple|banana|orange"#   |  就是或 字符集属于字符或这里是属于"单词"的或了
ret = re.findall(pattern,s)
print(ret)