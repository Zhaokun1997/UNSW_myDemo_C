//
// Created by Rui.Mu on 2019-02-02.
//
#include "Graph.h"
#include "list.h"
#include "pqueue.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define VERY_HIGH_VALUE 10000

int vertices[MAX_NODES];
int visited[MAX_NODES];

bool hasEulerPath(Graph g, Vertex v, Vertex w, int numberOfVertices)
{
    if (v != w)
    {
        // if start not equal to end, start and end must be odd
        // else return false
        if (degree(g, v) % 2 == 0 || degree(g, w) % 2 == 0)
            return false;
    } else if (degree(g, v) % 2 != 0)
    {
        // if start equal to end, start and end must be even
        // else return false
        return false;
    }
    Vertex x;
    // other vertices must be even
    // otherwise return false
    for (x = 0; x < numberOfVertices; x++)
        if (x != v && x != w && degree(g, x) % 2 != 0)
            return false;
    // return true
    return true;
}

/**
 * test euler path
 * @return
 */
int testEulerPath(void)
{
    int V = 10;
    Graph g = newGraph(V);

    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 1;
    e.w = 5;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v = 3;
    e.w = 4;
    insertEdge(g, e);
    e.v = 3;
    e.w = 5;
    insertEdge(g, e);
    e.v = 3;
    e.w = 8;
    insertEdge(g, e);
    e.v = 4;
    e.w = 5;
    insertEdge(g, e);
    e.v = 4;
    e.w = 7;
    insertEdge(g, e);
    e.v = 4;
    e.w = 8;
    insertEdge(g, e);
    e.v = 5;
    e.w = 6;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 9;
    insertEdge(g, e);
    e.v = 8;
    e.w = 9;
    insertEdge(g, e);

    int src = 0, dest = 6;

    hasEulerPath(g, src, dest, V);

    freeGraph(g);

    return 0;
}

bool hamiltonR(Graph g, int nV, Vertex v, Vertex dest, int d)
{
    // v = current vertex considered
    // dest = destination vertex
    // d = distance "remaining" until path found
    Vertex w;
    if (v == dest)
    {
        return (d == 0);
    }

    visited[v] = true;
    for (w = 0; w < nV; w++)
    {
        if (adjacent(g, v, w) && !visited[w] && hamiltonR(g, nV, w, dest, d - 1))
        {
            return true;
        }
    }

    // notice reset back
    visited[v] = false;
    return false;
}

/**
 * check has hamilton path
 * @param g
 * @param nV
 * @param src
 * @param dest
 * @return
 */
bool hasHamiltonianPath(Graph g, int nV, Vertex src, Vertex dest)
{
    // set default
    // all not visited
    Vertex v;
    for (v = 0; v < nV; v++)
        visited[v] = false;
    // check hamilton
    return hamiltonR(g, nV, src, dest, nV - 1);
}

int testHamiltonianPath(void)
{
    int V = 10;
    Graph g = newGraph(V);

    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 1;
    e.w = 5;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v = 3;
    e.w = 4;
    insertEdge(g, e);
    e.v = 3;
    e.w = 5;
    insertEdge(g, e);
    e.v = 3;
    e.w = 8;
    insertEdge(g, e);
    e.v = 4;
    e.w = 5;
    insertEdge(g, e);
    e.v = 4;
    e.w = 7;
    insertEdge(g, e);
    e.v = 4;
    e.w = 8;
    insertEdge(g, e);
    e.v = 5;
    e.w = 6;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 9;
    insertEdge(g, e);
    e.v = 8;
    e.w = 9;
    insertEdge(g, e);
    int src = 0, dest = 6;
    int result = hasHamiltonianPath(g, V, src, dest);
    // print
    printf("\nHamiltonianPath result is :%d", result);
    freeGraph(g);
    return 0;
}

/**
 *
 * @param g
 * @param sortedEdges
 * @param nV
 * @param nE
 * @return
 */
Graph kruskal(Edge sortedEdges[], int nV, int nE)
{
    Graph result = newGraph(nV);
    int i, n = 0;
    for (i = 0; i < nE && n < nV - 1; i++)
    {
        Edge e = sortedEdges[i];
        insertEdge(result, e);
        n++;
        Vertex v;
        for (v = 0; v < nV; v++)
            visited[v] = false;
        if (dfsCycleCheck(result, e.v, e.v, nV))
        { // cycle through node e.v?
            removeEdge(result, e);
            n--;
        }
    }
    return result;
}

