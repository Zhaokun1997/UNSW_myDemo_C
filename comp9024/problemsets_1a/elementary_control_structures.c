//
//  elementary_control_structures.c
//  problemsets_1a
//
//  Created by Steve on 8/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>

#define SIZE 10

int fibonacci(int);
void control_process(int);

int fibonacci(int n)
{
    if (n > 0)
    {
        if (n == 1)
        {
            return 1;
        } else if (n == 2)
        {
            return 2;
        } else
        {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    } else
    {
        return -1;
    }
}

void control_process(int input)
{
    printf("%d\n", input);
    if (input == 1)
    {
        return;
    }
    if ((input % 2) == 0) // even number
    {
        control_process(input/2);
    } else // ood number
    {
        control_process(3 * input + 1);
    }
}

//int main(void)
//{
//    int i;
//    for (i = 1; i <= SIZE; i++)
//    {
//        printf("Fib[%d] = %d\n", i, fibonacci(i));
//        control_process(i);
//    }
//    return 0;
//}
