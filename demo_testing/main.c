//
//  main.c
//  demo_testing
//
//  Created by Steve on 6/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 6

int main(int argc, const char *argv[])
{
    //    int a = 1;
    //    int b = 5;
    //    while (a < b)
    //    {
    //        a++;
    //        b--;
    //    }
    //    printf("a = %d, b = %d\n", a, b);
    //    printf("%8.2f\n", 3.14159);
    //
    //    char str[BUFSIZ];
    //    char mystr[] = "mars";
    //    if (strcmp(mystr, argv[1])==0)
    //    {
    //        printf("matched!\n");
    //    }
    //    else
    //    {
    //        printf("%s\n", mystr);
    //        printf("%s\n", argv[1]);
    //        printf("error!\n");
    //    }

    //    char name[30];
    //    strcpy(name, "mars");
    //    int len = strlen(name);
    //    printf("%d\n", len);
    //    printf("%s\n", name);
    char *word1 = NULL;
    char *word2 = NULL;
    char *word3 = NULL;
    int a;
    float b;
    char str1[30] = "url31  4  0.1945805";
    char delim[2] = ", ";
    word1 = strtok(str1, delim);
    word2 = strtok(NULL, delim);
    word3 = strtok(NULL, delim);
    a = atoi(word2);
    b = atof(word3);
    printf("str1 = %s\n", str1);
    printf("%s%d%f\n", word1, a, b);
    
    char s = 'w';
    if (s == '\n') {
        printf("success!\n");
    }
    return 0;
}
