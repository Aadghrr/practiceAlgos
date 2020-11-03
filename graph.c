#include<stdio.h>
#include<stdlib.h>
#define N 6
struct Graph { struct Node* head[N]; };
struct Node {int dest;
 struct Node* next;
};
struct Vertex { int src,dest;};
struct Graph* createGraph(struct Vertex vertices[],int n);
void printGraph(struct Graph* graph);
int main(void){
 struct Vertex vertices[]=
  {
   {0,1},{1,2},{2,0},{2,1},
   {3,2},{4,5},{5,4}
  };
  int n = sizeof(vertices)/sizeof(vertices[0]);
  return 0;
}
