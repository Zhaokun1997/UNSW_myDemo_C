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

void StackInit()
{
    stackObject.top = -1;
}

int StackIsEmpty()
{
    return (stackObject.top < 0);
}

void StackPush(char ch)
{
    assert(stackObject.top < MAXITEMS - 1);
    stackObject.top++;
    int i;
    i = stackObject.top;
    stackObject.item[i] = ch;
}

char StackPop()
{
    assert(stackObject.top > -1);
    int i;
    char ch;
    i = stackObject.top;
    ch = stackObject.item[i];
    stackObject.top--;
    return ch;
}
