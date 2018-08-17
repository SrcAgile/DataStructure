#include "ThreadedBTree.h"

ThreadedBTree PreTBNode;

ThreadedBTree CreateThreadedBTreeBase(BTree tree);
void CreateThreadedBTreeByBTreeByRec(ThreadedBTree tree);

ThreadedBTree InitThreadedBTree(void){
	ThreadedBTree tbree = (ThreadedBTree)malloc(sizeof(TBNode));
	tbree.left_flag = 1;
	tbree.right_flag = 1;
	tbree.left = tree;
	tbree.right = tree;
	return tree;
}
ThreadedBTree CreateThreadedBTreeByBTree(BTree tree){
	ThreadedBTree root = InitThreadedBTree();
	if(!tree) return root;
	ThreadedBTree btreeBase = CreateThreadedBTreeBase(tree);
	PreTBNode = root;
	root->right = NULL;
	root->left_flag = 0;
	CreateThreadedBTreeByBTreeByRec(btreeBase);
	root->left = btreeBase;
	PreTBNode->right_flag = 1;
	PreTBNode->right = root;
	root->left = PreTBNode;
	root->left_flag = 1;
	return root;
}
ThreadedBTree CreateThreadedBTreeBase(BTree tree){
	if(tree == NULL) return NULL;
	ThreadedBTree new = InitThreadedBTree();
	new->data = tree->data;
	new->left = CreateThreadedBTreeBase(tree->left);
	new->right = CreateThreadedBTreeBase(tree->right);
	return new;
}
void CreateThreadedBTreeByBTreeByRec(ThreadedBTree tree){
	if(tree == NULL)
		return;
	CreateThreadedBTreeByBTreeByRec(tree->left);
	//如果当前结点的左分支为空,将当前结点的左分支的前驱结点置为当前结点
	//否则不作为
	if(tree->left == NULL){
		tree->left_flag = 1;
		tree->left = PreTBNode;
	}else	tree->left_flag = 0;
	if(PreTBNode->right == NULL){
		PreTBNode->right_flag = 1;
		PreTBNode->right = tree;
	}else PreTBNode->right_flag = 0;
	PreTBNode = tree;
	CreateThreadedBTreeByBTreeByRec(tree->right);
}