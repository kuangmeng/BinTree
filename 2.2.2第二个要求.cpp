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
//头结点head，始终指向节点前一个节点的pre节点
BiTreTree pre,head;
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
//先序遍历并输出
void InOrder(BiTreTree T) {
	if (T) {
        printf("(");
		printf("%c  ", T->data);
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
        printf(")");
	}
}
void InOrderThread(BiTreTree T) {
	head = (BiTreTree)malloc(sizeof(BiTreNode));
	head->ltag = Thread;
	head->rtag = Link;
	head->lchild =head;
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
int main() {
	BiTreTree T = NULL;
	printf("二叉树的先序线索链表建立：");
	CreateBiTreTree(&T);
	printf("线索链表的存储与先序显示：");
	InOrderThread(T);
	return 0;
}
