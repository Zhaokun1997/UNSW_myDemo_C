
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src)
{
    int nV = GraphNumVertices(g);
    int visited[nV];
    // set initialization
    for (int i = 0; i < nV; i++)
    {
        visited[i] = -1;
    }
    Queue q = QueueNew();
    QueueEnqueue(q, src);
    visited[src] = 1;
    printf("%d ", src);
    int curr_vertex;
    while (!QueueIsEmpty(q))
    {
        curr_vertex = QueueDequeue(q);
        for (int i = 0; i < nV; i++)
        {
            if (GraphIsAdjacent(g, curr_vertex, i) && visited[i] == -1)
            {
                QueueEnqueue(q, i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    QueueFree(q);
}
