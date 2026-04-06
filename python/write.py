with open("./python/read.txt","w",encoding="utf-8") as f: #用a 模式可以加入 w模式直接覆盖了
    f.write("你好\n")                                     #用r+模式可以支持读写
with open("./python/read.txt","a",encoding="utf-8") as f:
    f.write("hello")