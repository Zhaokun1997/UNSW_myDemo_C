
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

#define MAXNODENUM 100
int visited[MAXNODENUM];

bool dfsCycleCheck(Graph g, Vertex v, Vertex u)
{
    visited[v] = 1;
    Vertex w;
    for (w = 0; w < GraphNumVertices(g); w++)
    {
        if (GraphIsAdjacent(g, v, w))
        {
            if (visited[w] == -1)
            {
                if (dfsCycleCheck(g, w, v))
                {
                    return true;
                }
            } else if (w != u)
            {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(Graph g)
{
    int nV = GraphNumVertices(g);
    int v;
    for (v = 0; v < nV; v++)
    {
        visited[v] = -1;
    }
    for (v = 0; v < nV; v++)
    {
        if (visited[v] == -1)
        {
            if (dfsCycleCheck(g, v, v))
            {
                return true;
            }
        }
    }
    return false;
}
