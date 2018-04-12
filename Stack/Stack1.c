#include <stdio.h>
#include "Stack.h"
#include <assert.h>



int main(){
	int i,j,num;
	printf("Enter a positive number: ");
	scanf("%d",&num );
	if(num>0){
	StackInit();
	for(i=1; i <= num; i++){
		 printf("Enter a number: ");
		 int in;
		 scanf("%d",&in);
		 StackPush(in);
	 
	}
	while(!StackIsEmpty()){
		int out;
		out = StackPop();
		printf("%d\n", out);
	
	}
	}

	return 0;

}





