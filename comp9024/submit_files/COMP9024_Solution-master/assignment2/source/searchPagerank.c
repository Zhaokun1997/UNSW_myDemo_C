

//
//  searchPagerank.c
//  ass_part_c
//
//  Created by Steve on 9/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSTRING 1000
#define MAXWORD 50

// url node
typedef struct url
{
    char name[MAXWORD]; // url's name
    int outdegree;
    float pageRank;
    int freq; // url's frequence
    struct url *next;
} UrlU;

// queryWord node
typedef struct queryWord
{
    char name[MAXWORD]; // word's name
    struct url *head;   // word's urls
    struct queryWord *next;
} QueryWordQ;

// pre_declaration
int isInQueryWords(char *word, const char *query_words[], int nb_query_words);
UrlU *makeUrlNode(char *name);                   // create a url node
UrlU *insertUrlNode(UrlU *list, char *url_name); // insert a url node
UrlU *insertUrlNodeByOrder(UrlU *list, char *url_name, int freq, float pageRank);
QueryWordQ *makeWordNode(char *word, UrlU *url_list);                           // create a word node
QueryWordQ *insertQueryNode(QueryWordQ *list, char *word_name, UrlU *url_list); // insert a word node
int inUrlList(UrlU *list, char *name);
void showWordList(QueryWordQ *list);
void showUrlList(UrlU *list);
void freeWordList(QueryWordQ *list);
void freeUrlList(UrlU *list);
UrlU *getResultList(UrlU *list);
UrlU *findMatchedUrls(const char *file_name, const char *query_words[], int nb_query_words);
UrlU *findPageRank(const char *file_name, UrlU *matchedList);

