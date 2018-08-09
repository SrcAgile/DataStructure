#include "joseph.h"
/**
 * param numbers         初始循环链人数
 * param outnumber       隔多少杀一人
 */
void josephProblem(int numbers,int outnumber){
	int data[numbers];
	//Initiate the array
	for(int i = 0;i<numbers;i++)
		data[i]=i+1;
	int start = 0;
	for(int i = 0;i<numbers;i++){
		int out = (start+outnumber-1)%(numbers-i);
		printf("delete %d\n", data[out]);
		start = out;
		for(int j = out+1;j<=numbers-i-1;j++)
			data[j-1] = data[j];//平移
	}
	puts("");
}