//
//  main.c
//  typedef
//
//  Created by Steve on 28/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>

typedef int (*PTR_TO_ARRAY)[3];     // 定义数组指针
typedef int (*PTR_TO_FUN)(void);    // 定义函数指针
typedef int *(*PTR_TO_FUN_2)(int); // 定义指向函数指针的指针
typedef int (*PTR_TO_FUN_3)(int, int); // 定义指向函数的指针

int makefun(void);
int funA(int num);
int funB(int num);
int funC(int num);
PTR_TO_FUN_3 selecting(char);

int makefun(void)
{
    return 520;
}

int funA(int num)
{
    return num * 1;
}

int funB(int num)
{
    return num * 2;
}

int funC(int num)
{
    return num * 3;
}

PTR_TO_FUN_3 selecting(char c)
{
    
    return makefun;
}

int main(void)
{
//    // part1
//    int array[3] = {1, 2, 3};
//    PTR_TO_ARRAY ptr_to_array = &array;
//
//    int i;
//    for (i = 0; i < 3; i++)
//    {
//        printf("%d\n", (*ptr_to_array)[i]);
//    }
//
//    // part2
//    PTR_TO_FUN ptr_to_fun = &makefun;
//    printf("%d\n", (*ptr_to_fun)());
//
//    // part3
//    PTR_TO_FUN_2 fun_array[3] = {
//        funA, funB, funC}; // & 可加可不加
//    for (i = 0; i < 3; i++)
//    {
//        printf("address of functions : %p\n", *(fun_array + i));
//    }
    int mask = 0xFF;
    int v3 = 0x12;
    int result;

    result = v3 ^ mask;
    
    printf("v3 = 0x%X\n",result);
    
    
    
    

    return 0;
}
