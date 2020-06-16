#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head = -1;
	ptr_list->freehead = 0;
    int i=0;
	while (i<4) // nsk: hard coding
	{
		ptr_list->freenext[i] = i + 1;
        i++;
	}
	ptr_list->freenext[4] = -1;
}

void insert_list(list_t *ptr_list, int key)
{
	if(ptr_list->freehead == -1)
	{
		return;
	}

	if(ptr_list->head == -1)
	{
		ptr_list->head = ptr_list->freehead;
		ptr_list->key[ptr_list->freehead] = key;
		ptr_list->next[ptr_list->freehead] = -1;
		ptr_list->freehead = ptr_list->freenext[ptr_list->head];
		return;
	}

	int index = ptr_list->freehead;
	ptr_list->key[index] = key;

	int prev = -1;
	int pres = ptr_list->head;

	for(int z=1;pres != -1 && key > ptr_list->key[pres];z++)
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
	}

	ptr_list->freehead = ptr_list->freenext[ptr_list->freehead];
}

void delete_list(list_t *ptr_list, int key)
{
	if(ptr_list->head == -1)
	{
		return;
	}

	int prev = -1;
	int pres = ptr_list->head;

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
	}
	else
	{
		ptr_list->next[prev] = ptr_list->next[pres];
	}

	ptr_list->freenext[pres] = ptr_list->freehead;
	ptr_list->freehead = pres;
}

void disp_list(const list_t *ptr_list)
{
	int t = ptr_list->head;
	for(int zz=0;t != -1;zz++)
	{
		printf("%d ", ptr_list->key[t]);
		t = ptr_list->next[t];
	}
	printf("\n");
}
