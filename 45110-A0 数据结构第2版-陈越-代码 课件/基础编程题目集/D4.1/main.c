#include<stdio.h>
#include<stdlib.h>
//使用哨兵的方法简化顺序查找

#define MAXSIZE 100

typedef int elemtype;
typedef struct Lnode {
	elemtype data[MAXSIZE];
	int last;//最后一个元素的位置
}*List;

typedef int position;

position sequential_search(List tab, elemtype k)
{
	position i;
	tab->data[0] = k;//哨兵
	for (i = tab->last; tab->data[i] != k; i--);//顺序查找
	return i;
}

List cearte_l()
{
	List L = (List)malloc(sizeof( struct Lnode));
	L->last = -1;//last初始是-1，满的时候是n-1
	return L;
}

int main()
{
	List list = cearte_l();




}