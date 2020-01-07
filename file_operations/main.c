//
//  main.c
//  file_operations
//
//  Created by Steve on 31/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1024

int main(void)
{
    //    FILE *fp;
    //    char buffer[MAX];
    //
    //    if ((fp = fopen("lines.txt", "w")) == NULL)
    //    {
    //        printf("failed to open file!\n");
    //        exit(EXIT_FAILURE);
    //    }
    //
    //    fputs("Line 1 : Hello World!\n", fp);
    //    fputs("Line 2 : Hello FishC!\n", fp);
    //    fputs("Line 3 : Hello Zhaokun!\n", fp);
    //
    //    fclose(fp);
    //
    //    if ((fp = fopen("lines.txt", "r")) == NULL)
    //    {
    //        printf("failed to open file!\n");
    //        exit(EXIT_FAILURE);
    //    }
    //
    //    while (!feof(fp))  // feof() 返回 0, 表示还没有到文件末尾
    //    {
    //        fgets(buffer, MAX, fp);
    //        printf("%s", buffer);
    //
    //    }
    FILE *fp;
    struct tm *p;
    time_t t;

    time(&t);
    p = localtime(&t);
    
    // write file
    if ((fp = fopen("date.txt", "w")) == NULL)
    {
        printf("failed to open file!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d-%d-%d", 1990 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    fclose(fp);
    
    // read file
    int year, month, day;
    if ((fp = fopen("date.txt", "r")) == NULL)
    {
        printf("failed to open file!\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d-%d-%d", &year, &month, &day);
    // print
    printf("%d-%d-%d", year, month, day);
    fclose(fp);
    
    

    return 0;
}
