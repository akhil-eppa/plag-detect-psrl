#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *p_list)
{
	p_list->hd = -1;
	p_list->fhd = 0;
	for(int i = 0; i < 4; i++) // nsk: hard coding
	{
		p_list->freenext[i] = i + 1;
	}
	p_list->freenext[4] = -1;
}

void insert_list(list_t *p_list, int key)
{
	if(p_list->fhd == -1)
	{
		return;
	}

	if(p_list->hd == -1)
	{
		p_list->hd = p_list->fhd;
		p_list->key[p_list->fhd] = key;
		p_list->next[p_list->fhd] = -1;
		p_list->fhd = p_list->freenext[p_list->hd];
		return;
	}

	int index = p_list->fhd;
	p_list->key[index] = key;

	int previous = -1;
	int pres = p_list->hd;

	while(pres != -1 && key > p_list->key[pres])
	{
		previous = pres;
		pres = p_list->next[pres];
	}

	if(previous == -1)
	{
		p_list->next[index] = p_list->hd;
		p_list->hd = index;
	}
	else
	{
		p_list->next[previous] = index;
		p_list->next[index] = pres;
	}

	p_list->fhd = p_list->freenext[p_list->fhd];
}

void delete_list(list_t *p_list, int key)
{
	if(p_list->hd == -1)
	{
		return;
	}

	int previous = -1;
	int pres = p_list->hd;

	while(pres != -1 && p_list->key[pres] != key)
	{
		previous = pres;
		pres = p_list->next[pres];
	}

	if(pres == -1)
	{
		return;
	}

	if(previous == -1)
	{
		p_list->hd = p_list->next[pres];
	}
	else
	{
		p_list->next[previous] = p_list->next[pres];
	}

	p_list->freenext[pres] = p_list->fhd;
	p_list->fhd = pres;
}

void disp_list(const list_t *p_list)
{
	int t = p_list->hd;
	while(t != -1)
	{
		printf("%d ", p_list->key[t]);
		t = p_list->next[t];
	}
	printf("\n");
}
