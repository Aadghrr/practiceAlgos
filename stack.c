#include<stdio.h>
#include<stdlib.h>
#define N 10
struct stack{
 int top;
 int array[N];
};

struct stack* createStack(){
 struct stack* newStack = malloc(sizeof(struct stack));
 newStack->top = 0;
 return newStack;
}

void push(struct stack* rootStack,int value){
 rootStack->array[rootStack->top]=value;
 rootStack->top+=1;
}
int pop(struct stack* rootStack){
 int value = rootStack->array[rootStack->top-1];
 rootStack->top-=1;
 return value;
}

int main(){
 struct stack* newStack = createStack();
 push(newStack,1);
 push(newStack,2);
 push(newStack,3);
 printf("%d ",pop(newStack));
 printf("%d ",pop(newStack));
 printf("%d ",pop(newStack));
}
