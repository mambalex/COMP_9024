//
// Created by Alex Zhang on 1/10/17.
//

#ifndef ASS2_GRAPH_H
#define ASS2_GRAPH_H

#endif //ASS2_GRAPH_H
#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
    Vertex v;
    Vertex w;
} Edge;

Graph newGraph(int);
void  insertEdge(Graph, Edge);
void  freeGraph(Graph);
void  show(Graph, int, int, char[][20]);
void  FindLongestPath(Graph, int,int,char[][20]);
void  print_path(int,int[],int,int,char[][20]);