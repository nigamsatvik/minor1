/*Program to represent A* Algorithm */

#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent an adjacency list node 
struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList 
{ 
    struct AdjListNode *head;  
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists.
// Size of array will be V (number of vertices  
// in graph) 
struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
		 
struct AdjListNode* newAdjListNode(int dest) 			//create a Adjacency List NOde 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
  
					 
struct Graph* createGraph(int V) 		//Create a GRaph of given Vertex V
{ 
    struct Graph* graph =  
        (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    // Create an array of adjacency lists.  Size of  
    // array will be V 
    graph->array =  
      (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    // Initialize each adjacency list as empty by making NULL 
    
    int i; 
    for (i = 1; i <=V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest) 
{ 
							    // Add an edge from src to dest.  A new node is  
							    // added to the adjacency list of src.  The node 
							    // is added at the begining 
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    					// Since graph is undirected, add an edge from dest to src also 
    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 
  
 
void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 1; v <=graph->V; ++v) 
    { 
        struct AdjListNode* p = graph->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (p) 
        { 
            printf("-> %d", p->dest); 
            p = p->next; 
        } 
        printf("\n"); 
    } 
} 
int main() 
{ 
    int V = 10; 
    struct Graph* graph = createGraph(V); 
   
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3); 
    addEdge(graph, 2, 4); 
    addEdge(graph, 2, 5); 
    addEdge(graph, 3, 6); 
    addEdge(graph, 3, 7); 
    addEdge(graph, 4, 8); 
    addEdge(graph, 4, 5); 
    addEdge(graph, 5, 8); 
    addEdge(graph, 6, 9); 
    addEdge(graph, 7, 9);
    addEdge(graph, 8, 9);  
    addEdge(graph, 8, 10); 
    addEdge(graph, 9, 10); 
				//printGraph function will print the adjacency list of Graph    
    printGraph(graph); 
  
    return 0; 
} 


//Execute it with GCC compiler.




