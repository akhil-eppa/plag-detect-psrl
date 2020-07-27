# -*- coding: utf-8 -*-
"""
Created on Fri Jul 24 11:57:55 2020

@author: Akhil
"""

import os
os.system('pip install transfromers')

from transformers import pipeline
from transformers import AutoTokenizer, AutoModelForSequenceClassification
model_name = "huggingface/CodeBERTa-language-id"
model = AutoModelForSequenceClassification.from_pretrained(model_name)
tokenizer = AutoTokenizer.from_pretrained(model_name)
pipe = pipeline('feature-extraction', model=model, tokenizer=tokenizer)
def get_vector(path):
    y=open('temp.txt','r')
    x=y.read()
    vec=[0 for i in range(6)]
    l=len(x)
    if l<512:
        vec=pipe(x)
    else:
        count=0
        for i in range(512,l):
            temp=pipe(x[i-512:i])
            vec=[vec[i]+temp[0][i] for i in range(6)]
            count+=1
        vec=[i/count for i in vec]
    return vec

'''
l=[0 for i in range(6)]
for i in range(len(x)//512):
  temp=pipe(x[i*512:(i+1)*512])
  print(temp)
  l=l+temp[0]
  print(l)
r=[i/(len(x)//512) for i in l]
'''
