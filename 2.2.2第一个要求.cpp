#include <stdio.h>
#include <stdlib.h>
//�����ڵ�����
typedef struct BiTreNode {
	char data;
	struct BiTreNode * lchild, *rchild;
}BiTreNode, *BiTreTree;
BiTreTree pre;
//���ɶ�����
void CreateBiTreTree(BiTreTree *T) {
	char chr;
	scanf("%c", &chr);
	if ('#' == chr) {
		*T = NULL;
	}
	else {
		*T = (BiTreNode*)malloc(sizeof(BiTreNode));
		(*T)->data = chr;
		//�ݹ鷽ʽʵ��
		CreateBiTreTree(&(*T)->lchild);
		CreateBiTreTree(&(*T)->rchild);
	}
}
//�����������
void PreOrder(BiTreTree T) {
	if (T != NULL) {
        printf("(");
		printf("%c ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
        printf(")");
	}
}
//�����������
void MidOrder(BiTreTree T) {
	if (T != NULL) {
        printf("(");
		MidOrder(T->lchild);
		printf("%c ", T->data);
		MidOrder(T->rchild);
        printf(")");
	}
}
//�����������
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
    //�������Ŀ�ʼ�ڵ�
	BiTreTree T = NULL;
	printf("�밴����˳������Ԫ���Խ�����������������\'#\'��:");
	CreateBiTreTree(&T);
	printf(" ����洢����ʾ��");
	PreOrder(T);
	printf("\n");
	printf(" ����洢����ʾ��");
	MidOrder(T);
	printf("\n");
	printf(" ����洢����ʾ��");
	NextOrder(T);
	printf("\n");
	return 0;
}
