#include <stdio.h>
#include <stdlib.h>
struct node {
int value; 
struct node *next;
};
struct node *createNode(struct node *head,int val){
struct node *res;
res->value = val;
res->next = (struct node*)malloc(sizeof(struct node));
return res->next;
}
int main() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->value=5;
    struct node *temp = head;
    struct node *node1 = createNode(head,10);
    struct node *node2 = createNode(node1,20);
    while(temp->next){
        temp=temp->next;
        printf("%d",temp->value);}
    return 0;
}
