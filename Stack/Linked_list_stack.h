#include <stdlib.h>
#include <assert.h>


typedef struct node {
   int data;
   struct node *next;
} NodeT;

typedef struct StackRep {
int height; // #elements on stack NodeT *top; // ptr to first element
} StackRep;

// set up empty stack
stack newStack() {
   stack S = malloc(sizeof(StackRep));
   S->height = 0;
   S->top = NULL;
   return S;
}

// remove unwanted stack
void dropStack(stack S) {
NodeT *curr = S->top;
while (curr != NULL) { // free the list
      NodeT *temp = curr->next;
      free(curr);
      curr = temp;
}
free(S); // free the stack rep 
}

// check whether stack is empty
int StackIsEmpty(stack S) {
   return (S->height == 0);
}

// insert an int on top of stack
void StackPush(stack S, int v) { 
NodeT *new = malloc(sizeof(NodeT)); 
assert(new != NULL);
new->data = v;
// insert new element at top
new->next = S->top;
S->top = new;
S->height++;
}

// remove int from top of stack
int StackPop(stack S) { 
assert(S->height > 0);
NodeT *head = S->top;
// second list element becomes new top S->top = S->top->next; S->height--;
   // read data off first element, then free
   int d = head->data;
   free(head);
   return d;
}