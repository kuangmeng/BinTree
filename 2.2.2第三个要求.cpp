#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef enum { Link, Thread } PointerTag;
//定义节点类型
typedef struct BiTreNode {
	ElemType  data;
	struct BiTreNode * lchild, *rchild;
	PointerTag ltag, rtag;
}BiTreNode, *BiTreTree;
//定义头结点head，始终指向前一节点的pre
BiTreTree pre, head;
//生成线索二叉树
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
//先序遍历
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
//求前驱后继
void PreNext(BiTreTree T) {
	char letter;
	scanf("%c", &letter);
	pre = head;
	T = head->rchild;
	while (T!=head) {

		if (T->data==letter) {
			printf("    所输入的节点的前驱为：");
			pre == head ? printf("NULL\n") : printf("%c\n",pre->data);
			printf("    所输入的节点的后继为：");
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
	printf("请输入元素建立二叉树先序线索链表（无则输\'#\'）：");
	CreateBiTreTree(&T);
	InOrderThread(T);
	getchar();
	printf("请输入待求前驱后继的节点（请确保其在二叉树中）：");
	PreNext(T);
	return 0;
}
