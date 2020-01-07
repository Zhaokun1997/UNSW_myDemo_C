

//
//  main.c
//  link_list2
//
//  Created by Steve on 28/12/19.
//  Copyright © 2019 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

void insertNode(struct Node **head, int input);
void deleteNode(struct Node **head, int input);
void printNodes(struct Node *head);

void insertNode(struct Node **head, int input)
{
    struct Node *previous;
    struct Node *current;
    struct Node *new_node;

    new_node = (struct Node *)malloc(sizeof(struct Node *));
    if (new_node == NULL)
    {
        printf("memory allocation failed.");
        exit(1);
    }

    current = *head;
    previous = NULL;

    while (current != NULL && current->value < input)
    {
        previous = current;
        current = current->next;
    }

    new_node->value = input;
    if (previous == NULL)
    {
        *head = new_node;
        new_node->next = current;
    } else
    {
        new_node->next = current;
        previous->next = new_node;
    }

    // 空间申请
    //    struct Node *new_node;
    //    new_node = (struct Node *)malloc(sizeof(struct Node *));
    //    if (new_node == NULL)
    //    {
    //        printf("memory allocation failed.");
    //        exit(1);
    //    }
    //    new_node->value = input;
    //
    //    if (*head == NULL) // 空链表时
    //    {
    //        *head = new_node;
    //        new_node->next = NULL;
    //    } else // 链表中 有元素时
    //    {
    //        struct Node *temp = *head;
    //        struct Node *temp_next = temp->next;
    //        if (temp->value > input) // temp->value > value : 头插法
    //        {
    //            *head = new_node;
    //            new_node->next = temp;
    //        } else // 尾插法
    //        {
    //            if (temp_next == NULL)
    //            {
    //                temp->next = new_node;
    //                new_node->next = temp_next;
    //            } else
    //            {
    //                while (!((temp->value <= input && temp_next == NULL) || (temp->value <= input && temp_next->value >= input)))
    //                {
    //                    temp = temp_next;
    //                    temp_next = temp_next->next;
    //                }
    //                temp->next = new_node;
    //                new_node->next = temp_next;
    //            }
    //        }
    //    }
}

void deleteNode(struct Node **head, int input)
{
    struct Node *previous;
    struct Node *current;

    current = *head;
    previous = NULL;

    while (current != NULL && current->value != input)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("cannot find corresponding node.\n");
        return;
    } else
    {
        if (previous == NULL) // 删除的那个节点如果是第一个节点
        {
            *head = current->next;
        } else
        {
            previous->next = current->next;
        }
        free(current);
    }
}

void printNodes(struct Node *head)
{
    printf("here is the link_list : \n");
    struct Node *node;
    node = head;

    while (node != NULL)
    {
        printf("%d  ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    struct Node *head = NULL;
    int input;

    while (1)
    {
        printf("please input an node that you want to insert.(input -1 means end)\n");
        scanf("%d[^\n]", &input);
        if (input == -1)
        {
            break;
        }
        insertNode(&head, input);
        printNodes(head);
    }

    while (1)
    {
        printf("please input an node that you want to delete.(input -1 means end)\n");
        scanf("%d[^\n]", &input);
        if (input == -1)
        {
            break;
        }
        deleteNode(&head, input);
        printNodes(head);
    }
    

    return 0;
}

