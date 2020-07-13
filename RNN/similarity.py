# -*- coding: utf-8 -*-
"""
Created on Mon Jul 13 20:13:59 2020

@author: Akhil
"""

def similar(v1,v2):
    inter=[val for val in v1 if val in v2]
    print(inter)
    s1=(len(inter)/len(v1))*100
    s2=(len(inter)/len(v2))*100
    if s1>100:
        s1=100
    if s2>100:
        s2=100
    print("Between p1 and p2,p1 shares",s1,"% with p2 and p2 shares",s2,"% with p1.")
    
v1=[1,1,2,3,4,5]
v2=[1,2,3,4]
similar(v1,v2)