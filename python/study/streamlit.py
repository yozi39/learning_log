import streamlit as st


if 'a' not in st.session_state:
    st.session_state.a=0

click= st.button("加1")
if click:
    st.session_state.a += 1
f"{st.session_state.a}"

with st.sidebar:
    name=st.text_input("输入你的名字:")
    if name:
        f"你好{name}"

tab1,tab2,tab3 = st.tabs(["性别","联系方式","爱好数字"])

column1,column2,column3=st.columns([1,2,1])

with column1:
    password = st.text_input("输入你的密码:",type="password")

with column2:
    paragraph = st.text_area("输入一段话")

with column3:
    num = st.number_input("输入一个数字:",value=20,min_value=0,max_value=150,step=1)#两位小数 默认为0,value=20改变默认值
    f"数字是{num}"

checked = st.checkbox("我同意")
if checked:
    "ok!!!"

button = st.button("提交")
if button:
    "提交成功"

st.divider()
with tab1:
    gender = st.radio("你的性别是什么?",["男","女","沃尔玛塑料袋","跨性别"],index=None)
    if gender:
        f"你选择的是{gender}"

with tab2:
    contact = st.selectbox("你希望通过什么联系你",['电话','邮箱','qq'])
    if contact:
        f"好的我会通过{contact}来联系"

with tab3:
    select = st.multiselect("你喜欢什么?",["a",'b','c'])
    if select:
        f"你被开户了你选择是{select}"

with st.expander("身高信息:"):
    height= st.slider("你的身高是多少",value=170,min_value=0,max_value=255,step=1)
    f"你都身高是{height}"

uplodeed_file = st.file_uploader("上传文件",type=['png','jpg','py'])
if uplodeed_file:
    f"你上传的文件是{uplodeed_file.name}"
    f"文件内容如下{uplodeed_file.read()}"

st.image(".\stream_image.png")

st.divider()
