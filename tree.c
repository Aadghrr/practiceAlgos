#include<stdlib.h>
#include<stdio.h>
struct node {
 int item;
 struct node* left;
 struct node* right;
};

void traverseInOrder(struct node* root){
 if (root == NULL) return;
 traverseInOrder(root->left);
 printf("%d ->", root->item);
 traverseInOrder(root->right);
}

struct node* createNode(int value) {
 struct node* newNode = malloc(sizeof(struct node));
 newNode->item = value;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}

struct node* insertLeft(struct node* root,int value){
 root->left = createNode(value);
 return root->left;
}

struct node* insertRight(struct node* root,int value){
 root->right = createNode(value);
 return root->right;
}

int main(){
 struct node* root = createNode(10);
 struct node* left1 = insertLeft(root,15);
 struct node* right1 = insertRight(root,20);
 struct node* left11 = insertLeft(left1,25);
 traverseInOrder(root);
 return 0;
}
