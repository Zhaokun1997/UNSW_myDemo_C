
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

#define INFINITY 100

int furthestReachable(Graph g, int src)
{
    int nV = GraphNumVertices(g);
    int dist[nV];
    int visited[nV];

    // initialization
    for (int i = 0; i < nV; i++)
    {
        dist[i] = INFINITY;
        visited[i] = 0;
    }
    dist[src] = 0;

    // process
    int i, j, k;
    int min;
    for (i = 0; i < nV; i++)
    {
        min = INFINITY;
        for (j = 0; j < nV; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        for (j = 0; j < nV; j++)
        {
            if (GraphIsAdjacent(g, k, j) && visited[j] == 0 && dist[j] > min + 1)
            {
                dist[j] = min + 1;
            }
        }
        visited[k] = 1;
    }

    int maxLen = 0;
    int target;
    for (int i = 0; i < nV; i++)
    {
        if (dist[i] != INFINITY && dist[i] >= maxLen)
        {
            target = i;
            maxLen = dist[i];
        }
    }
    if (maxLen == 0) // case 1: isolated vertex
    {
        return src;
    } else
    {
        return target;
    }
}
