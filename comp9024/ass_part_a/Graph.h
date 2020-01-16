//
//  Graph.h
//  ass_part_a
//
//  Created by Steve on 16/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

// Graph ADT interface ... COMP9024 19T3

#include <stdio.h>
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
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);
bool  goOutTo(Graph, Vertex, Vertex);
void  showGraph(Graph);
void  freeGraph(Graph);

#endif /* Graph_h */
