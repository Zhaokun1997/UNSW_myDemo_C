

//
//  main.c
//  structure
//
//  Created by Steve on 26/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Book
{
    char title[128];
    float price;
    struct Date date;
    struct Book *next;
};

void getInput(struct Book *);
void printBooks(struct Book *);

void getInput(struct Book *library)
{
    printf("please input the title : \n");
    scanf("%[^\n]", library->title);
    getchar();
    printf("please input the price : \n");
    scanf("%f", &library->price);
    getchar();
    printf("please input the date : \n");
    scanf("%d-%d-%d", &library->date.year, &library->date.month, &library->date.day);
    getchar();
    printf("\ninput finished.\n");
}

void printBooks(struct Book *library)
{
    printf("title : %s\n", library->title);
    printf("price : %.2f\n", library->price);
    printf("date : %d-%d-%d\n", library->date.year, library->date.month, library->date.day);
}


int main(void)
{
    // insert code here...
    struct Book b1, b2, b3;

    struct Book *library[3] = {&b1, &b2, &b3}; // 指针数组，每一个指针指向一个 book
    for (int i = 0; i < 3; i++)
    {
        getInput(library[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printBooks(library[i]);
    }
    

    return 0;
}
