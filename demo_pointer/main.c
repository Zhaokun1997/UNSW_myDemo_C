//
//  main.c
//  demo_pointer
//
//  Created by Steve on 23/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>

void swap(int *, int *);
void swap(int *x, int *y)
{
    int temp;

    printf("In swap, before swapping x and y: \n");
    printf("x = %d, y = %d\n", *x, *y);

    temp = *x;
    *x = *y;
    *y = temp;

    printf("In swap, after swapping x and y: \n");
    printf("x = %d, y = %d\n", *x, *y);
}

int main(void)
{
    //     insert code here...
    /*
        int array[2][3] = {
            1, 2, 3, 4, 5, 6,
        };
        int i, j;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d    ", array[i][j]);
            }
            printf("\n");
        }
    
        printf("array = %p\n", array);                 // 数组第一块元素的地址
        printf("*array = %p\n", *(array + 0));         // 数组第一块元素里第一个元素的地址
        printf("**array = %d\n", *(*(array + 0) + 0)); // 数组第一块元素里第一个元素的内容
    
        int(*array_p1)[3] = array;
        int(*array_p2)[2][3] = &array; // (&数组第一块元素的地址)即==>整个二维数组的地址
    
        printf("array_p1 = %p\n", array_p1);
        printf("*array_p1 = %p\n", *array_p1);
        printf("**array_p1 = %d\n", **array_p1);
    
        printf("array_p2 = %p\n", array_p2);
        printf("*array_p2 = %p\n", *array_p2);
        printf("**array_p2 = %p\n", **array_p2);
        printf("***array_p2 = %d\n", ***array_p2);

        int num = 1024;
        int *pi = &num;
        char *pc = "Zhaokun.com";
        void *pv;
        pv = pi;
        printf("pi = %p, pv = %p\n", pi, pv);
        printf("*pv = %d\n", *(int *)pv);
    
    
        pv = pc;
        printf("pc = %p, pv = %p\n", pc, pv);
        printf("*pv = %s\n", pv);

        char *p[] = {
            "11111",
            "22222",
            "33333"};
    
        char **ps = &p[2];
        printf("p = %p\n", p);
        printf("p+1 = %p\n", p + 1);
    
        printf("p[0] = %p\n", p[0]);
        printf("&p[0] = %p\n", &p[0]);
        printf("p[1] = %p\n", p[1]);
        printf("&p[1] = %p\n", &p[1]);
    
        printf("*p[0] = %c\n", *p[0]);
        printf("*p[1] = %c\n", *p[1]);
    
        printf("p+2 = %p\n", p+2);
        printf("ps = %p\n", ps);
        printf("&p[2] = %p\n", &p[2]);

        int num = 520;
        const int cnum = 250;
        int *p = &num;                // 普通指针
        const int *pc = &cnum;        // 指向一个常量的普通指针(指针本身可以改变)
        int *const cp = &num;         // 指向一个变量的常量指针(指针本身不可以改变)
        const int *const cpc = &cnum; // 指向一个常量的常量指针
    
        printf("cnum = %d, &cnum = %p\n", cnum, &cnum);
        printf("*pc = %d, &cnum = %p\n", *pc, &cnum);
        printf("*cp = %d, &num = %p\n", *cp, &num);
        printf("*cpc = %d, &cnum = %p\n", *cpc, &cnum);
    
        pc = &num;
        *p = 100;
        printf("num = %d, &num = %p\n", num, &num);
        printf("*pc = %d, &num = %p\n", *pc, &num);
        printf("*p = %d, &num = %p\n", *p, &num);
 */

    int x = 3, y = 5;
    swap(&x, &y);
    
    printf("In main, before swapping x and y: \n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
