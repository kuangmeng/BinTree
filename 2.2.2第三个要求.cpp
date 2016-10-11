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
//����ͷ���head��ʼ��ָ��ǰһ�ڵ��pre
BiTreTree pre, head;
//��������������
void CreateBiTreTree(BiTreTree *T) {
	ElemType  chr;
	scanf("%c", &chr);
	if ('#' == chr) {
		*T = NULL;
	}
	else {
		*T = (BiTreNode*)malloc(sizeof(BiTreNode));
		(*T)->data = chr;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		CreateBiTreTree(&(*T)->lchild);
		CreateBiTreTree(&(*T)->rchild);
	}
}
//�������
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
void InOrderThread(BiTreTree T) {
	head = (BiTreTree)malloc(sizeof(BiTreNode));
	head->ltag = Thread;
	head->rtag = Link;
	head->lchild = head;
	if (!T) {
		head->rchild = head;
	}
	else {
		head->rchild = T;
		pre = head;
		InOrder(T);
		pre->rchild = head;
		pre->rtag = Thread;
		head->lchild = pre;
	}
}
//��ǰ�����
void PreNext(BiTreTree T) {
	char letter;
	scanf("%c", &letter);
	pre = head;
	T = head->rchild;
	while (T!=head) {

		if (T->data==letter) {
			printf("    ������Ľڵ��ǰ��Ϊ��");
			pre == head ? printf("NULL\n") : printf("%c\n",pre->data);
			printf("    ������Ľڵ�ĺ��Ϊ��");
			T->ltag == Link ? T = T->lchild : T = T->rchild;
			T == head ? printf("NULL\n") : printf("%c\n", T->data);
			break;
		}
		pre = T;
		T->ltag == Link ? T= T->lchild : T = T->rchild;
	}
}
int main() {
	BiTreTree T = NULL;
	printf("������Ԫ�ؽ���������������������������\'#\'����");
	CreateBiTreTree(&T);
	InOrderThread(T);
	getchar();
	printf("���������ǰ����̵Ľڵ㣨��ȷ�����ڶ������У���");
	PreNext(T);
	return 0;
}