int isInQueryWords(char *word, const char *query_words[], int nb_query_words)
{
    int i;
    for (i = 0; i < nb_query_words; i++)
    {
        if (strcmp(word, query_words[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

UrlU *makeUrlNode(char *name)
{
    UrlU *new;
    new = (UrlU *)malloc(sizeof(UrlU));
    assert(new != NULL);
    strcpy(new->name, name);
    new->freq = 1;
    new->next = NULL;
    return new;
}

UrlU *insertUrlNode(UrlU *list, char *url_name)
{
    UrlU *new = makeUrlNode(url_name);
    new->next = list;
    return new;
}

// insert urls by pageRank order
UrlU *insertUrlNodeByOrder(UrlU *list, char *url_name, int freq, float pageRank)
{
    if (list == NULL)
    {
        UrlU *new = makeUrlNode(url_name);
        new->freq = freq;
        new->pageRank = pageRank;
        new->next = NULL;
        list = new;
        return list;
    } else
    {
        UrlU *prev, *curr;
        prev = NULL;
        curr = list;
        UrlU *new = makeUrlNode(url_name);
        new->freq = freq;
        new->pageRank = pageRank;

        // case 1: L.freq < new.freq
        if (curr != NULL && curr->freq < freq)
        {
            list = new;
            new->next = curr;
            return list;
        }
        // case 2: L.freq = new.freq
        else if (curr != NULL && curr->freq == freq)
        {
            //            printf("now, prev is : %p\n", prev);
            //            printf("now, curr is : %p\n", curr);
            while (curr != NULL && curr->freq >= freq && curr->pageRank > pageRank)
            {
                prev = curr;
                curr = curr->next;
                //                printf("now, prev is : %p\n", prev);
                //                printf("now, curr is : %p\n", curr);
            }
            if (prev == NULL)
            {
                list = new;
                new->next = curr;
                return list;
            }
            prev->next = new;
            new->next = curr;
            return list;
        }
        // case 3: L.freq > new.freq
        else
        {
            while (curr != NULL && curr->freq > freq)
            {
                prev = curr;
                curr = curr->next;
            }
            while (curr != NULL && curr->freq >= freq && curr->pageRank > pageRank)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = new;
            new->next = curr;
            return list;
        }
    }
}

QueryWordQ *makeWordNode(char *word, UrlU *url_list)
{
    QueryWordQ *new;
    new = (QueryWordQ *)malloc(sizeof(QueryWordQ));
    assert(new != NULL);
    strcpy(new->name, word);
    new->head = url_list;
    new->next = NULL;
    return new;
}

QueryWordQ *insertQueryNode(QueryWordQ *list, char *word_name, UrlU *url_list)
{
    QueryWordQ *new = makeWordNode(word_name, url_list);
    new->next = list;
    return new;
}

int inUrlList(UrlU *list, char *name)
{
    if (list == NULL)
    {
        return 0;
    }
    UrlU *up;
    for (up = list; up != NULL; up = up->next)
    {
        if (strcmp(up->name, name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void showWordList(QueryWordQ *list)
{
    QueryWordQ *p;
    UrlU *q;
    for (p = list; p != NULL; p = p->next)
    {
        printf("%s : ", p->name);
        for (q = p->head; q != NULL; q = q->next)
        {
            printf("%s ", q->name);
        }
        printf("\n");
    }
}

void showUrlList(UrlU *list)
{
    // print to test
    UrlU *temp;
    temp = list;
    while (temp != NULL)
    {
        printf("%s: frequence: %d pagerank: %f\n", temp->name, temp->freq, temp->pageRank);
        temp = temp->next;
    }
}

void freeWordList(QueryWordQ *list)
{
    QueryWordQ *p, *temp_p;
    UrlU *q, *temp_q;

    p = list;
    while (p != NULL)
    {
        q = p->head;
        while (q != NULL)
        {
            temp_q = q->next;
            free(q);
            q = temp_q;
        }
        temp_p = p->next;
        free(p);
        p = temp_p;
    }
}

void freeUrlList(UrlU *list)
{
    UrlU *p, *temp;
    p = list;
    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}

// to sort
UrlU *getResultList(UrlU *list)
{
    UrlU *result_list = NULL;
    UrlU *temp;
    temp = list;
    //    printf("insert order is following : \n");
    while (temp != NULL)
    {
        //        printf("%s\n", temp->name);
        result_list = insertUrlNodeByOrder(result_list, temp->name, temp->freq, temp->pageRank); // insert by order
                                                                                                 //        showUrlList(result_list);
        temp = temp->next;
    }
    //    printf("\n");
    //    showUrlList(result_list); // print
    return result_list;
}

UrlU *findMatchedUrls(const char *file_name, const char *query_words[], int nb_query_words)
{
    char delim[2] = " ";
    char *word;
    char line[MAXSTRING];
    FILE *invertedFile;

    if ((invertedFile = fopen(file_name, "r")) == NULL)
    {
        printf("Failed to open file.\n");
        return (0);
    }

    // char searchWords[nb_query_words][MAXWORD];
    QueryWordQ *begin = NULL; // head address of words
    while (fgets(line, MAXSTRING, invertedFile) != NULL)
    {
        // first word
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0'; // subsitute '\n' to '\0' at the end of every line
        }
        word = strtok(line, delim); // char *strtok(char *str, const char *delim)
        // strcpy(searchWords[i++], token);  // char *strcpy(char *dest, const char *src)
        if (isInQueryWords(word, query_words, nb_query_words) == 1) // find corresponding search words
        {
            char *first_token = word;
            UrlU *head = NULL; // head address of word's urls

            // for every query word
            if (word != NULL)
            {
                while ((word = strtok(NULL, delim)) != NULL)
                {
                    head = insertUrlNode(head, word);
                }
            }
            begin = insertQueryNode(begin, first_token, head);
        }
    }

    fclose(invertedFile);
    UrlU *matched_list = NULL;
    QueryWordQ *temp_q = NULL;
    UrlU *temp_u = NULL;
    temp_q = begin;
    while (temp_q != NULL)
    {
        temp_u = temp_q->head;
        while (temp_u != NULL)
        {
            // printf("%s\n", temp_u->name);
            if (inUrlList(matched_list, temp_u->name) == 1) // if matched_list has contained url, the corresponding url freq +1
            {
                UrlU *search = matched_list;
                while (search != NULL)
                {
                    if (strcmp(search->name, temp_u->name) == 0)
                    {
                        search->freq++;
                        break;
                    }
                    search = search->next;
                }
            } else // if matched_list does not contain url, create a new one
            {
                matched_list = insertUrlNode(matched_list, temp_u->name);
                // showUrlList(matched_list);
            }
            temp_u = temp_u->next;
        }
        temp_q = temp_q->next;
    }
    //    showWordList(begin);
    freeWordList(begin);

    return matched_list;
}

UrlU *findPageRank(const char *file_name, UrlU *matchedList)
{
    char urlName[MAXWORD];
    char str_outdegree[MAXWORD];
    char str_pageRank[MAXWORD];
    int outdegree;
    float pageRank;
    FILE *pagerankListFile;
    if ((pagerankListFile = fopen(file_name, "r")) == NULL)
    {
        printf("Failed to open file.\n");
        return (0);
    }

    UrlU *new_list = NULL; // result list
    while (!feof(pagerankListFile))
    {
        //        printf("--------\n");
        // first word -- urlName
        // line[strlen(line) - 1] = '\0';  // check txt file if there is a '\n' at the end of file
        fscanf(pagerankListFile, "%s", urlName);
        fscanf(pagerankListFile, "%s", str_outdegree);
        fscanf(pagerankListFile, "%s", str_pageRank);
        // remove comma
        urlName[strlen(urlName) - 1] = '\0';
        str_outdegree[strlen(str_outdegree) - 1] = '\0';
        //                printf("%s   %s   %s\n", urlName, str_outdegree, str_pageRank);

        outdegree = atoi(str_outdegree);
        pageRank = atof(str_pageRank);
        //                printf("%d   %f\n", outdegree, pageRank);
        if (inUrlList(matchedList, urlName) == 1) // if urlname is in list
        {
            // give values
            UrlU *temp;
            temp = matchedList;
            while (temp != NULL)
            {
                if (strcmp(temp->name, urlName) == 0)
                {
                    temp->outdegree = outdegree;
                    temp->pageRank = pageRank;
                    break;
                }
                temp = temp->next;
            }
        }
        // else : do nothing
    }
    fclose(pagerankListFile);
    // by now, list have enough data to sort
    //    printf("matchedList is : \n");
    //    showUrlList(matchedList);
    //    printf("\n");
    new_list = getResultList(matchedList);

    return new_list;
}

int main(int argc, const char *argv[])
{
    // get query words from auguments
    //    for (int i = 0; i < argc; i++)
    //    {
    //        printf("i is %d, argc[%d] is %s \n", i, i, argv[i]);
    //    }
    int nb_query_words = argc - 1;
    const char *query_words[nb_query_words];
    for (int i = 0; i < nb_query_words; i++)
    {
        query_words[i] = argv[i + 1];
        //        printf("query_words[%d] is %s\n", i, query_words[i]);
    }

    UrlU *matchedList = findMatchedUrls("invertedIndex.txt", query_words, nb_query_words); // list contain freq
    UrlU *result = findPageRank("pagerankList.txt", matchedList);
    //    printf("\n");
    //    showUrlList(result);

    // print results
    UrlU *temp = result;
    int i = 0;
    while (temp != NULL && i < 30)
    {
        printf("%s\n", temp->name);
        temp = temp->next;
        i++;
    }
    freeUrlList(matchedList);
    freeUrlList(result);

    return 0;
}
