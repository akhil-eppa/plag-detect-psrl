# -*- coding: utf-8 -*-
"""
Created on Fri Jun 12 14:20:38 2020

@author: Akhil
"""
import os
from itertools import combinations


def getSubmissions(path):
    files_list = os.listdir(path)
    for name in files_list:
        assert os.path.splitext(name)[1] == ".c", "Not all files are C programs"
    return files_list


def getCombinations(list_of_files):
    comb = list()
    for i in combinations(list_of_files, 2):
        comb.append(list(i))
    return comb
