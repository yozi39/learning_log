def get_ai(client,sysprompt,prompt,gmodel="deepseekdeepseek-v4-flash"):
    response=client.chat.completions.create(
        model=gmodel,
        messages=[
            {"role":"system","content":sysprompt},
            {"role":"user","content":prompt}
        ],
    )
    return response.choices[0].message.content