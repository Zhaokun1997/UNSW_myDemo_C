#include "Graph.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define VERY_HIGH_VALUE 10000
#define INFINITY 100

int vertices[MAX_NODES]; // components record
int visited[MAX_NODES];  // visited record
int dist[MAX_NODES];     // record shortest path length
int prev[MAX_NODES];     // record previous node for the shortest path

// reachable
int dfsReachableNodes(Graph g, int numOfVertices, Vertex v)
{
    int total = 0;
    visited[v] = 1;
    Vertex w;
    for (w = 0; w < numOfVertices; w++)
    {
        if (adjacent(g, v, w) && !visited[w])
        {
            // plus further
            total += dfsReachableNodes(g, numOfVertices, w);
        }
    }
    // plus current vertex
    total++;
}

int countReachableNodes(Graph g, Vertex v, int numberOfVertices)
{
    Vertex vertex;
    for (vertex = 0; vertex < numberOfVertices; vertex++)
    {
        visited[vertex] = 0;
    }
    return dfsReachableNodes(g, numberOfVertices, v);
}

// DFS
bool dfsPathCheck(Graph g, Vertex src, Vertex dest, int numOfVertices)
{
    if (src == dest)
    {
        return true;
    } else
    {
        for (Vertex w = 0; w < numOfVertices; w++)
        {
            if (adjacent(g, src, w) && visited[w] == -1)
            {
                // target
                visited[w] = src;
                // if found
                if (dfsPathCheck(g, w, dest, numOfVertices))
                {
                    return true;
                }
            }
        }
        return false;
    }
}

void dfsFindPath(Graph g, Vertex src, Vertex dest, int numOfVertices)
{
    for (Vertex w = 0; w < numOfVertices; w++)
    {
        visited[w] = -1;
    }
    visited[src] = src;

    if (dfsPathCheck(g, src, dest, numOfVertices))
    {
        Vertex v = dest;
        while (v != src)
        {
            printf("%d--", v);
            v = visited[v];
        }
    }
}

// BFS
bool bfsFindPath(Graph g, Vertex src, Vertex dest, int numOfVertices)
{
    Vertex w;
    for (w = 0; w < numOfVertices; w++)
    {
        visited[w] = -1;
    }

    visited[src] = src;
    queue Q = newQueue();
    QueueEnqueue(Q, src);
    // while queue Q is not empty
    Vertex t;
    while (!QueueIsEmpty(Q))
    {
        t = QueueDequeue(Q);
        for (Vertex w = 0; w < numOfVertices; w++)
        {
            // scan all adjacent vertex
            if (adjacent(g, t, w) && visited[w] == -1)
            {
                visited[w] = t;
                if (w == dest)
                {
                    return true;
                } else
                {
                    QueueEnqueue(Q, w);
                }
            }
        }
    }

    return false;
}

// CYCLE
bool dfsCycleCheck(Graph g, Vertex v, Vertex u, int numOfVertices)
{
    visited[v] = 1;
    Vertex w;
    for (w = 0; w < numOfVertices; w++)
    {
        if (adjacent(g, v, w))
        {
            // if has not been visited, go to next vertex
            if (!visited[w] && dfsCycleCheck(g, w, v, numOfVertices))
            {
                return true;
            }
            // if has been visited, estimate whether it is the same vertex with before
            if (visited[w] && w != u)
            {
                return true;
            }
        }
    }
    // no cycle
    return false;
}

bool hasCycle(Graph g, int numOfVertices)
{
    Vertex v;
    // set default
    for (v = 0; v < numOfVertices; v++)
    {
        visited[v] = 0;
    }
    // for each vertice
    for (v = 0; v < numOfVertices; v++)
    {
        if (!visited[v] && dfsCycleCheck(g, v, v, numOfVertices))
        {
            return true;
        }
    }
    return false;
}

// components
void dfsComponents(Graph g, int numOfVertices, Vertex v, int componentId)
{
    vertices[v] = componentId;
    Vertex w;
    for (Vertex w = 0; w < numOfVertices; w++)
    {
        if (adjacent(g, v, w) && vertices[w] == -1)
        {
            dfsComponents(g, numOfVertices, w, componentId);
        }
    }
}

int components(Graph g, int numOfVertices)
{
    // set default
    Vertex v;
    for (v = 0; v < numOfVertices; v++)
    {
        vertices[v] = -1;
    }
    int componentId = 0;

    // set componentId for each vertex
    for (v = 0; v < numOfVertices; v++)
    {
        // if not visited
        if (vertices[v] == -1)
        {
            dfsComponents(g, numOfVertices, v, componentId);
            componentId++;
        }
    }
    return componentId;
}

// Dijkstra Algorithm
// returns the number of edges on the shortest path
int shortestDistance(Graph g, int src, int dest, int numOfVertices)
{
    int total_dist = 0;
    if (src == dest)
    {
        return total_dist;
    } else
    {
        // initialization
        for (Vertex v = 0; v < numOfVertices; v++)
        {
            visited[v] = 0;
            dist[v] = INFINITY;
            // prev[v] = -1;
        }
        dist[src] = 0;

        // process
        int i, j, k;
        int min;
        // everytime find the shortest path for a particular vertex
        for (Vertex i = 0; i < numOfVertices; i++)
        {
            min = INFINITY;
            // find minimum of current processing list
            for (Vertex j = 0; j < numOfVertices; j++)
            {
                if (!visited && dist[j] < min)
                {
                    min = dist[j];
                    k = j;
                }
            }
            for (j = 0; j < numOfVertices; j++)
            {
                if (adjacent(g, k, j) && !visited[j] && dist[j] > min + 1)
                {
                    dist[j] = min + 1;
                    prev[j] = k;
                }
            }
            visited[k] = 1;
        }
        if (dist[dest] == INFINITY)
        {
            return -1;
        } else
        {
            return dist[dest];
        }
    }
}