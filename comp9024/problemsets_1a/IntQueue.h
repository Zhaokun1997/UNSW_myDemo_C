//
//  IntQueue.h
//  problemsets_1a
//
//  Created by Steve on 8/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#ifndef IntQueue_h
#define IntQueue_h

#include <stdio.h>

#define MAXITEMS 10

void QueueInit(void);       // set up empty queue
int QueueIsEmpty(void);     // check whether queue is empty
void QueueEnqueue(int); // insert int at end of queue
int QueueDequeue(void);     // remove int from front of queue

#endif /* IntQueue_h */
