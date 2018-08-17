#include "ConsBTByAfterAndMid.h"
BTree ConsBTByAfterAndMid(char aft[],int laft,int raft,char mid[],int lmid,int rmid){
	if(laft>raft || lmid>rmid)
		return NULL;
	BTree root = InitBNode();
	root->data = aft[raft];
	int location = -1;
	for (int i = lmid; i <= rmid; ++i)
	{
		if(mid[i]==aft[raft]){
			location = i;
			break;
		}
	}
	root->left = ConsBTByAfterAndMid(aft,laft,laft+location-lmid-1,mid,lmid,location-1);
	root->right = ConsBTByAfterAndMid(aft,laft+location-lmid,raft-1,mid,location+1,rmid);
	return root;

}