//
//  subsetsum.c
//  week2_programs
//
//  Created by Steve on 9/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

// Test subset sum ... COMP9024 19T3

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXNUMS 30

bool subsetsum(int[], int, int);

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("i is %d, argv[%d] is %s \n", i, i, argv[i]);
    }
    int n = 0;      // count of numbers
    int A[MAXNUMS]; // actual numbers
    int v;          // last number read
    int k;          // sum being checked for

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s k < file\n", argv[0]);
    } else
    {
        k = atoi(argv[1]); // get target sum k
        while (scanf("%d", &v) == 1)  // return : the successful number of read from std input
        { // read numbers
            printf("%d\n", v);
            A[n++] = v;
        }

        if (subsetsum(A, n, k))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

bool subsetsum(int A[], int n, int k)
{
    if (k == 0)
        return true; // empty set solves this
    else if (n == 0)
        return false; // no elements => no sums
    else
    {
        int m = A[n - 1];
        return (subsetsum(A, n - 1, k - m) || subsetsum(A, n - 1, k));
    }
}
