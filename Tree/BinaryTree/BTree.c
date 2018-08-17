#include "BTree.h"
BTree InitBNode(){
	BTree tree = (BTree)malloc(sizeof(BNode));
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
BTree CreateBTree(){
	BTree root;
	char ch;
	puts("请输入数据:");
	ch = getchar();
	if(ch=='#') root = NULL;
	else{
		root = (BTree)malloc(sizeof(BNode));
		root->data = ch;
		root->left = CreateBTree();
		root->right = CreateBTree();
	}
	return root;
}


BTree FindNodeInBTree(BTree tree,ElemType data){
	if(tree = NULL)
		return NULL;
	if(tree->data = data)
		return tree;
	BTree *left = FindNodeInBTree(tree->left,data);
	if(left==NULL){
		BTree *right = FindNodeInBTree(tree->right,data);
		return right;
	}else
		return left;
}
BTree LocationLeftChildNode(BTree tree){
	if(tree==NULL)
		return NULL;
	else
		return tree->left;
}
BTree LocationRightChildNode(BTree tree){
	if(tree == NULL)
		return NULL;
	else
		return tree->right;
}
int   BTreeHeight(BTree tree){
	if(tree == NULL)
		return 0;
	int left = BTreeHeight(tree->left);
	int right = BTreeHeight(tree->right);
	left>right?return left+1;:return right+1;
}
void  PrintBTree(BTree tree){
	if(tree == NULL)
		printf("#");
	printf("%c",tree->data);
	PrintBTree(tree->left);
	PrintBTree(tree->right);
}