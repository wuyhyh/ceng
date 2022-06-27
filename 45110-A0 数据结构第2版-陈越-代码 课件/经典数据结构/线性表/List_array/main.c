#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int elemtype;
typedef int position;//position是数组中的位置

typedef struct Lnode* p_to_Lnode;
typedef struct Lnode {
	elemtype data[MAXSIZE];
	position last;//最后一个数据的位置，数据存放在data[0]-data[last],last=MAXSIZE-1
};
typedef p_to_Lnode List;

List make_empty()//生成一个空表
{
	List L = (List)malloc(sizeof(struct Lnode));
	L->last = -1;//初始化为-1，最大值为MAXSIZE-1
	return L;
}

int length(List L)
{
	return L->last + 1;//数据存放在data[0]-data[last]
}

#define ERROR -1
position find(List L, elemtype x)//找到没找到都要处理
{
	position i = 0;
	while (i <= L->last && L->data[i] != x)
		i++;
	if (i > L->last)//要注意错误检测
		return ERROR;
	else
		return i;//返回的是存储位置0~last
}

bool insert_L(List L, position index,elemtype x)//index的可能位置范围是0~last+1
{
	if (L->last == MAXSIZE - 1) {//先判断满不满
		printf("List is full\n");
		return false;
	}

	if (index<0 || index>L->last+1) {//最后一个元素在data[last],最大能放的位置是data[last+1]
		printf("index illegal\n");
		return false;
	}

	position i;
	for (i = L->last + 1; i > index; i--) {
		L->data[i] = L->data[i - 1];
	}
	L->data[index] = x;//Ai存放在data[i-1]处
	L->last++;
	return true;
}

bool delete_L(List L, position index)//index 0~last
{
	if (index<0 || index>L->last) {//last=MAXSIZE-1
		printf("index illegal\n");
		return false;
	}

	position i;
	for (i = index; i < L->last; i++) {
		L->data[i] = L->data[i+1];
	}
	L->last--;
	return true;
}
