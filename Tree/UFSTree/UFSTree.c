#include "UFSTree.h"
void InitUFSTree(UFSTree tree[NUM]){
	for(int i = 0; i<NUM;i++){
		tree[i].data = i;
		tree[i].parent = i;
		tree[i].rank = 0;
	}
}
int FindInUFS(UFSTree tree[NUM],int element){
	int elem = element;
	while(tree[elem].parent != elem)
		elem = tree[elem].parent;
	#ifdef COLLAPSE_PATH
	int colla;
	while(tree[colla].parent != elem){
		colla = tree[colla].parent;
		tree[colla].parent = elem;

	}
	#endif
	return elem;
}
void UnionUFSTree(UFSTree tree[NUM],int one,int two){
	int oneroot = FindInUFS(tree,one);
	int tworoot = FindInUFS(tree,two);
	if(one == two)
		return ;
	if(tree[oneroot].rank > tree[tworoot].rank )
		tree[tworoot].parent = oneroot;
	else if(tree[oneroot].rank < tree[tworoot].rank)
		tree[oneroot].parent = tworoot;
	else{
		tree[oneroot].parent = tworoot;
		tree[tworoot].rank++;
	}
}