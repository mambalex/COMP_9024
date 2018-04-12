//
// Created by Alex Zhang on 1/10/17.
//

#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphRep {
    int  **edges;   // adjacency matrix
    int    nV;      // #vertices
    int    nE;      // #edges
} GraphRep;

Graph newGraph(int V) {
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int *));
    assert(g->edges != NULL);
    // allocate memory for each column and initialise with 0
    for (i = 0; i < V; i++) {
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);
    }

    return g;
}

// check if vertex is valid in a graph
bool validV(Graph g, Vertex v) {
    return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g,e.v) && validV(g,e.w));

    if (!g->edges[e.v][e.w]) {  // edge e not in graph
        g->edges[e.v][e.w] = 1;
        g->edges[e.w][e.v] = 1;
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g,e.v) && validV(g,e.w));

    if (g->edges[e.v][e.w]) {   // edge e in graph
        g->edges[e.v][e.w] = 0;
        g->edges[e.w][e.v] = 0;
        g->nE--;
    }
}

bool adjacent(Graph g, Vertex v, Vertex w) {
    assert(g != NULL && validV(g,v) && validV(g,w));

    return (g->edges[v][w] != 0);
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
        for (j = i+1; j < g->nV; j++)
            if (g->edges[i][j])
                printf("Edge %d - %d\n", i, j);
}

void show(Graph g, int row, int col, char list[row][col]) {
    assert(g != NULL);
    int i, j;
    for (i = 0; i < g->nV; i++){
        printf("\n");
        printf("%s: ",list[i]);
        for (j = i+1; j < g->nV; j++) {
            if (g->edges[i][j])
                printf("%s ",list[j]);}
    }
}

void freeGraph(Graph g) {
    assert(g != NULL);

    int i;
    for (i = 0; i < g->nV; i++)
        free(g->edges[i]);
    free(g->edges);
    free(g);
}

void print_path(int n, int l[n],int row, int col, char list[row][col]){
    int loop;
    for (loop = n; loop >= 0; loop--){
        if(loop == 0){
            printf("%s\n",list[l[loop]]);
        } else{
            printf("%s -> ",list[l[loop]]);
        }
    }
}

void FindLongestPath(Graph g, int n, int col, char list[n][col]){
    int distance[n],pred[n];
    int visited[n],seq,i;
    int max_dist = 0;

    //initialize pred[],distance[]
    for(i=0;i<n;i++)
    {
        distance[i]= 0;
        pred[i]=0;
        visited[i]=0;
    }

    distance[0]=0;
    seq=0;

     for(i=0;i<n;i++){
        printf("%d:%d  ",distance[i],pred[i]);
        if (i==n-1)
        {printf("\n");}
    }

    while(seq<n-1)
    {
        for(i=seq+1;i<n;i++){
            if (g->edges[seq][i]== 1 && distance[seq]+1 > distance[i]) {
                distance[i] = distance[seq] + 1;
                pred[i] = seq;
            }
	    for(i=0;i<n;i++){
            printf("%d:%d  ",distance[i],pred[i]);
            if (i==n-1)
            {printf("\n");}
        }
        seq+=1;
    }
    for(i=0;i<n;i++){
        if (max_dist < distance[i]){
            max_dist = distance[i];}
//        printf("%d  ",distance[i]);
    }
//    printf("\n");
//    for(i=0;i<n;i++){
//        printf("%d  ",pred[i]);
//    }
//    printf("\n");
    printf("Maximum chain length: %d\n",max_dist+1);
    printf("Maximal chains:\n");

    int temp = 0;
    int p;
    for(i=0;i<n;i++){
        if (distance[i] == max_dist){
            int *path = malloc((max_dist+1)*sizeof(int));
            temp = 0;
            path[temp] = i;
            p = pred[i];
            while (p!=0){
                temp += 1;
                path[temp] = p;
                p = pred[p];
            }
            path[temp+1] = p;
//            printf("path: %d  %d  %d\n",path[0],path[1],path[2]);
            print_path(max_dist,path,n,col,list);
            free(path);
        }
    }
}
