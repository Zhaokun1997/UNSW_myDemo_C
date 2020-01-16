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
#include <ctype.h>
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
    char data[3][20] = {0};
    strcpy(data[0], "this ");
    strcpy(data[1], "is ");
    strcpy(data[2], "fire");

    printf("%s  %lu\n", data[0], strlen(data[0]));
    printf("%s  %lu\n", data[1], strlen(data[1]));
    printf("%s  %lu\n", data[2], strlen(data[2]));

    strcpy(data[0], "chane ");
    strcpy(data[1], "another ");
    strcpy(data[2], "string");

    printf("%s  %lu\n", data[0], strlen(data[0]));
    printf("%s  %lu\n", data[1], strlen(data[1]));
    printf("%s  %lu\n", data[2], strlen(data[2]));

    char str1[] = "This is a joke.";
    str1[3] = 'R';
    if (isupper(str1[0]))
    {
        str1[0] = tolower(str1[0]);
    }
    printf("%s\n", str1);

    printf("%f\n", (1.0+3)/7);
    

    return 0;
}
