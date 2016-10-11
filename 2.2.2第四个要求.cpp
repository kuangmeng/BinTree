#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef enum { Link, Thread } PointerTag;
//����ڵ�����
typedef struct BiTreNode {
	ElemType  data;
	struct BiTreNode * lchild, *rchild;
	PointerTag ltag, rtag;
}BiTreNode, *BiTreTree;
//����ͷ���head��ʼ���ڽڵ�ǰһ����pre�ڵ�
BiTreTree pre, head;
//��������������
void CreateBiTreTree(BiTreTree *T) {
	ElemType  chr;
	scanf("%c", &chr);
	if ('#' == chr) *T = NULL;
	else {
		*T = (BiTreNode*)malloc(sizeof(BiTreNode));
		(*T)->data = chr;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		//�ݹ�������������
		CreateBiTreTree(&(*T)->lchild);
		CreateBiTreTree(&(*T)->rchild);
	}
}
//������������
void InOrder(BiTreTree T) {
	if (T) {
		if (!T->lchild) {
			T->ltag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild) {
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;
		if (T->ltag == Link) InOrder(T->lchild);
		if (T->rtag == Link) InOrder(T->rchild);
	}
}
//����������
void InOrderThread(BiTreTree T) {
	head = (BiTreTree)malloc(sizeof(BiTreNode));
	head->ltag = Thread;
	head->rtag = Link;
	head->lchild = head;
	if (!T) head->rchild = head;
	else {
		head->rchild = T;
		pre = head;
		InOrder(T);
		pre->rchild = head;
		pre->rtag = Thread;
		head->lchild = pre;
	}
}
//�ǵݹ鷽ʽ�������������
void Print() {
	BiTreTree p;
	p = head->rchild;
	while (p!=head) {
		printf("%c ",p->data);
		p=p->ltag==Link?p->lchild:p->rchild;
	}
}
int main() {
	BiTreTree T = NULL;
	printf("������������������������");
	CreateBiTreTree(&T);
	InOrderThread(T);
	printf("��������Ĵ洢��������ʾ(�ǵݹ�)��");
	Print();
	return 0;
}
