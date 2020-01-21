//
//  graphAnalyser.c
//  problemsets_2a
//
//  Created by Steve on 18/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

#define MAX_NODES 1000

// determine minimum and maximum degree of graph g with n vertices
// and output all nodes of those degrees

void MinMaxDegree(Graph g)
{
    int minDegree, maxDegree;
    int nb_vertices = numOfVertices(g);
    int degree[MAX_NODES];
    minDegree = nb_vertices - 1;
    maxDegree = 0;

    int v, w;
    for (v = 0; v < nb_vertices; v++)
    {
        degree[v] = 0;
        for (w = 0; w<nb_vertices; w++)
        {
            if (adjacent(g, v, w))
            {
                degree[v]++;
            }
        }
        if (degree[v] < minDegree)
        {
            minDegree = degree[v];
        }
        if (degree[v] > maxDegree)
        {
            maxDegree = degree[v];
        }
    }
    printf("Minimum degree: %d\n", minDegree);
    printf("Maximum degree: %d\n", maxDegree);

    printf("Nodes of minimun degree:\n");
    for (int i = 0; i < nb_vertices; i++)
    {
        if (degree[i] == minDegree)
        {
            printf("%d\n", i);
        }
    }

    printf("Nodes of maximum degree:\n");
    for (int i = 0; i < nb_vertices; i++)
    {
        if (degree[i] == maxDegree)
        {
            printf("%d\n", i);
        }
    }
}

void Show3Cliques(Graph g)
{
    int nb_vertices = numOfVertices(g);
    printf("Triangles: \n");
    for (int i = 0; i < nb_vertices - 2; i++)
    {
        for (int j = i + 1; j < nb_vertices - 1; j++)
        {
            if (adjacent(g, i, j))
            {
                for (int k = j + 1; k < nb_vertices; k++)
                {
                    if (adjacent(g, i, k) && adjacent(g, j, k))
                    {
                        printf("%d - %d - %d\n", i, j, k);
                    }
                }
            }
        }
    }
}

//int main(void)
//{
//    int nb_vertices;
//    Edge e;
//    printf("Enter the number of vertices: ");
//    scanf("%d", &nb_vertices);
//
//    Graph g = newGraph(nb_vertices);
//
//    printf("Enter an edge (from): ");
//    while (scanf("%d", &e.v) == 1)
//    {
//        printf("Enter an edge (to): ");
//        scanf("%d", &e.w);
//        insertEdge(g, e);
//        printf("Enter an edge (from): ");
//    }
//    printf("Done.\n");
//
//    MinMaxDegree(g);
//    Show3Cliques(g);
//    freeGraph(g);
//
//    return 0;
//}
