//
//  IntStack.c
//  problemsets_1a
//
//  Created by Steve on 8/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include "IntStack.h"
#include <assert.h>

typedef struct
{
    int item[MAXITEMS];
    int top;
} StackRep;

static StackRep IntStackObject;

void StackInit(void)
{
    IntStackObject.top = -1;
}
int StackIsEmpty(void)
{
    return (IntStackObject.top < 0);
}
void StackPush(int i)
{
    assert(IntStackObject.top < MAXITEMS - 1); // assert(test) terminates program with error message if test fails
    IntStackObject.top++;
    int index = IntStackObject.top;
    IntStackObject.item[index] = i;
}
int StackPop(void)
{
    assert(IntStackObject.top > -1);
    int popValue;
    int curr_top;
    curr_top= IntStackObject.top;
    popValue = IntStackObject.item[curr_top];
    IntStackObject.top--;
    return popValue;
}
