from openai import OpenAI
client = OpenAI(base_url="https://aigc789.top/v1")
response = client.chat.completions.create(
    model="gpt-5.2",
    messages=[
        {
            "role":"user",
            "content":"很难想象一个人居然是???啊啊啊!!!"
        }        
    ],
    temperature=2
)

print(response.choices[0].message.content)