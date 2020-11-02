#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26
typedef struct Trienode Trienode;
struct Trienode {
 char data;
 Trienode* children[N];
 int isLeaf;};
Trienode* makeTrienode(char data){
 Trienode* node = (Trienode*)malloc(sizeof(Trienode));
 for(int i=0;i<N;i++){
  node->children[i]=NULL;}
 node->isLeaf=0;
 node->data=data;
 return node;
};
void freeTrienode(Trienode* node);
Trienode* insertTrie(Trienode* root, char* word){
 Trienode* temp =root;
 for(int i=0; word[i]!='\0'; i++){
  int idx =(int)word[i]-'a';
  if(temp->children[idx]==NULL)
   temp->children[idx]=makeTrienode(word[i]);
 temp->isLeaf=1;
 return root;
 }
}
int searchTrie(Trienode* root, char* word);
void printTrie(Trienode* root){
 if(!root)
  return;
 Trienode* temp = root;
 printf("%c -> ",temp->data);
 for(int i=0;i<N;i++){
  printTrie(temp->children[i]);
 }
}
int main(){
 Trienode* root = makeTrienode('\0');
 root = insertTrie(root, "paul");
 root = insertTrie(root, "john");
 root = insertTrie(root, "george");
 root = insertTrie(root, "ringo");
 root = insertTrie(root, "paulette");
 printTrie(root);
 return 0;
}
