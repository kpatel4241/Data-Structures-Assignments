#include<stdio.h>
#include<stdlib.h>
 
// Creating the node for inserting the vertex data.
struct Node
{
    int vertex_data;
    struct Node* next;
};

// Function to create node.
struct Node* create_node(int v_data)
{
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->vertex_data = v_data;
    new_node->next = NULL;
    return new_node;
}

// Structure for Graph Creation.
struct Graph
{
    int num_vertices;
    int* visited;
    struct Node **adj_lists;
};

// Function to create graph.
struct Graph* create_graph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    
    graph->num_vertices = vertices;

    graph->adj_lists = malloc(vertices * sizeof(struct Node*));
    
    graph->visited = malloc(vertices * sizeof(int));
 
    int i;
    for (i = 0; i < vertices; i++) 
    {
        graph->adj_lists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}


// Function to create edge between two vertices.
void add_edge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest.
    struct Node* new_node = create_node(dest);
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
 
    // Add edge from dest to src.
    new_node = create_node(src);
    new_node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = new_node;
}
 
// DFS Alogorithm.
void DFS(struct Graph* graph, int vertex_data) 
{
        struct Node* adjList = graph->adj_lists[vertex_data];
        struct Node* temp = adjList;
        
        graph->visited[vertex_data] = 1;
        printf("\nVisited : %d ", vertex_data);
    
        while(temp!=NULL) 
        {
            int connectedvertex_data = temp->vertex_data;
        
            if(graph->visited[connectedvertex_data] == 0) 
            {
                DFS(graph, connectedvertex_data);
            }
            temp = temp->next;
        }
}

// Function to print Graph.
void printGraph(struct Graph* graph)
{
    int i;
    for (i = 0; i < graph->num_vertices; i++)
    {
        struct Node* temp = graph->adj_lists[i];
        printf("\n Adjacency list of vertex_data : %d\n ", i);
        while (temp)
        {
            printf("%d ", temp->vertex_data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main()
{

    struct Graph* graph = create_graph(6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    
    printGraph(graph);

    DFS(graph, 0);
    
    return 0;
}
