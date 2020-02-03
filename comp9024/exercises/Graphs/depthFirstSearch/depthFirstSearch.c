
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void depthFirstPrint(Graph g, int v, int *visited, int nV)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < nV; i++)
    {
        if (GraphIsAdjacent(g, v, i) && visited[i] == -1)
        {
            depthFirstPrint(g, i, visited, nV);
        }
    }
}

void depthFirstSearch(Graph g, int src)
{
    int nV = GraphNumVertices(g);
    int visited[nV];
    for (int i = 0; i < nV; i++)
    {
        visited[i] = -1;
    }
    visited[src] = 1;
    printf("%d ", src);
    for (int i = 0; i < nV; i++)
    {
        if (GraphIsAdjacent(g, src, i) && visited[i] == -1)
        {
            depthFirstPrint(g, i, visited, nV);
        }
    }
}
