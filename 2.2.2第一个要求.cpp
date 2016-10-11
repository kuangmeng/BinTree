#include <stdio.h>
#include <stdlib.h>
//建立节点类型
typedef struct BiTreNode {
	char data;
	struct BiTreNode * lchild, *rchild;
}BiTreNode, *BiTreTree;
BiTreTree pre;
//生成二叉树
void CreateBiTreTree(BiTreTree *T) {
	char chr;
	scanf("%c", &chr);
	if ('#' == chr) {
		*T = NULL;
	}
	else {
		*T = (BiTreNode*)malloc(sizeof(BiTreNode));
		(*T)->data = chr;
		//递归方式实现
		CreateBiTreTree(&(*T)->lchild);
		CreateBiTreTree(&(*T)->rchild);
	}
}
//先序排序并输出
void PreOrder(BiTreTree T) {
	if (T != NULL) {
        printf("(");
		printf("%c ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
        printf(")");
	}
}
//中序排序并输出
void MidOrder(BiTreTree T) {
	if (T != NULL) {
        printf("(");
		MidOrder(T->lchild);
		printf("%c ", T->data);
		MidOrder(T->rchild);
        printf(")");
	}
}
//后序排序并输出
void NextOrder(BiTreTree T) {
	if (T != NULL) {
        printf("(");
		NextOrder(T->lchild);
		NextOrder(T->rchild);
		printf("%c ", T->data);
        printf(")");
	}
}
int main() {
    //建立树的开始节点
	BiTreTree T = NULL;
	printf("请按先序顺序输入元素以建立二叉树（无则输\'#\'）:");
	CreateBiTreTree(&T);
	printf(" 先序存储并显示：");
	PreOrder(T);
	printf("\n");
	printf(" 中序存储并显示：");
	MidOrder(T);
	printf("\n");
	printf(" 后序存储并显示：");
	NextOrder(T);
	printf("\n");
	return 0;
}
