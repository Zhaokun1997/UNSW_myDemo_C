

//
//  main.c
//  UNSW_myDemo_C
//
//  Created by Steve on 18/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>
#include <String.h>

#define FIRST_NAME "ZHAOKUN"
#define LAST_NAME "SU"

// it can have no arguments names in the declaration.
int add(int, int);
int sub(int, int);
int calculate(int (*)(int, int), int, int); // 第一个参数是一个指向函数的指针
int (*selecting(char))(int, int);  // 声明一个selecting函数，此函数的返回值是一个指向函数的指针

int add(int num1, int num2)
{
    return num1 + num2;
}

int sub(int num1, int num2)
{
    return num1 - num2;
}


int calculate(int (*fp)(int, int), int num1, int num2)
{
    return (*fp)(num1, num2);
}

int (*selecting(char c))(int, int)
{
    switch (c)
    {
        case '+':
            return add;  // 返回add()函数的地址(或返回add()函数的指针)
        case '-':
            return sub;
        default:
            return add;
    }
}

int main(void)
{
    // insert code here...
    int oprd1, oprd2;
    char op;
    int (*fp)(int, int); // 声明一个函数指针 fp
    
    
    printf("please input an expression : for instance : (1+3)\n");
    scanf("%d %c %d", &oprd1, &op, &oprd2);
    
    fp = selecting(op);
    printf("%d %c %d = %d\n", oprd1, op, oprd2, (*fp)(oprd1, oprd2));
    

    return 0;
}
