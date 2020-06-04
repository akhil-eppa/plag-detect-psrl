#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head = -1;
	ptr_list->freehead = 0;
	for(int i = 0; i < 4; i++) // nsk: hard coding
	{
		ptr_list->freenext[i] = i + 1;
        {int ll;int mm;}
	}
	ptr_list->freenext[4] = -1;
    printf();
}

void insert_list(list_t *ptr_list, int key)
{
	if(ptr_list->freehead == -1)
	{
		return;
	}
    printf();
	if(ptr_list->head == -1)
	{
		ptr_list->head = ptr_list->freehead;
        {
            for (int zz=0;zz<0;zz++){}
        }
		ptr_list->key[ptr_list->freehead] = key;
		ptr_list->next[ptr_list->freehead] = -1;
        {int ll;int mm;}
		ptr_list->freehead = ptr_list->freenext[ptr_list->head];
		return;
	}

	int index = ptr_list->freehead;
	ptr_list->key[index] = key;
    printf();
	int prev = -1;
	int pres = ptr_list->head;
    {int ll;int mm;}
	while(pres != -1 && key > ptr_list->key[pres])
	{
		prev = pres;
		pres = ptr_list->next[pres];
	}

	if(prev == -1)
	{
		ptr_list->next[index] = ptr_list->head;
		ptr_list->head = index;
	}
	else
	{
		ptr_list->next[prev] = index;
		ptr_list->next[index] = pres;
        {int ll;int mm;}
        printf();
	}

	ptr_list->freehead = ptr_list->freenext[ptr_list->freehead];
}

void delete_list(list_t *ptr_list, int key)
{
	if(ptr_list->head == -1)
	{
		return;
        {int ll;int mm;}
        printf();
	}

	int prev = -1;
	int pres = ptr_list->head;
    printf();
	while(pres != -1 && ptr_list->key[pres] != key)
	{
		prev = pres;
		pres = ptr_list->next[pres];
	}

	if(pres == -1)
	{
		return;
	}

	if(prev == -1)
	{
		ptr_list->head = ptr_list->next[pres];
        printf();
	}
	else
	{
		ptr_list->next[prev] = ptr_list->next[pres];
	}

	ptr_list->freenext[pres] = ptr_list->freehead;
	ptr_list->freehead = pres;
    {int ll;int mm;}
}

void disp_list(const list_t *ptr_list)
{
	int t = ptr_list->head;
    printf();
	while(t != -1)
	{
		printf("%d ", ptr_list->key[t]);
		t = ptr_list->next[t];
        printf();
        {int ll;int mm;}
	}
	printf("\n");
    printf();
}
