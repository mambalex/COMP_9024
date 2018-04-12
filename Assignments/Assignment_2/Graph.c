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

void show(Graph g, int row, int col, char list[row][col]) {     /* print adjacency, time complexity: O(n²) */
    assert(g != NULL);
    int i, j;
    for (i = 0; i < g->nV; i++){            /*loop each word once, time complexity: O(n) */
        printf("\n");                       /* time complexity: O(n) */
        printf("%s: ",list[i]);             /* time complexity: O(n²) */
        for (j = i+1; j < g->nV; j++) {     /*loop the second word, time complexity: O(n²) */
            if (g->edges[i][j])             /* time complexity: O(n²) */
                printf("%s ",list[j]);}     /* time complexity: O(n²) */
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

void print_path(int n, int l[n],int row, int col, char list[row][col]){        /* print path, time complexity: O(n) */
    int loop;                                   /* time complexity: O(1) */
    for (loop = n; loop >= 0; loop--){          /*print reversed array, time complexity: O(n) */
        if(loop == 0){                          /* time complexity: O(n) */
            printf("%s\n",list[l[loop]]);       /* time complexity: O(n) */
        } else{
            printf("%s -> ",list[l[loop]]);     /* time complexity: O(n) */
        }
    }
}

void FindLongestPath(Graph g, int n, int col, char list[n][col]){    /* inspired by Dijkstra algorithm, overall time complexity: O(n²) */
    int distance[n],pred[n];    /* time complexity: O(1) */
    int seq,i;                  /* time complexity: O(1) */
    int max_dist = 0;           /* time complexity: O(1) */

    for(i=0;i<n;i++)            /* initialize pred[],distance[], time complexity: O(n) */
    {
        distance[i]= 0;        /* time complexity: O(n) */
        pred[i]=0;              /* time complexity: O(n) */
    }

    distance[0]=0;              /* time complexity: O(1) */
    seq=0;                      /* time complexity: O(1) */


    while(seq<n-1)                                                            /* find longest path, time complexity: O(n) */
    {
        for(i=seq+1;i<n;i++){                                                 /* loop the second word, time complexity: O(n²) */
            if (g->edges[seq][i]== 1 && distance[seq]+1 > distance[i]) {      /* two words are adjacent, time complexity: O(n²) */
                distance[i] = distance[seq] + 1;
                pred[i] = seq;
            }
        }
        seq+=1;
    }
    for(i=0;i<n;i++){                          /* find maximum length,time complexity: O(n) */
        if (max_dist < distance[i]){           /* time complexity: O(n) */
          max_dist = distance[i];              /* time complexity: O(n) */
        }
    }

    printf("Maximum chain length: %d\n",max_dist+1);        /* time complexity: O(1) */
    printf("Maximal chains:\n");                            /* time complexity: O(1) */

    int temp = 0;                                           /* time complexity: O(1) */
    int p;                                                  /* time complexity: O(1) */
    for(i=0;i<n;i++){                                       /* time complexity: O(n) */
        if (distance[i] == max_dist){                       /* destinations of longest path, time complexity: O(n) */
            int *path = malloc((max_dist+1)*sizeof(int));   /* allocate memory for path, time complexity: O(n) */
            temp = 0;                                       /* time complexity: O(n) */
            path[temp] = i;                                 /* time complexity: O(n) */
            p = pred[i];                                    /* time complexity: O(n) */
            while (p!=0){                                   /* generate the longest path, time complexity: O(n²) */
                temp += 1;                                  /* time complexity: O(n²) */
                path[temp] = p;                             /* time complexity: O(n²) */
                p = pred[p];                                /* time complexity: O(n²) */
            }
            path[temp+1] = p;                               /* time complexity: O(n) */
            print_path(max_dist,path,n,col,list);           /* time complexity: O(n) */
            free(path);                                     /* free path's memory, time complexity: O(n) */
        }
    }
}
