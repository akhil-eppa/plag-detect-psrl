#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head = -1;
	ptr_list->freehead = 0;
	for(int i = 0; i < 4; i++) // we hard code the number
	{
		ptr_list->freenext[i] = i + 1;//initializing free next
	}
	ptr_list->freenext[4] = -1;//putting end of freenext
}

void insert_list(list_t *ptr_list, int key)//we insert into the list
{
	if(ptr_list->freehead == -1)//1st free location
	{
		return;
	}

	if(ptr_list->head == -1)//checking the head
	{
		ptr_list->head = ptr_list->freehead;//free head is put to location of head
		ptr_list->key[ptr_list->freehead] = key;
		ptr_list->next[ptr_list->freehead] = -1;
		ptr_list->freehead = ptr_list->freenext[ptr_list->head];//moving the nodes/values
		return;
	}

	int index = ptr_list->freehead;
	ptr_list->key[index] = key;//after the iindex is found. put the key in that place

	int prev = -1;
	int pres = ptr_list->head;//the pres points to

	while(pres != -1 && key > ptr_list->key[pres])//checking some conditions as required
	{
		prev = pres;
		pres = ptr_list->next[pres];
	}

	if(prev == -1)//if inserting at first position
	{
		ptr_list->next[index] = ptr_list->head;
		ptr_list->head = index;
	}
	else//if not
	{
		ptr_list->next[prev] = index;
		ptr_list->next[index] = pres;
	}

	ptr_list->freehead = ptr_list->freenext[ptr_list->freehead];
}

void delete_list(list_t *ptr_list, int key)//delete an element from the list
{
	if(ptr_list->head == -1)//if list empty just return
	{
		return;
	}

	int prev = -1;//initialzing
	int pres = ptr_list->head;//pres is the head

	while(pres != -1 && ptr_list->key[pres] != key)//checking some conditions
	{
		prev = pres;
		pres = ptr_list->next[pres];
	}

	if(pres == -1)//if not found
	{
		return;
	}

	if(prev == -1)//if first position insertion
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

void disp_list(const list_t *ptr_list)//We use this to display the contents of the list
{
	int t = ptr_list->head;
	while(t != -1)//till we reach the end of the list
	{
		printf("%d ", ptr_list->key[t]);
		t = ptr_list->next[t];
	}
	printf("\n");
}
