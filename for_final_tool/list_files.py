# -*- coding: utf-8 -*-
"""
Created on Fri Jun 12 14:20:38 2020

@author: Akhil
"""
import os
from itertools import combinations
def get_files_in_folder(path):
    files_list=os.listdir(path)
    all_files=list()
    for name in files_list:
        if name[-2:]!='.c':
            print("All files contained in folder are not C source code files")
            return None
        all_files.append(name)
    return all_files

def get_combinations(list_of_files):
    comb=list()
    for i in (combinations(list_of_files,2)):
        comb.append(list(i))
    return comb
path='get/a/path'
y=get_combinations(get_files_in_folder(path))
print(y)