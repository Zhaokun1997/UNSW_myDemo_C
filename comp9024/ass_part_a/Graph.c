

//
//  Graph.c
//  ass_part_a
//
//  Created by Steve on 16/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct GraphRep
{
    int **edges; // adjacency matrix
    int nV;      // #vertices
    int nE;      // #edges
} GraphRep;

Graph newGraph(int V)
{
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each now
    g->edges = malloc(V * sizeof(int *));
    assert(g->edges != NULL);

    // allocate memory for each column and initialise with 0
    for (i = 0; i < V; i++)
    {
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);
    }

    return g;
}

int numOfVertices(Graph g)
{
    return g->nV;
}

bool validV(Graph g, Vertex v)
{
    return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e)
{
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));
    if (!g->edges[e.v][e.w])
    {
        g->edges[e.v][e.w] = 1;
        g->nE++;
    }
}
void removeEdge(Graph g, Edge e)
{
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));
    if (g->edges[e.v][e.w])
    {
        g->edges[e.v][e.w] = 0;
        g->nE--;
    }
}

bool adjacent(Graph g, Vertex v, Vertex w)
{
    assert(g != NULL && validV(g, v) && validV(g, w));

    return (g->edges[v][w] != 0 || g->edges[w][v] != 0);
}

bool goOutTo(Graph g, Vertex src, Vertex dest)
{
    return (g->edges[src][dest] != 0);
}

void showGraph(Graph g)
{
    assert(g != NULL);
    int i, j;
    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
    {
        for (j = 0; j < g->nV; j++)
        {
            if (g->edges[i][j])
            {
                printf("Edge %d - %d\n", i, j);
            }
        }
    }
}
void freeGraph(Graph g)
{
    assert(g != NULL);
    int i;
    for (i = 0; i < g->nV; i++)
    {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}
