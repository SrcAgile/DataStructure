#include "fac.h"
int factorial(int num){
	if(num==0||num==1)
		return num;
	return num*factorial(num-1);
}