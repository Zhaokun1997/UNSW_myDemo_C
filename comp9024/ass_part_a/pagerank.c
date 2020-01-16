
            
        
    


//
//  pagerank.c
//  ass_part_a
//
//  Created by Steve on 16/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "Graph.h"

#define MAXURLNAME 20 // max space of per urlName
#define MAXURLNUM 50  // max # of urls

typedef struct urlNode
{
    char urlName[MAXURLNAME];
    int outDegree;
    float pageRank;
} UrlT;

UrlT *makeUrlNode(char *urlName);
void freeUrlNodeList(UrlT *urlNodeList[], int nb_of_urls);
int getVertexOrIndex(char *urlName);

UrlT *makeUrlNode(char *urlName)
{
    UrlT *new;
    new = (UrlT *)malloc(sizeof(UrlT));
    assert(new != NULL);
    strcpy(new->urlName, urlName);
    return new;
}

void freeUrlNodeList(UrlT *urlNodeList[], int nb_of_urls)
{
    // free urlNodes
    for (int i = 0; i < nb_of_urls; i++)
    {
        free(urlNodeList[i]);
    }
}

// vertex <--> urlNode
UrlT *urlNodeList[MAXURLNUM];
int nb_of_urls = 0; // record # of total url pages

// get vertex number from urlNodeList
int getVertexOrIndex(char *urlName)
{
    int i;
    for (i = 0; i < nb_of_urls; i++)
    {
        if (strcmp(urlNodeList[i]->urlName, urlName) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char *argv[])
{
    float d = atof(argv[1]);
    float diffPR = atof(argv[2]);
    int maxIterations = atoi(argv[3]);
    printf("d(argv[1]): %f\n", d);
    printf("diffPR(argv[2]): %f\n", diffPR);
    printf("maxIterations(argv[3]): %d\n", maxIterations);

    const char *fname = "collection.txt";
    char urlName[MAXURLNAME];

    // read collection file
    FILE *collectionFile;
    if ((collectionFile = fopen(fname, "r")) == NULL)
    {
        printf("Failed to open collection file.\n");
        return (0);
    }
    int i;

    for (i = 0; !feof(collectionFile); i++)
    {
        // fscanf(): return the successful number of matching
        // when this function meets ' ', '\t', '\n', then it will stop
        if (fscanf(collectionFile, "%s", urlName) == 1)
        {
            urlNodeList[i] = makeUrlNode(urlName);
            nb_of_urls++;
        }
    }
    fclose(collectionFile);

    // create a graph
    Graph g = newGraph(nb_of_urls);

    // read urlFile
    FILE *urlFile;
    char urlFileName[MAXURLNAME];
    char urlRealName[MAXURLNAME];

    // url11, url21, url22, url23...
    for (int i = 0; i < nb_of_urls; i++)
    {
        strcpy(urlFileName, urlNodeList[i]->urlName); // url11
        strcpy(urlRealName, urlNodeList[i]->urlName); // url11
        char *FileName = strcat(urlFileName, ".txt");

        if ((urlFile = fopen(FileName, "r")) == NULL)
        {
            printf("Failed to open url file.\n");
            return (0);
        }
        printf("\n%s has been accessed successfully.\n", FileName);

        // read section-1:
        char beginWord[MAXURLNAME];
        char urlNameInSection1[MAXURLNAME];
        while (!feof(urlFile))
        {
            if (fscanf(urlFile, "%s", beginWord) == 1 && strcmp(beginWord, "Section-1") == 0)
            {
                // begin to read section-1
                Edge e;
                while (fscanf(urlFile, "%s", urlNameInSection1) == 1)
                {
                    if (strcmp(urlNameInSection1, "#end") == 0)
                    {
                        break;
                    }
                    // insert edges +++++++++++++++++++

                    e.v = getVertexOrIndex(urlRealName);
                    e.w = getVertexOrIndex(urlNameInSection1);
                    //                    printf("urlNameInSection1 = %s\n", urlNameInSection1);
                    //                    printf("e.v = %d, e.w = %d\n", e.v, e.w);
                    insertEdge(g, e);
                    urlNodeList[e.v]->outDegree += 1;
                }
                if (strcmp(urlNameInSection1, "#end") == 0)
                {
                    break;
                }
            }
        }
    }
    showGraph(g);

    // initialise pageranks
    for (int i = 0; i < nb_of_urls; i++)
    {
        urlNodeList[i]->pageRank = 1.0 / nb_of_urls; // float
        printf("name: %s, outdegree: %d, pagerank: %f\n", urlNodeList[i]->urlName, urlNodeList[i]->outDegree, urlNodeList[i]->pageRank);
    }

    // calculate pageranks
    int iteration = 0;
    float diff = diffPR;           // to enter the following loop
    float newPageRank[nb_of_urls]; // store temporary updated pagerank
    while (iteration < maxIterations && diff >= diffPR)
    {
        iteration++;

        for (int i = 0; i < nb_of_urls; i++) // looking for vertexs which go out to vertex i
        {
            float sum_prev = 0.0;
            for (int j = 0; j < nb_of_urls; j++)
            {
                if (goOutTo(g, j, i)) // vertex j goes out to vertex i
                {
                    sum_prev = sum_prev + (urlNodeList[j]->pageRank / urlNodeList[j]->outDegree);
                }
            }
            newPageRank[i] = ((1.0 - d) / nb_of_urls) + d * sum_prev;
        }

        // get absolute value
        float sum_for_abs = 0;
        for (int i = 0; i < nb_of_urls; i++)
        {
            sum_for_abs = sum_for_abs + fabsf(newPageRank[i] - urlNodeList[i]->pageRank);
        }
        diff = sum_for_abs;

        // update new data
        for (int i = 0; i < nb_of_urls; i++)
        {
            urlNodeList[i]->pageRank = newPageRank[i];
        }
    }
    
    printf("\n\n");
    for (int i = 0; i < nb_of_urls; i++)
    {
        printf("name: %s, outdegree: %d, pagerank: %f\n", urlNodeList[i]->urlName, urlNodeList[i]->outDegree, urlNodeList[i]->pageRank);
    }
    
    
    freeUrlNodeList(urlNodeList, nb_of_urls);
    freeGraph(g);

    return 0;
}
