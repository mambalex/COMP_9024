#include <stdio.h>
#include "Stack.h"
#include <assert.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
   int i;

   StackInit();
   for (i = 1; i < argc; i++) {
      StackPush(atoi(argv[i]));
   }
   while (!StackIsEmpty()) {
      printf("%d\n", StackPop());
   }
   return 0;
}





