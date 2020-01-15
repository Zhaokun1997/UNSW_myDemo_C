

//
//  inverted.c
//  ass_part_b
//
//  Created by Steve on 13/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define MAXURLNAME 20    // max space of per urlName
#define MAXURLNUM 50     // max # of urls
#define MAXWORDLENGTH 30 // max length of word
#define MAXWORDNUM 200   // max words number in section-2
#define DOT '.'          // all punctuations
#define COMMA ','
#define SEMICOLON ';'
#define QUESTIONMARK '?'

typedef struct urlNode
{
    char urlName[MAXURLNAME];
    struct urlNode *next;
} UrlNodeU;

typedef struct wordNode
{
    char wordName[MAXWORDLENGTH];
    struct urlNode *head;
    struct wordNode *next;
} WordNodeW;

// pre-declaration
UrlNodeU *makeUrlNode(char *urlName, UrlNodeU *next);
UrlNodeU *insertUrlNodeByAlphabeticalOrder(UrlNodeU *head, UrlNodeU *urlNode);
int inUrlList(UrlNodeU *list, char *urlName);
void showUrlList(UrlNodeU *head);
void freeUrlList(UrlNodeU *head);
WordNodeW *makeWordNode(char *wordName, UrlNodeU *urlNode, WordNodeW *next);
WordNodeW *insertWordNodeByAlphabeticalOrder(WordNodeW *head, WordNodeW *wordNode);
WordNodeW *findWordNode(WordNodeW *head, char *wordName);
void showWordList(WordNodeW *head);
int inWordList(WordNodeW *list, char *wordName);
void freeWordList(WordNodeW *head);
int containPunctuationOrUppercase(char *word);
void convertAndRemove(char *word);
void writeResultToInvertedIndex(WordNodeW *head);

// create url
UrlNodeU *makeUrlNode(char *urlName, UrlNodeU *next)
{
    UrlNodeU *new;
    new = (UrlNodeU *)malloc(sizeof(UrlNodeU));
    assert(new != NULL);
    strcpy(new->urlName, urlName);
    new->next = next;
    return new;
}

// insert url(sorted)
UrlNodeU *insertUrlNodeByAlphabeticalOrder(UrlNodeU *head, UrlNodeU *urlNode)
{
    if (head == NULL)
    {
        urlNode->next = NULL;
        return urlNode;
    }
    // name1 < name2 : 'a' < 'b'
    if (strcmp(urlNode->urlName, head->urlName) < 0)
    {
        urlNode->next = head;
        return urlNode;
    }
    head->next = insertUrlNodeByAlphabeticalOrder(head->next, urlNode);
    return head;
}

