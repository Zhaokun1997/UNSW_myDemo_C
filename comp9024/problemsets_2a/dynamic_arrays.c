//
//  dynamic_arrays.c
//  problemsets_2a
//
//  Created by Steve on 18/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//int main(int argc, const char *argv[])
//{
//    if (argc != 2)
//    {
//        fprintf(stderr, "Usage: %s number\n", argv[0]);
//        return (1);
//    }
//    int n = atoi(argv[1]);
//    if (n > 0)
//    {
//        unsigned long long int *arr = malloc(n * sizeof(unsigned long long int));
//        assert(arr != NULL);
//        arr[0] = 1;
//        arr[1] = 1;
//        int i;
//        for (i = 2; i < n; i++)
//        {
//            arr[i] = arr[i - 1] + arr[i - 2];
//        }
//        printf("%llu\n", arr[n - 1]);
//        free(arr);
//    }
//
//    return 0;
//}
