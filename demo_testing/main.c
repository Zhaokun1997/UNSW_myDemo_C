//
//  main.c
//  demo_testing
//
//  Created by Steve on 6/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#define SIZE 6

int main(void)
{
    int a = 1;
    int b = 5;
    while (a < b)
    {
        a++;
        b--;
    }
    printf("a = %d, b = %d\n", a, b);
    printf("%8.2f\n", 3.14159);
    
    char str[BUFSIZ];
    
    return 0;
}
