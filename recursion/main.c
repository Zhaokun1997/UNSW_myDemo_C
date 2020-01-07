//
//  main.c
//  recursion
//
//  Created by Steve on 25/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//void hanoi(int, char, char, char);
//
//void hanoi(int n, char x, char y, char z)  //
//{
//    if (n == 1)
//    {
//        printf("%c --> %c\n", x, z);
//    }
//    else
//    {
//        hanoi(n-1, x, z, y);
//        printf("%c --> %c\n", x, z);
//        hanoi(n-1, y, x, z);
//    }
//}

int f(int m, int n) {

   while (m != n) {
      if (m > n) {
     m = m-n;
      } else {
     n = n-m;
      }
   }
   return m;
}

int main(void)
{
    // insert code here...
    //    int n;
    //    printf("please input a number n as the scale of your hanoi : ");
    //    scanf("%d", &n);
    //
    //    hanoi(n, 'X', 'Y', 'Z');

    //    int x;
    //    printf("%p\n", &x);
    //    printf("%p\n", (&x + 1)); // + 4。
    //
    //    char s[6] = "90241";  //"hello\0"
    //    printf("%c\n", s[0]);
    //    printf("%c\n", s[2]);
    //    printf("%c\n", s[4]);
    //    printf("%c\n", s[5]);  // \0
    //    printf("%s\n", s);
    //
    //    x = atoi(s);
    //    printf("%d\n", x);
    
    
    printf("%d\n", f(30,18));
    
    return 0;
}




