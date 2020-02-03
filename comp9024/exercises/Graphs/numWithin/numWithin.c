
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

#define INFINITY 100

// must to search by breadth
int numWithin(Graph g, int src, int dist)
{
    if (dist == 0)
    {
        return 1;
    }

    int total_num = 0;
    int nV = GraphNumVertices(g);
    int shortestDist[nV];
    int visited[nV];

    // initialization
    for (int i = 0; i < nV; i++)
    {
        shortestDist[i] = INFINITY;
        visited[i] = 0;
    }
    shortestDist[src] = 0;

    // process to get shortest
    int i, j, k;
    int min;
    // everytime fine a shortest path for a particular vertex
    for (i = 0; i < nV; i++)
    {
        // in the unvisited set, find the minimum distance
        min = INFINITY;
        for (j = 0; j < nV; j++)
        {
            if (visited[j] == 0 && shortestDist[j] < min)
            {
                min = shortestDist[j];
                k = j;
            }
        }
        for (j = 0; j < nV; j++)
        {
            if (GraphIsAdjacent(g, k, j) && visited[j] == 0 && shortestDist[j] > min + 1)
            {
                shortestDist[j] = min + 1;
            }
        }
        visited[k] = 1;
    }

    for (int i = 0; i < nV; i++)
    {
        if (shortestDist[i] <= dist)
        {
            total_num++;
        }
    }

    return total_num;
}
