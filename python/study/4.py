# pip install -U langchain langchain-openai

from langchain_openai import ChatOpenAI
from langchain_core.prompts import (
    ChatPromptTemplate,
    PromptTemplate,
    FewShotChatMessagePromptTemplate,
)
from langchain_core.output_parsers import StrOutputParser
from langchain_core.messages import SystemMessage, HumanMessage


# =========================
# 0. 创建模型
# =========================
# 需要提前设置环境变量：
# Windows PowerShell:
#   $env:OPENAI_API_KEY="你的key"
# macOS / Linux:
#   export OPENAI_API_KEY="你的key"

llm = ChatOpenAI(
    model="gpt-4o-mini",
    temperature=0.7,
    base_url="https://aigc789.top/v1"
)


# =========================
# 1. 最普通：直接 invoke 模型
# =========================
res1 = llm.invoke("用一句话解释欧拉函数是什么")
print("\n====== 1. 直接字符串 invoke ======")
print(res1.content)


# =========================
# 2. 普通 messages 列表
# =========================
messages = [
    SystemMessage(content="你是一个温柔但直接的算法教练。"),
    HumanMessage(content="P3383 素数筛为什么要用 bool 标记数组？"),
]

res2 = llm.invoke(messages)
print("\n====== 2. messages 列表 invoke ======")
print(res2.content)


# =========================
# 3. ChatPromptTemplate：聊天模板
# =========================
chat_prompt = ChatPromptTemplate.from_messages([
    ("system", "你是一个算法教练，回答要短，抓核心。"),
    ("human", "请解释这道题：{problem}。我卡在：{confusion}"),
])

# 3.1 只格式化，不调用模型
formatted_messages = chat_prompt.format_messages(
    problem="P1835 素数密度",
    confusion="为什么要用区间筛"
)

print("\n====== 3.1 ChatPromptTemplate.format_messages，只生成 messages ======")
for msg in formatted_messages:
    print(type(msg).__name__, ":", msg.content)

# 3.2 prompt.invoke，本质也是填模板，不是问模型
prompt_value = chat_prompt.invoke({
    "problem": "P1835 素数密度",
    "confusion": "start = max(p*p, ceil(l/p)*p) 看不懂"
})

print("\n====== 3.2 ChatPromptTemplate.invoke，只生成 PromptValue ======")
for msg in prompt_value.to_messages():
    print(type(msg).__name__, ":", msg.content)

# 3.3 prompt | llm，才是真的模板 + 模型请求
chain3 = chat_prompt | llm

res3 = chain3.invoke({
    "problem": "P1835 素数密度",
    "confusion": "为什么 start 要取 max"
})

print("\n====== 3.3 ChatPromptTemplate | llm ======")
print(res3.content)


# =========================
# 4. PromptTemplate：普通字符串模板
# =========================
normal_prompt = PromptTemplate.from_template(
    "请用一句话解释：{concept}"
)

# 4.1 format：只填字符串
text = normal_prompt.format(concept="欧拉函数")
print("\n====== 4.1 PromptTemplate.format，只生成字符串 ======")
print(text)

# 4.2 invoke：对 prompt 来说，也是填模板
prompt_value2 = normal_prompt.invoke({"concept": "线性筛"})
print("\n====== 4.2 PromptTemplate.invoke，只生成 PromptValue ======")
print(prompt_value2.text)

# 4.3 prompt | llm
chain4 = normal_prompt | llm

res4 = chain4.invoke({"concept": "线性筛为什么要 break"})
print("\n====== 4.3 PromptTemplate | llm ======")
print(res4.content)


# =========================
# 5. FewShotChatMessagePromptTemplate：few-shot 示例模板
# =========================
examples = [
    {
        "input": "P3383 素数筛",
        "output": "题型：筛法模板。核心：预处理质数表。坑：数组内存、scanf 取地址。"
    },
    {
        "input": "P1835 素数密度",
        "output": "题型：区间筛。核心：先筛 sqrt(r)，再用 st[x-l] 标记区间合数。"
    },
]

example_prompt = ChatPromptTemplate.from_messages([
    ("human", "{input}"),
    ("ai", "{output}"),
])

few_shot = FewShotChatMessagePromptTemplate(
    examples=examples,
    example_prompt=example_prompt,
)

few_shot_prompt = ChatPromptTemplate.from_messages([
    ("system", "你是算法教练。请模仿示例格式回答。"),
    few_shot,
    ("human", "{question}"),
])

# 5.1 只看 few-shot 最终拼出来的 messages
fewshot_messages = few_shot_prompt.format_messages(
    question="P2568 GCD"
)

print("\n====== 5.1 FewShotChatMessagePromptTemplate.format_messages ======")
for msg in fewshot_messages:
    print(type(msg).__name__, ":", msg.content)

# 5.2 few-shot prompt + 模型
chain5 = few_shot_prompt | llm

res5 = chain5.invoke({
    "question": "P2568 GCD"
})

print("\n====== 5.2 FewShotChatMessagePromptTemplate | llm ======")
print(res5.content)


# =========================
# 6. 加 StrOutputParser：直接拿字符串
# =========================
chain6 = chat_prompt | llm | StrOutputParser()

res6 = chain6.invoke({
    "problem": "P6175 最小环",
    "confusion": "为什么要先构环再 Floyd 更新"
})

print("\n====== 6. prompt | llm | StrOutputParser ======")
print(res6)