#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//��ʼ���������ڲ���
void InitDLL(DLinkList& DL) {
	DL = (DLinkList)malloc(sizeof(DNode));
	DLinkList s = (DLinkList)malloc(sizeof(DNode));
	DL->prior = NULL;
	DL->next = s;
	s->data = 777;
	s->prior = DL;
	s->next = NULL;
	
}
//˫����ͷ�巨����
void DList_Head_Insert(DLinkList& DL) {
	DLinkList s;
	DL = (DLinkList)malloc(sizeof(DNode));
	ElemType x;
	DL->prior= NULL;
	DL->next = NULL;
	scanf("%d", &x);
	while (9999 != x) {
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = x;
		s->next = DL->next;
		if (NULL != DL->next) {//�������Ԫ�ز��ǵ�һ��Ԫ�ص�����������ǲ���
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d", &x);
	}
}
//β�����뷨����ʵ���ϲ��ù�עԭ���������Ƿ��Ѿ���Ԫ�أ�������ռ���һ����Ĭ�϶��ǿձ�
void Dlist_Tail_Insert(DLinkList &DL) {
	
	ElemType x;
	DL = (DLinkList)malloc(sizeof(DNode));
	DLinkList s;
	DLinkList p = DL;//����ָ��,һ��Ҫ��ΪDL����ռ�֮��
	DL->prior = NULL;
	scanf("%d", &x);
	while (9999 != x) {
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = x;
		p->next = s;
		s->prior = p;
		p = s;
		scanf("%d", &x);
	}
	p->next = NULL;
}

//��ӡ����
void PrintDList(DLinkList DL) {
	DL= DL->next;//���ﲻ����ָ����һ��ָ��p= DL->next
	while (NULL != DL) { //���һ��Ԫ��Ҳ��Ҫ��ӡ��
		printf("%3d", DL->data);
		DL = DL->next;//
	}
	printf("%\n");
}
//����Ų���Ԫ��ֵ,ͬʱҲ�𵽶�λ������
DLinkList GetElem(DLinkList DL, int x) {
	DLinkList P = DL->next;
	int i =1;
	if (x == 0) {
		return DL;
	}
	if (x < 1)
		return NULL;
	while (P && i < x) {
		P = P->next;
		i++;
	}
	return P;
}
//ɾ��ĳλ�õ�Ԫ��
bool DListDelete(DLinkList DL, int x) {
	DLinkList p = GetElem(DL, x - 1);
	DLinkList q;//����ָ�룬�������ֱ��free ��p���Ļ���ӡ�����
	if (x < 0) {
		return false;
	}
	if (NULL == p || NULL == p->next) {
		return false;
	}
	q = p->next;
	p->next = q->next;//����
	if (NULL != q->next) {//���q��Ҫɾ����Ԫ�أ���������Ԫ��
		q->next->prior = p;
	}
	free(q);
	return true;
}
//�ڵ�iλ�ò����µĽڵ�
bool DListFrontInsert(DLinkList DL, int x, ElemType e) {
	
	DLinkList p = GetElem(DL, x - 1);
	if (NULL != p) {
		DLinkList s = (DLinkList)malloc(sizeof(DNode));
		s->data = e;
		s->next = p->next;
		if (NULL == p->next) {//���Ҫ�����ǰһλ�������һλ
			s->prior = p;
			p->next = s;
		}
		p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
	return false;
}
int main() {
	DLinkList DL;//������DL������DL��ַ��0xcccccccc
	DLinkList search;
	bool del,ins;
	//InitDLL(DL);
	Dlist_Tail_Insert(DL);
	PrintDList(DL);
	//DList_Head_Insert(DL);
	//PrintDList(DL);
	search = GetElem(DL, 5);
	if (search) {
		printf("��λ�õ�Ԫ��Ϊ%d%\n",search->data);
	}
	else {
		printf("��������ȷ�����");
	}
	del = DListDelete(DL, 1);
	ins = DListFrontInsert(DL, 1, 99);
	PrintDList(DL);
}