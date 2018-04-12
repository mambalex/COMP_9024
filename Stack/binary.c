#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int n;
   printf("%d %s \n",argc,argv[1]);
   if (argc != 2) {
      printf("Usage: %s number\n", argv[0]);
      return 1;
   }

   StackInit();
   n = atoi(argv[1]);
   while (n > 0) {
      StackPush(n % 2);
      n = n / 2;
   }
   while (!StackIsEmpty()) {
      printf("%d", StackPop());
   }
   putchar('\n');
   return 0;
}