int inUrlList(UrlNodeU *list, char *urlName)
{
    if (list == NULL)
    {
        return 0;
    }
    UrlNodeU *pu;
    for (pu = list; pu != NULL; pu = pu->next)
    {
        if (strcmp(pu->urlName, urlName) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void showUrlList(UrlNodeU *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%s", head->urlName);
    if (head->next != NULL)
    {
        printf(", ");
        showUrlList(head->next);
    }
}

void freeUrlList(UrlNodeU *head)
{
    UrlNodeU *p, *temp;
    p = head;
    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}

// create word
WordNodeW *makeWordNode(char *wordName, UrlNodeU *urlNode, WordNodeW *next)
{
    WordNodeW *new;
    new = (WordNodeW *)malloc(sizeof(WordNodeW));
    assert(new != NULL);
    strcpy(new->wordName, wordName);
    new->head = urlNode;
    new->next = next;
    return new;
}

// insert word(sorted)
WordNodeW *insertWordNodeByAlphabeticalOrder(WordNodeW *head, WordNodeW *wordNode)
{
    if (head == NULL)
    {
        wordNode->next = NULL;
        return wordNode;
    }
    // name1 < name2 : 'a' < 'b'
    if (strcmp(wordNode->wordName, head->wordName) < 0)
    {
        wordNode->next = head;
        return wordNode;
    }
    head->next = insertWordNodeByAlphabeticalOrder(head->next, wordNode);
    return head;
}

// find word
WordNodeW *findWordNode(WordNodeW *head, char *wordName)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (strcmp(head->wordName, wordName) == 0)
    {
        return head;
    }
    return findWordNode(head->next, wordName);
}

void showWordList(WordNodeW *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%s : ", head->wordName);
    showUrlList(head->head);
    printf("\n");
    if (head->next != NULL)
    {
        showWordList(head->next);
    }
}

int inWordList(WordNodeW *list, char *wordName)
{
    if (list == NULL)
    {
        return 0;
    }
    WordNodeW *pw;
    for (pw = list; pw != NULL; pw = pw->next)
    {
        if (strcmp(pw->wordName, wordName) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void freeWordList(WordNodeW *head)
{
    WordNodeW *p, *temp;
    UrlNodeU *pu;
    p = head;
    while (p != NULL)
    {
        pu = p->head;
        freeUrlList(pu);
        temp = p->next;
        free(p);
        p = temp;
    }
}

int containPunctuationOrUppercase(char *word)
{
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        // int isupper(int c) : if it is not upper, return 0; otherwise, return not 0;
        if (word[i] == DOT || word[i] == COMMA || word[i] == SEMICOLON || word[i] == QUESTIONMARK || isupper(word[i]))
        {
            return 1;
        }
    }
    return 0;
}

void convertAndRemove(char *word)
{
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        // int isupper(int c) : if it is not upper, return 0; otherwise, return not 0;
        if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        if (word[i] == DOT || word[i] == COMMA || word[i] == SEMICOLON || word[i] == QUESTIONMARK)
        {
            word[i] = '\0';
        }
    }
}

void writeResultToInvertedIndex(WordNodeW *head)
{
    if (head == NULL)
    {
        return;
    }
    FILE *fp;
    const char *fname = "InvertedIndex.txt";
    if ((fp = fopen(fname, "w+")) == NULL)
    {
        printf("Failed to open file InvertedIndex.txt.\n");
        exit(1);
    }
    
    printf("begin to write results to file.\n");
    WordNodeW *temp_w;
    UrlNodeU *temp_u;
    temp_w = head;
    while (temp_w != NULL)
    {
        temp_u = temp_w->head;
        fprintf(fp, "%s  ", temp_w->wordName);
        while (temp_u != NULL) {
            fprintf(fp, "%s ", temp_u->urlName);
            temp_u = temp_u->next;
        }
        fprintf(fp, "\n");
        temp_w = temp_w->next;
    }
    fclose(fp);
}

int main(int argc, const char *argv[])
{
    const char *fname = "collection.txt";
    char urlName[MAXURLNAME];
    char urlNameMatrix[MAXURLNUM][MAXURLNAME]; // store all urlName

    // read collection file
    FILE *collectionFile;
    if ((collectionFile = fopen(fname, "r")) == NULL)
    {
        printf("Failed to open file.\n");
        return (0);
    }
    int i, j;
    int nb_of_urls = 0;
    for (i = 0; !feof(collectionFile); i++)
    {
        // fscanf(): return the successful number of matching
        // when this function meets ' ', '\t', '\n', then it will stop
        if (fscanf(collectionFile, "%s", urlName) == 1)
        {
            strcpy(urlNameMatrix[i], urlName);
            nb_of_urls++;
        }
    }
    fclose(collectionFile);

    // define the wordNodeList:
    WordNodeW *head = NULL;

    // read url file (iteration)
    FILE *urlFile; // pointer to exact url file
    char urlFileName[MAXURLNAME];
    char urlRealName[MAXURLNAME];
    // (iteration for every file)
    for (j = 0; j < nb_of_urls; j++)
    {
        // char *strcpy(char *dest, const char *src)
        strcpy(urlFileName, urlNameMatrix[j]);
        strcpy(urlRealName, urlNameMatrix[j]);
        //        printf("%s\n", urlFileName);

        char *FileName = strcat(urlFileName, ".txt"); // urlFileName + ".txt"
        urlFile = fopen(FileName, "r");
        if (urlFile == NULL)
        {
            printf("Failed to open file.\n");
            return (0);
        }
        printf("\n%s has been accessed successfully.\n", FileName);

        // read section-2:
        int nb_words = 0; // record # of words per file
        char word_list[MAXWORDNUM][MAXWORDLENGTH];
        char word[MAXWORDLENGTH];
        char beginWord[MAXWORDLENGTH];

        // read url file
        while (!feof(urlFile))
        {
            if (fscanf(urlFile, "%s", beginWord) == 1 && strcmp(beginWord, "Section-2") == 0)
            {
                // begin to read section-2
                while (fscanf(urlFile, "%s", word) == 1)
                {
                    if (strcmp(word, "#end") == 0)
                    {
                        break;
                    }
                    strcpy(word_list[nb_words++], word);
                }
            }
        }
        // by now, all words are available on word_list[]
        for (int i = 0; i < nb_words; i++)
        {
            if (containPunctuationOrUppercase(word_list[i]))
            {
                convertAndRemove(word_list[i]);
            }
            printf("%s\n", word_list[i]);
        }

        for (int i = 0; i < nb_words; i++)
        {
            // if word exists in the list : update one more urlFileName
            if (inWordList(head, word_list[i]) == 1) // word already in the list
            {
                // 1.find the location
                // 2.check if current url is in this word's url list
                WordNodeW *locat = findWordNode(head, word_list[i]);

                // if it is not in : add this urlFileName
                if (inUrlList(locat->head, urlRealName) == 0)
                {
                    locat->head = insertUrlNodeByAlphabeticalOrder(locat->head, makeUrlNode(urlRealName, NULL));
                }
                // if it is in : do nothing to avoid duplicate

            }
            // if word does not exist : add a new word and update one more urlFileName
            else
            {
                head = insertWordNodeByAlphabeticalOrder(head, makeWordNode(word_list[i], makeUrlNode(urlRealName, NULL), NULL));
            }
        }
        fclose(urlFile);
    }
    printf("====================================\n");
    printf("index generating...\n");
    printf("====================================\n");
    showWordList(head);
    writeResultToInvertedIndex(head);

    freeWordList(head);
    return 0;
}
