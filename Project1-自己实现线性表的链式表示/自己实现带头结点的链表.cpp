#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode *Next;
}LinkNode,*LinkList;

//ͷ�巨��������
void CreatList1(LinkList& L) {
	LinkList s;
	int x;
	L = (LinkList)malloc(sizeof(LinkNode));
	L->Next = NULL;
	scanf("%d", &x);
	while (9999 != x) {
		s = (LinkList)malloc(sizeof(LinkNode));
		s->data = x;
		s->Next = L->Next;//���ܼ򵥵���ΪNULL����Ϊ��ֹһ��ѭ����ͷ�巨������Ч�����ǵ����
		L->Next = s;
		scanf("%d", &x);
	}
}
//β�巨��������
void CreatList2(LinkList& L) {
	LinkList s;
	int x;
	L = (LinkList)malloc(sizeof(LinkNode));
	L->Next = NULL;
	scanf("%d", &x);
	while (9999 != x) {
		s = (LinkList)calloc(1,sizeof(LinkNode));
		s->data = x;
		s->Next = L->Next;
		L->Next = s;
		scanf("%d", &x);
	}
}
//��ӡ����Ԫ��
void PrintList(LinkList L) {
	L = L->Next;
	while (NULL != L) {
		printf("%3d", L->data);
		L = L->Next;
	}
	printf("\n");
}
//����Ų��ҽڵ�ֵ
LinkList GetElem(LinkList L, int x) {//��ֵ��ѯ��Ҫ���ǵ��Ƿ��±�Խλ�Լ���ѯ�Ƿ�Ϸ�
	if (x == 0) {
		return L;
	}
	if (x < 0) {
		return NULL;
	}
	for (int i = 0; i < x; i++) {
		L = L->Next;
		if (L == NULL) {
			return NULL;
		}
	}
	
	return L;
}
//��ֵ��ѯ
LinkList LocateElem(LinkList L, ElemType e) {
	L = L->Next;
	while (e != L->data) {
		L = L->Next;
		if (NULL == L) {
			return NULL;
		}
	}
	return L;
}
//�½������i��λ��
bool ListFrontInsert(LinkList& L, int x, ElemType e) {
	LinkList p = GetElem(L, x - 1);
	if (NULL == p) {
		return false ;
	}
	LinkList s = (LinkList)malloc(sizeof(LinkNode));
	s->data = e;
	s->Next = p->Next;
	p->Next = s;
	return true;
}
//ɾ����i��Ԫ��
bool ListDelete(LinkList& L, int x) {
	LinkList p = GetElem(L, x - 1);
	if (NULL == p) {
		return false;
	}
	p->Next = p->Next->Next;
	return true;
}

//ɾ����һ��/����Ԫ��ֵ��e��Ԫ��
int main() {
	LinkList L;//����ͷ
	LinkList search;//�����洢�õ���ĳһ���ڵ�
	bool ret;
	//CreatList1(L);//ͷ�巨�����������ݿ���Ϊ3 4 5 6 7 9999
	CreatList2(L);//β�巨�����������ݿ���Ϊ3 4 5 6 7 9999
	PrintList(L);
	search = GetElem(L, 6);
	if (search != NULL)
	{
		printf("����Ų��ҳɹ�\n");
		printf("%d\n", search->data);
	}
	else if (search == NULL) {
		printf("��������ȷ���");
		printf("\n");
	}
	search = LocateElem(L, 6);//��ֵ��ѯ
	if (search != NULL)
	{
		printf("��ֵ���ҳɹ�\n");
		printf("%d\n", search->data);
	}
	else if (NULL == search) {
		printf("��������û������ѯ��Ԫ��");
		printf("\n");
	}
	ret = ListFrontInsert(L, 5, 99);//�½������i��λ��
	if (ret) {
		printf("����ɹ�");
	}
	if (!ret) {
		printf("������ȷ��λ�ò�����ʵ�Ԫ��");
	}
	PrintList(L);
	ret = ListDelete(L, 4);//ɾ����4�����
	if (ret) {
		printf("����ɹ�");
	}
	if (!ret) {
		printf("��ȷ��Ҫɾ����Ԫ�ص�λ��");
	}
	PrintList(L);
}