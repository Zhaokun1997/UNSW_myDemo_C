//
//  Stack.c
//  comp9024
//
//  Created by Steve on 7/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include "Stack.h"
#include <assert.h>

typedef struct
{
    char item[MAXITEMS];
    int top;
} stackRep;

static stackRep stackObject;

void StackInit(void)
{
    stackObject.top = -1;
}

int StackIsEmpty(void)
{
    return (stackObject.top < 0);
}

void StackPush(char ch)
{
    assert(stackObject.top < MAXITEMS - 1);
    stackObject.top++;
    stackObject.item[stackObject.top] = ch;
}

char StackPop(void)
{
    assert(stackObject.top > -1);
    char popValue = stackObject.item[stackObject.top];
    stackObject.top--;
    return popValue;
}
