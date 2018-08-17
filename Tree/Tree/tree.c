#include "tree.h"

int treeHeight(CSTree tree){
	if(tree == NULL)
		return 0;
	int max = 0;
	CSTree sib = tree;
	while(sib != NULL){
		rheight = treeHeight(sib->rightSib);
		if(max < rheight)
			max = rheight;
		sib = sib->rightSib;
	}
	return max+1;
}