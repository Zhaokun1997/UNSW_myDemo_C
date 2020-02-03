
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int nbReachable(Graph g, Vertex v, int *visited, int nV)
{
    int total = 0;
    visited[v] = 1;

    for (int i = 0; i < nV; i++)
    {
        if (GraphIsAdjacent(g, v, i) && visited[i] == -1)
        {
            total = total + nbReachable(g, i, visited, nV);
        }
    }
    total++; // for node v

    return total;
}

int numReachable(Graph g, int src)
{
    int total = 0;
    int nV = GraphNumVertices(g);
    int visited[nV];

    for (int i = 0; i < nV; i++)
    {
        visited[i] = -1;
    }
    visited[src] = 1;
    for (int i = 0; i < nV; i++)
    {
        if (GraphIsAdjacent(g, src, i) && visited[i] == -1)
        {
            total = total + nbReachable(g, i, visited, nV);
        }
    }
    total++;

    return total;
}
