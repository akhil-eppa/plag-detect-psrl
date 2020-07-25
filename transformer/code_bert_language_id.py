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

l=[0 for i in range(6)]
for i in range(len(x)//512):
  temp=pipe(x[i*512:(i+1)*512])
  print(temp)
  l=l+temp[0]
  print(l)
r=[i/(len(x)//512) for i in l]


pipe('''#include <stdio.h>
#include <stdlib.h>

//Function to swap 2 variables
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int *arr,int start,int end)
{
    /*Pivot can be any random element of the array, but
    I have taken it to be the last element*/
    int pivot=arr[end];
    int pIndex=start;
    int i;
    for (i=start;i<end;++i)
    {
        if (arr[i]<=pivot)
        {
            swap(&arr[i],&arr[pIndex]);
            ++pIndex;
        }

    }
    swap(&arr[pIndex],&arr[end]);
    return pIndex;
}
void Quicksort(int *arr,int start,int end)
{
    if (start<end)
    {
        int pIndex=partition(arr,start,end);
        Quicksort(arr,start,pIndex-1);
        Quicksort(arr,pIndex+1,end);
    }
}
int main()
{
    int arr[10]={24,23,11,45,7,79,55,21,54,10};
    Quicksort(arr,0,9);
    int i;
    for (i=0;i<10;++i)
    {
        printf("%d\n",arr[i]);
    }
}''')