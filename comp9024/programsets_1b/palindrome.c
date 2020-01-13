//
//  palindrome.c
//  programsets_1b
//
//  Created by Steve on 8/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int isPalindrome(char *);

int isPalindrome(char str[])
{
    int length = (int)strlen(str);
    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(void)
{
    char str[BUFSIZ];
    printf("Enter a word : ");
    scanf("%s", str);

    if (isPalindrome(str))
    {
        printf("yes\n");
    } else
    {
        printf("no\n");
    }

    return 0;
}
