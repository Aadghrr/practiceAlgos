#include<stdlib.h>
#include<stdio.h>

typedef struct node{
 int value;
 struct node* right;
 struct node* left;
} nd;

nd* createNode(int value){
 nd* node = malloc(sizeof(nd));
 node->value = value;
 node->right=NULL;
 node->left=NULL;
 return node;
}

void insertNode(nd* parentNode, int value){
 if(value<parentNode->value){
  if(parentNode->left == NULL)
   parentNode->left = createNode(value);
  else
   parentNode->right = createNode(value);
 }
}
void printHeap(nd* node){
 if(node->left != NULL){
  if(node->right != NULL)
   printHeap(node->right);
  printHeap(node->left);
 }
 printf("%d ",node->value);
}

int main(){
 nd* root = malloc(sizeof(nd));
 root->value=100;
 insertNode(root,5);
 insertNode(root,10);
 printHeap(root);
 return 0;
}
