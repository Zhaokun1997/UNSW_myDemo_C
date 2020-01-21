//
//  llsplit.c
//  problemsets_2a
//
//  Created by Steve on 18/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
    int data;
    struct Node *next;
} NodeT;


NodeT *makeNode(int value);
NodeT *joinLL(NodeT *list1, NodeT *list2);
void freeLL(NodeT *list);
void showLL(NodeT *list);
NodeT *splitLL(NodeT *list);


NodeT *makeNode(int value)
{
    NodeT *new;
    new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->data = value;
    new->next = NULL;

    return new;
}

NodeT *joinLL(NodeT *list1, NodeT *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    // recursively append
    list1->next = joinLL(list1->next, list2);
    return list1;
}

NodeT *splitLL(NodeT *list)
{
    assert(list!=NULL);
    NodeT *slow, *fast;
    slow = list;
    fast = list->next;
    
    while (fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    return fast;
}

void freeLL(NodeT *list)
{
    NodeT *p = list;
    while (p != NULL)
    {
        NodeT *temp = p->next;
        free(p);
        p = temp;
    }
}

void showLL(NodeT *list)
{
    if (list == NULL)
    {
        return;
    }
    printf("%d", list->data);
    if (list->next != NULL)
    {
        printf(", ");
        showLL(list->next);
    }
}

//int main(void)
//{
//    NodeT *all = NULL;
//    int data;
//    printf("Enter an integer: ");
//    while (scanf("%d", &data) == 1)
//    {
//        NodeT *new = makeNode(data);
//        all = joinLL(all, new);
//        printf("Enter an integer: ");
//    }
//    if (all != NULL)
//    {
//        printf("Done. List is: ");
//        showLL(all);
//        printf("\n");
//        NodeT *sec = NULL;
//        sec = splitLL(all);
//        printf("first part is: ");
//        showLL(all);
//        printf("\n");
//        printf("second part is: ");
//        showLL(sec);
//        printf("\n");
//        freeLL(all);
//    } else
//    {
//        printf("Done.\n");
//    }
//
//    return 0;
//}

