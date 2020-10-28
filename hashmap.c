#include <stdio.h>
#include <stdlib.h>
struct pair{int key,val;struct pair *next;};
struct table{int size;struct pair **list;};
struct table *createTable(int size){
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct pair**)malloc(sizeof(struct pair*)*size);
    for(int i=0;i<size;i++){t->list[i] = NULL;}
    return t;
}
int hashCode(struct table *t,int key){
    if(key<0){return -(key%t->size);}
    return key%t->size;
}
void insert(struct table *t,int key,int val){
    int pos = hashCode(t,key);
    struct pair *list = t->list[pos];
    struct pair *newPair = (struct pair*)malloc(sizeof(struct pair));
    struct pair *temp = list;
    while(temp){
        if(temp->key==key){
            temp->val=val;
            return;}
        temp=temp->next;
    }
    newPair->key = key;
    newPair->val = val;
    newPair->next = list;
    t->list[pos] = newPair;
}
int lookup(struct table *t,int key){
    int pos = hashCode(t,key);
    struct pair *list = t->list[pos];
    struct pair *temp = list;
    while(temp){
        if(temp->key==key){return temp->val;}
        temp = temp->next;
    }
    return -1;
}
int main(){
    struct table *t = createTable(5);
    insert(t,5,4);
    printf("%d",lookup(t,5));
    return 0;
}
