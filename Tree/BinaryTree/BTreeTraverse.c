#include "BTreeTraverse.h"

void PreOrderTraverse(BTree tree){
	if(tree == NULL)
		return ;
	printf("%c",tree->data);
	PreOrderTraverse(tree->left);
	PreOrderTraverse(tree->right);
}
void MidOrderTraverse(BTree tree){
	if(tree == NULL)
		return;
	MidOrderTraverse(tree->left);
	printf("%c",tree->data);
	MidOrderTraverse(tree->right);
}
void AftOrderTraverse(BTree tree){
	if(tree == NULL)
		return ;
	AftOrderTraverse(tree->left);
	AftOrderTraverse(tree->right);
	printf("%c",tree->data);
}