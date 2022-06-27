#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int elemtype;
typedef int position;//position�������е�λ��

typedef struct Lnode* p_to_Lnode;
typedef struct Lnode {
	elemtype data[MAXSIZE];
	position last;//���һ�����ݵ�λ�ã����ݴ����data[0]-data[last],last=MAXSIZE-1
};
typedef p_to_Lnode List;

List make_empty()//����һ���ձ�
{
	List L = (List)malloc(sizeof(struct Lnode));
	L->last = -1;//��ʼ��Ϊ-1�����ֵΪMAXSIZE-1
	return L;
}

int length(List L)
{
	return L->last + 1;//���ݴ����data[0]-data[last]
}

#define ERROR -1
position find(List L, elemtype x)//�ҵ�û�ҵ���Ҫ����
{
	position i = 0;
	while (i <= L->last && L->data[i] != x)
		i++;
	if (i > L->last)//Ҫע�������
		return ERROR;
	else
		return i;//���ص��Ǵ洢λ��0~last
}

bool insert_L(List L, position index,elemtype x)//index�Ŀ���λ�÷�Χ��0~last+1
{
	if (L->last == MAXSIZE - 1) {//���ж�������
		printf("List is full\n");
		return false;
	}

	if (index<0 || index>L->last+1) {//���һ��Ԫ����data[last],����ܷŵ�λ����data[last+1]
		printf("index illegal\n");
		return false;
	}

	position i;
	for (i = L->last + 1; i > index; i--) {
		L->data[i] = L->data[i - 1];
	}
	L->data[index] = x;//Ai�����data[i-1]��
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
