#include "HuffmanCode.h"
void CreateHuffmanCode(HuffmanTree tree[],HuffmanCode code[], int numbers){
	for(int i = 0 ; i<numbers;i++){
		HuffmanCode new;
		new.startIndex = CodeLength;
		int tempIndex = i;
		while(tree[tempIndex].parent != -1){
			HuffmanTree parent = tree[tree[tempIndex].parent];
			if(parent.left == tempIndex)
				new.code[--new.startIndex] = '0';
			else if(parent.right == tempIndex)
				new.code[--new.startIndex] = '1';
			tempIndex = tree[tempIndex].parent;
		}
		code[i] = new;	
	}
}