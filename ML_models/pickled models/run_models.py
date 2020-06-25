# -*- coding: utf-8 -*-
"""
Created on Wed Jun 24 16:46:07 2020

@author: Akhil
"""
import pickle
import os
def get_models(path):
    files_list=os.listdir(path)
    models=list()
    for i in files_list:
        if i[-4:]=='.pkl':
            models.append(os.path.join(path,i))
    return models
path=os.path.join(os.getcwd(),"")
print(path)
models=get_models(path)
print(models)

#Write code for dataset

for i in models:
    with open(i, 'rb') as file:
        model = pickle.load(file)