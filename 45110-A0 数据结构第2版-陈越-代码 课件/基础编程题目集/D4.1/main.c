#include<stdio.h>
#include<stdlib.h>
//ʹ���ڱ��ķ�����˳�����

#define MAXSIZE 100

typedef int elemtype;
typedef struct Lnode {
	elemtype data[MAXSIZE];
	int last;//���һ��Ԫ�ص�λ��
}*List;

typedef int position;

position sequential_search(List tab, elemtype k)
{
	position i;
	tab->data[0] = k;//�ڱ�
	for (i = tab->last; tab->data[i] != k; i--);//˳�����
	return i;
}

List cearte_l()
{
	List L = (List)malloc(sizeof( struct Lnode));
	L->last = -1;//last��ʼ��-1������ʱ����n-1
	return L;
}

int main()
{
	List list = cearte_l();




}