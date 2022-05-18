#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//初始化链表，用于测试
void InitDLL(DLinkList& DL) {
	DL = (DLinkList)malloc(sizeof(DNode));
	DLinkList s = (DLinkList)malloc(sizeof(DNode));
	DL->prior = NULL;
	DL->next = s;
	s->data = 777;
	s->prior = DL;
	s->next = NULL;
	
}
//双链表头插法建表
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
		if (NULL != DL->next) {//当插入的元素不是第一个元素的情况，等于是插入
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d", &x);
	}
}
//尾部插入法建表（实际上不用关注原来的链表是否已经有元素，有申请空间这一步，默认都是空表）
void Dlist_Tail_Insert(DLinkList &DL) {
	
	ElemType x;
	DL = (DLinkList)malloc(sizeof(DNode));
	DLinkList s;
	DLinkList p = DL;//辅助指针,一定要在为DL分配空间之后，
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

//打印链表
void PrintDList(DLinkList DL) {
	DL= DL->next;//这里不能再指定另一个指针p= DL->next
	while (NULL != DL) { //最后一个元素也是要打印的
		printf("%3d", DL->data);
		DL = DL->next;//
	}
	printf("%\n");
}
//按序号查找元素值,同时也起到定位的作用
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
//删除某位置的元素
bool DListDelete(DLinkList DL, int x) {
	DLinkList p = GetElem(DL, x - 1);
	DLinkList q;//辅助指针，若是最后直接free （p）的话打印会出错
	if (x < 0) {
		return false;
	}
	if (NULL == p || NULL == p->next) {
		return false;
	}
	q = p->next;
	p->next = q->next;//断链
	if (NULL != q->next) {//如果q（要删除的元素）不是最后的元素
		q->next->prior = p;
	}
	free(q);
	return true;
}
//在第i位置插入新的节点
bool DListFrontInsert(DLinkList DL, int x, ElemType e) {
	
	DLinkList p = GetElem(DL, x - 1);
	if (NULL != p) {
		DLinkList s = (DLinkList)malloc(sizeof(DNode));
		s->data = e;
		s->next = p->next;
		if (NULL == p->next) {//如果要插入的前一位就是最后一位
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
	DLinkList DL;//声明了DL，但是DL地址是0xcccccccc
	DLinkList search;
	bool del,ins;
	//InitDLL(DL);
	Dlist_Tail_Insert(DL);
	PrintDList(DL);
	//DList_Head_Insert(DL);
	//PrintDList(DL);
	search = GetElem(DL, 5);
	if (search) {
		printf("该位置的元素为%d%\n",search->data);
	}
	else {
		printf("请输入正确的序号");
	}
	del = DListDelete(DL, 1);
	ins = DListFrontInsert(DL, 1, 99);
	PrintDList(DL);
}