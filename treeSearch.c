#include <stdlib.h>
#include<stdio.h>
#define SIZE 20

struct queue {
 int items[SIZE];
 int front;
 int rear;
};

struct node {
 int vertex;
 struct node* next;
};

struct graph {
 int numVertices;
 struct node** adjacencyList;
 int* visited;
};

struct graph* createGraph(int vertices){
 struct graph* newGraph = malloc(sizeof(struct graph));
 newGraph->numVertices = vertices;
 newGraph->adjacencyList = malloc(vertices * sizeof(struct node*));
 newGraph->visited = malloc(vertices * sizeof(int));
 for(int i =0;i<vertices;i++){
  newGraph->adjancencyList[i] = NULL;
  newGraph->visited[i] = 0;
 }
 return newGraph;
}
