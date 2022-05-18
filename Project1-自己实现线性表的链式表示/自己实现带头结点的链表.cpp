#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode *Next;
}LinkNode,*LinkList;

//头插法建立链表
void CreatList1(LinkList& L) {
	LinkList s;
	int x;
	L = (LinkList)malloc(sizeof(LinkNode));
	L->Next = NULL;
	scanf("%d", &x);
	while (9999 != x) {
		s = (LinkList)malloc(sizeof(LinkNode));
		s->data = x;
		s->Next = L->Next;//不能简单得设为NULL，因为不止一次循环，头插法建表在效果上是倒序的
		L->Next = s;
		scanf("%d", &x);
	}
}
//尾插法建立链表
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
//打印链表元素
void PrintList(LinkList L) {
	L = L->Next;
	while (NULL != L) {
		printf("%3d", L->data);
		L = L->Next;
	}
	printf("\n");
}
//按序号查找节点值
LinkList GetElem(LinkList L, int x) {//按值查询需要考虑到是否下表越位以及查询是否合法
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
//按值查询
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
//新结点插入第i个位置
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
//删除第i个元素
bool ListDelete(LinkList& L, int x) {
	LinkList p = GetElem(L, x - 1);
	if (NULL == p) {
		return false;
	}
	p->Next = p->Next->Next;
	return true;
}

//删除第一个/所有元素值是e的元素
int main() {
	LinkList L;//链表头
	LinkList search;//用来存储拿到的某一个节点
	bool ret;
	//CreatList1(L);//头插法建表输入数据可以为3 4 5 6 7 9999
	CreatList2(L);//尾插法建表输入数据可以为3 4 5 6 7 9999
	PrintList(L);
	search = GetElem(L, 6);
	if (search != NULL)
	{
		printf("按序号查找成功\n");
		printf("%d\n", search->data);
	}
	else if (search == NULL) {
		printf("请输入正确序号");
		printf("\n");
	}
	search = LocateElem(L, 6);//按值查询
	if (search != NULL)
	{
		printf("按值查找成功\n");
		printf("%d\n", search->data);
	}
	else if (NULL == search) {
		printf("该链表内没有所查询的元素");
		printf("\n");
	}
	ret = ListFrontInsert(L, 5, 99);//新结点插入第i个位置
	if (ret) {
		printf("插入成功");
	}
	if (!ret) {
		printf("请在正确的位置插入合适的元素");
	}
	PrintList(L);
	ret = ListDelete(L, 4);//删除第4个结点
	if (ret) {
		printf("插入成功");
	}
	if (!ret) {
		printf("请确认要删除的元素的位置");
	}
	PrintList(L);
}