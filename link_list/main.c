//
//  main.c
//  link_list
//
//  Created by Steve on 26/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <String.h>

// 链表结构
struct Book
{
    char title[128];
    char author[40];
    struct Book *next;
};

void getInput(struct Book *book);
void addBooksFromHead(struct Book **Library);
void addBooksFromTail(struct Book **Library);
struct Book *searchBook(struct Book *Library, char *target);
void printBook(struct Book *book);
void printLibrary(struct Book *Library);
void releaseLibrary(struct Book *Library);

void getInput(struct Book *book)
{
    printf("please input the title : \n");
    scanf("%[^\n]", book->title);
    getchar();
    printf("please input the author : \n");
    scanf("%[^\n]", book->author);
    getchar();
    printf("input finished.\n");
}

void printLibrary(struct Book *Library)
{
    struct Book *book;
    book = Library;
    int count = 1;
    while (book != NULL)
    {
        printf("Book %d == ", count);
        printf("title : %s, author : %s", book->title, book->author);
        printf("\n");
        book = book->next;
        count++;
    }
}

void printBook(struct Book *book)
{
    if (book)
    {
        printf("the searched book is : title : %s, author : %s\n", book->title, book->author);

    } else
    {
        printf("the searched book not found.\n");
    }
}

void releaseLibrary(struct Book *Library)
{
    struct Book *last;
    while (Library != NULL)
    {
        last = Library;
        Library = Library->next;
        free(last);
    }
}

void addBooksFromHead(struct Book **Library)
{
    struct Book *newbook;
    struct Book *temp;
    // 申请空间
    newbook = (struct Book *)malloc(sizeof(struct Book));
    if (newbook == NULL)
    {
        printf("memory allocation failed.\n");
        exit(1);
    }

    getInput(newbook);
    temp = *Library;
    *Library = newbook;
    newbook->next = temp;
}

void addBooksFromTail(struct Book **Library)
{
    struct Book *newbook;

    newbook = (struct Book *)malloc(sizeof(struct Book));
    if (newbook == NULL)
    {
        printf("memory allocation failed.\n");
        exit(1);
    }
    getInput(newbook);

    //    // 不添加尾指针的时候插入
    //    struct Book *temp;
    //    if (*Library == NULL)
    //    {
    //        *Library = newbook;
    //        newbook->next = NULL;
    //    } else
    //    {
    //        temp = *Library;
    //        while (temp->next != NULL)
    //        {
    //            temp = temp->next;
    //        }
    //        temp->next = newbook;
    //        newbook->next = NULL;
    //    }

    // 添加尾指针时候的插入
    static struct Book *tail; // 静态指针变量
    if (*Library == NULL)
    {
        *Library = newbook;
        newbook->next = NULL;
    } else
    {
        tail->next = newbook;
        newbook->next = NULL;
    }
    tail = newbook;
}

struct Book *searchBook(struct Book *Library, char *target)
{
    struct Book *book = NULL;
    book = Library;
    while (book != NULL)
    {
        if (!strcmp(book->title, target) || !strcmp(book->author, target)) // strcmp(A,B): A == B 返回 0
        {
            break;
        }
        book = book->next;
    }
    if (book != NULL)
    {
        return book;
    } else
    {
        return book;
    }
}

int main(void)
{
    // 链表插入元素:头插法
    struct Book *Library = NULL;
    struct Book *book;
    char input[128];
    int nb_books = 3;
    int i;
    //    for (i = 0; i < nb_books; i++)
    //    {
    //        addBooksFromHead(&Library);
    //    }
    for (i = 0; i < nb_books; i++)
    {
        addBooksFromTail(&Library);
    }

    printLibrary(Library);   // 打印所有书
    
    printf("please input the book that you want to search : \n");
    scanf("%s", input);
    book = searchBook(Library, input);
    
    printBook(book);
    releaseLibrary(Library); // 释放空间
    
    

    return 0;
}

