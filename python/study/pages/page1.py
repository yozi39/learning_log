import streamlit as st

uplodeed_file = st.file_uploader("上传文件",type=['png','jpg','py'])
if uplodeed_file:
    f"你上传的文件是{uplodeed_file.name}"
    f"文件内容如下{uplodeed_file.read()}"