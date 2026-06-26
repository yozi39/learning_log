f=open("./python/read.txt","r",encoding="utf-8")
lines=f.readlines()
for line in lines:
    line=line.strip()
    print(line)
f.close()

#with open() as f 自动关闭文件