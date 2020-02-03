
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

#define INFINITY 100

// returns the number of edges on the shortest path
int shortestDistance(Graph g, int src, int dest)
{
    int nV = GraphNumVertices(g);
    // int visited[nV];
    int dist[nV];
    // int prev[nV];
    int flag[nV];

    int total_dist = 0;
    if (src == dest)
    {
        return total_dist;
    } else
    {
        // initialization
        for (int i = 0; i < nV; i++)
        {
            dist[i] = INFINITY;
            // prev[i] = -1;
            flag[i] = 0;
        }
        dist[src] = 0;

        // process
        int i, j, k;
        int min;
        // everytime fine a shortest path for a particular vertex
        for (i = 0; i < nV; i++)
        {
            min = INFINITY;
            for (j = 0; j < nV; j++)
            {
                if (flag[j] == 0 && dist[j] < min)
                {
                    min = dist[j];
                    k = j;
                }
            }
            for (j = 0; j < nV; j++)
            {
                if (GraphIsAdjacent(g, k, j) && flag[j] == 0 && dist[j] > min + 1)
                {
                    dist[j] = min + 1;
                    // prev[j] = k;
                }
            }
            flag[k] = 1; // won't visit again
        }
        if (dist[dest] == INFINITY)
        {
            return -1;
        }
        return dist[dest];
    }
}
