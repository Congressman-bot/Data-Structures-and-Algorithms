/*
$ Code written by ALex Mwangi
$ BSE 2.1 
$ Graphs in Data Structures and Algorithms
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{ // Creation of a node or vertex with a pointer
    int vertex;
    struct Node* next;
};

struct Graph{ // Creation of the graph with an adjacency list
    int numVertices;
    struct Node** adjLists;
};

// Initialization of the node for the adjacency list
struct Node* createNode(int v){ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
};

// Create a graph with a given number of vertices
struct Graph* createGraph(int vertices){ 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for(int i = 0; i < vertices; i++){
        graph->adjLists[i] = NULL;
    }
    return graph;
};

// Add edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest){
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add edge form src to dest since it is undirected
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Traversal starts from given vertex
void BFS(struct Graph* graph, int startVertex){
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;
    
    // Mark start vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    printf("BFS Traversal: ");
    while(front < rear){
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        // Explore neighbours
        struct Node* temp = graph->adjLists[currentVertex];
        while(temp){
            int adjVertex = temp->vertex;
            if(!visited[adjVertex]){
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

// DFS utility function for recursive traversal
void DFSUtil(struct Graph* graph, int vertex, int* visited){
    //Mark current vertex as visited
    visited[vertex] = 1;
    printf("%d", vertex);
    
    // Explore neighbours
    struct Node* temp = graph->adjLists[vertex];
    while(temp){
        int adjVertex = temp->vertex;
        if(!visited[adjVertex]){
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// DFS traversal starting from a given vertex
void DFS(struct Graph* graph, int startVertex){
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}


// Feee the graph memory
void freeGraph(struct Graph* graph){
    for(int i = 0; i < graph->numVertices; i++){
        struct Node* temp = graph->adjLists[i];
        while(temp){
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}
int main()
{   // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);
    
    // Age
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    // Perform BFS and DFS starting from vertex 0
    BFS(graph, 0);
    DFS(graph, 0);
    
    //Fee memory
    freeGraph(graph);
    

    return 0;
}