/**
 * test Kruskal
 * @return
 */
int testKruskal(void)
{
    int nV = 5;
    Graph g = newGraph(nV);

    Edge edges[8];
    edges[0].v = 2;
    edges[0].w = 3;
    edges[0].weight = 1;
    edges[1].v = 0;
    edges[1].w = 2;
    edges[1].weight = 2;
    edges[2].v = 0;
    edges[2].w = 1;
    edges[2].weight = 3;
    edges[3].v = 1;
    edges[3].w = 2;
    edges[3].weight = 4;
    edges[4].v = 2;
    edges[4].w = 4;
    edges[4].weight = 5;
    edges[5].v = 1;
    edges[5].w = 4;
    edges[5].weight = 6;
    edges[6].v = 3;
    edges[6].w = 4;
    edges[6].weight = 7;
    edges[7].v = 0;
    edges[7].w = 3;
    edges[7].weight = 8;

    int i, nE = 8;
    for (i = 0; i < nE; i++)
    {
        insertEdge(g, edges[i]);
    }
    showGraph(g);
    Graph mst = kruskal(edges, nV, nE);
    showGraph(mst);
    freeGraph(mst);
    freeGraph(g);

    return 0;
}

void showDijkstraPath(int v, int pred[])
{
    if (pred[v] == -1)
    {
        printf("%d", v);
    } else
    {
        showDijkstraPath(pred[v], pred);
        printf("-%d", v);
    }
}

void dijkstraSSSP(Graph g, int nV, Vertex source)
{
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    bool vSet[MAX_NODES]; // vSet[v] = true <=> v has not been processed
    int s, t;

    PQueue pQueue = newPQueue();
    for (s = 0; s < nV; s++)
    {
        joinPQueue(pQueue, s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;
    while (!PQueueIsEmpty(pQueue))
    {
        s = leavePQueue(pQueue);
        vSet[s] = false;
        for (t = 0; t < nV; t++)
        {
            if (vSet[t])
            {
                int weight = adjacent(g, s, t);
                if (weight > 0 && dist[s] + weight < dist[t])
                { // relax along (s,t,weight)
                    dist[t] = dist[s] + weight;
                    pred[t] = s;
                }
            }
        }
    }
    for (s = 0; s < nV; s++)
    {
        printf("%d: ", s);
        if (dist[s] < VERY_HIGH_VALUE)
        {
            printf("distance = %d, shortest path: ", dist[s]);
            showDijkstraPath(s, pred);
            putchar('\n');
        } else
        {
            printf("no path\n");
        }
    }

    // free
    freePQueue(pQueue);
}

/**
 * 测试插入排序
 * @param array
 * @param n
 * @return
 */
void testInsertionSortArr()
{
    int array[10] = {1, 4, 3, 5, 7, 9, 8, 6, 2};
    int n = 10, element, i, j;
    for (i = 1; i < n; i++)
    {
        element = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > element)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = element;
    }

    // print result
    printf("testInsertionSortArr:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

/**
 * 测试插入排序
 * @param array
 * @param n
 * @return
 */
void testInsertionSortList()
{
    List list = malloc(sizeof(List));
    list->v = 10;
    list->next = NULL;

    insertLL(list, 1);
    insertLL(list, 4);
    insertLL(list, 3);
    insertLL(list, 2);
    insertLL(list, 5);
    insertLL(list, 17);
    insertLL(list, 14);
    insertLL(list, 6);

    int n = 8, i = 0, j = 0;

    List nodes[8], element;

    List header = (List)list;

    while (header != NULL)
    {
        nodes[i] = header;
        i++;
        header = header->next;
    }

    for (i = 1; i < n; i++)
    {
        element = nodes[i];
        j = i - 1;
        while (j >= 0 && nodes[j]->v > element->v)
        {
            nodes[j + 1] = nodes[j];
            j--;
        }
        nodes[j + 1] = element;
    }

    // print result
    printf("testInsertionSortArr:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d \n", nodes[i]->v);
    }

    freeLL(list);
}

/**
 * main method
 * @return
 */
int main()
{
    int V = 6;
    Graph g = newGraph(V);

    Edge e;
    e.v = 2;
    e.w = 0;
    insertEdge(g, e);
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 1;
    e.w = 3;
    insertEdge(g, e);

    int result = hasCycle(g, V);
    // print
    printf("\n hasCycle result is :%d\n", result);
    freeGraph(g);

    // dfsCheck
}
