 #include "destoryLinkNode.h"
void destoryLinkNodeWithoutHead(LinkList *list){
	if(list==NULL)
		return;
	LinkList *next = list->next;
	free(list);
	destoryLinkNodeWithoutHead(next);
}