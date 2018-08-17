#include "ConsBTByPreAndMid.h"

BTree ConsBTByPreAndMid(char pre[],int lpre,int rpre,char mid[],int lmid,int rmid){
	BTree root = InitBNode();
	if(lpre>rpre||lmid>rmid)
		return NULL;

	root->data = pre[lpre];
	
	int location = -1;
	for(int i = lmid;i<=rmid;i++){
		if(mid[i]==pre[lpre]){
			location = i;
			break;
		}
	}
	root->left = ConsBTByPreAndMid(pre,lpre+1,lpre+location-lmid,mid,lmid,location-1);
	root->right = ConsBTByPreAndMid(pre,lpre+location-lmid,rpre,mid,location+1,rmid);

	return root;
}