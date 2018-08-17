#include "ThreadedBTreeTraverse.h"

void MidOrderTraverseTBTree(ThreadedBTree tree){
	ThreadedBTree VisitTree = tree->left;
	while(VisitTree != tree){
		while(VisitTree->left_flag ==0)
			VisitTree = VisitTree->left;
		printf("%c",VisitTree->data);
		while(VisitTree->right_flag == 1 && VisitTree-> right != tree){
			printf("%c",VisitTree->right->data);
			VisitTree = VisitTree->right;
		}
		VisitTree = VisitTree->right;
	}
}