#include "HuffmanTree.h"

#define Max 100000
/**
 * [CreateHuffmanTree description]
 * @param tree    [description]
 * @param numbers [description]
 */
void CreateHuffmanTree(HuffmanTree tree[],int numbers){
	int length = 2*numbers - 1;
	//初始化哈弗曼数组
	for(int i = 0; i < numbers; i++){
		tree[i].parent = -1;
		tree[i].right = -1;
		tree[i].left = -1;
	}
	for(int i = numbers;i<length;i++){
		//define the min number of two
		int minOne = Max;
		int minOneLocation = -1;
		int minTwo = Max;
		int minTwoLocation = -1;
		for(int j = 0; j<i;j++){
			if(tree[i].parent == -1){
				if(tree[i].weight <= minOne){
					minTwo = minOne;
					minTwoLocation = minOneLocation;
					minOne = tree[j].weight;
					minOneLocation = j;
				}else if(tree[j].weight <= minTwo && tree[j].weight > minOne){
					minTwoLocation = j;
					minTwo = tree[j].weight;
				}
			}
			HuffmanTree new;
			new.parent = -1;
			new.left = minOneLocation;
			new.right = minTwoLocation;
			tree[minOneLocation].parent = i;
			tree[minTwoLocation].parent = i;
			tree[i] = new;
		}
	}
}