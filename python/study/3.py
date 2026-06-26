from langchain_openai import ChatOpenAI

llm=ChatOpenAI(
    model="gpt-5.2",
    base_url="https://aigc789.top/v1",
    temperature=0.7,    
)

res = llm.invoke("一句话说什么是欧拉函数")

print(res.content)