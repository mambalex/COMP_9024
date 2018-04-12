#include <stdio.h>
#include <stdlib.h>
// The wrong way
// void swap(int a, int b) {
//    int temp = a;
//    a = b;
//    b = temp;
// }
// // only local "copies" of a and b will swap
// int main(void) {
// int a = 5, b = 7;
// swap(a, b);
// printf("a = %d, b = %d\n", a, b); // a and b still have their original values return 0;
// }


// The right way

void swap(int *p, int *q) {
   int temp = *p;
   *p = *q;
   *q = temp;
}
// change the actual values of a and b
int main(void) {
int a = 5, b = 7;
swap(&a, &b);
printf("a = %d, b = %d\n", a, b); // a and b now successfully swapped return 0;
}