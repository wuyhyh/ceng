#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 100

typedef int elemtype;
typedef int position;//标记的是序列标号

typedef struct Lnode* p_to_Lnode;
typedef struct Lnode {
	elemtype data[MAXSIZE];
	int last;//标记的是内存位置
};

typedef p_to_Lnode List;

List make_empty()
{
	List L = (List)malloc(sizeof(struct Lnode));
	L->last = -1;
	return L;
}

int length(List L)
{
	return L->last + 1;
}

#define ERROR -1
position find(List L, elemtype x)
{
	int i = 0;
	while (i <= L->last && L->data[i] != x)
		i++;
	if (i > L->last)
		return ERROR;
	else
		return i;
}

bool insert_L(List L, position index, elemtype x)
{
	if (L->last == MAXSIZE - 1) {
		printf("full\n");
		return false;
	}

	if (index<1 || index>L->last + 2) {
		printf("index illegal\n");
		return false;
	}

	for (int i = L->last + 1; i >= index; i--) {
		L->data[i] = L->data[i - 1];
	}
	L->data[index - 1] = x;
	L->last++;
	return true;
}

bool delete_L(List L, position index)
{
	if (index<1 || index>L->last + 1) {
		printf("illegal index\n");
		return false;
	}

	for (int i = index - 1; i < L->last; i++) {
		L->data[i] = L->data[i + 1];
	}
	L->last--;
	return true;
}