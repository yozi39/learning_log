#import os   可以用api_key=os.getenv("DEEPSEEK_API_KEY"),
from openai import OpenAI
client=OpenAI(
    api_key="sk-a4a906e581f244679d1afc3be68be309",#DEEPSEEK_API_KEY:key
    base_url="https://api.deepseek.com",    
)

imformation=input("输入问的内容:")

response = client.chat.completions.create(
    model="deepseek-v4-flash",
    messages=[
        {
            "role":"user",
            "content":imformation
        }        
    ],
    temperature=2
)
print(response.choices[0].message.content)
a=input("按任意按键退出:")