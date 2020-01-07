

//
//  brackets.c
//  week1_programs
//
//  Created by Steve on 7/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

#define OPENA '{'
#define OPENB '['
#define OPENC '('
#define CLOSA '}'
#define CLOSB ']'
#define CLOSC ')'



int main(void)
{
    
    char ch;
    char openning;
    int mismatch = 0;
    StackInit();
    
    
    while ((ch = getchar()) != '\n' && !mismatch)
    {
        if (ch == OPENA || ch == OPENB || ch == OPENC)
        {
            StackPush(ch);
        } else if (ch == CLOSA || ch == CLOSB || ch == CLOSC)
        {
            if (StackIsEmpty())
            {
                mismatch = 1;
            } else
            {
                openning = StackPop();
                if (!((openning == OPENA && ch == CLOSA) || (openning == OPENB && ch == CLOSB) || (openning == OPENC && ch == CLOSC)))
                {
                    mismatch = 1;
                }
            }
        }
    }
    

    if (mismatch || (!StackIsEmpty()))
    {
        printf("it is unsatisfied!\n");
    } else
    {
        printf("it is balanced!\n");
    }
    
    
    return 0;
}

