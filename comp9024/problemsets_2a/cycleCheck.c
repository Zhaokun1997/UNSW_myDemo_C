//
//  cycleCheck.c
//  problemsets_2a
//
//  Created by Steve on 19/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "Graph.h"

#define MAX_NODES 1000

// determine minimum and maximum degree of graph g with n vertices
// and output all nodes of those degrees

int visited[MAX_NODES];
bool dfsCycleCheck(Graph g, Vertex v, Vertex u);
bool hasCycle(Graph g);


bool dfsCycleCheck(Graph g, Vertex v, Vertex u)
{
    visited[v] = true;
    Vertex w;
    for (w = 0; w < numOfVertices(g); w++)
    {
        if (adjacent(g, v, w))
        {
            if (!visited[w])
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
    int v;
    int nV = numOfVertices(g);
    for (v = 0; v < nV; v++)
    {
        visited[v] = false;
    }
    for (v = 0; v < nV; v++)
    {
        if (!visited[v])
        {
            if (dfsCycleCheck(g, v, v))
            {
                return true;
            }
        }
    }
    return false;
}

//int main(void)
//{
//
//
//    return 0;
//}
