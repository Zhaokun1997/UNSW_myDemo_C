
#include "list.h"
#include <ctype.h>

bool contains(List s, int value)
{
    if (s->head == NULL)
    {
        return false;
    } else
    {
        for (Node temp = s->head; temp != NULL; temp = temp->next)
        {
            if (temp->value == value)
            {
                return true;
            }
        }
        return false;
    }
}

List insertNode(List s, Node new)
{
    if (s->head == NULL)
    {
        s->head = new;
    } else
    {
        new->next = s->head;
        s->head = new;
    }
    return s;
}

List listSetUnion(List s1, List s2)
{
    if (s1->head == NULL && s2->head == NULL)
    {
        List s3 = newList();
        return s3;
    } else if (s1->head == NULL && s2->head != NULL)
    {
        List s3 = newList();
        for (Node temp2 = s2->head; temp2 != NULL; temp2 = temp2->next)
        {
            s3 = insertNode(s3, newNode(temp2->value));
        }
        return s3;
    } else if (s1->head != NULL && s2->head == NULL)
    {
        List s3 = newList();
        for (Node temp1 = s1->head; temp1 != NULL; temp1 = temp1->next)
        {
            s3 = insertNode(s3, newNode(temp1->value));
        }
        return s3;
    } else
    {
        List s3 = newList();
        Node temp1 = s1->head;
        Node temp2 = s2->head;
        while (temp1 != NULL)
        {
            if (!contains(s3, temp1->value))
            {
                s3 = insertNode(s3, newNode(temp1->value));
            }
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            if (!contains(s3, temp2->value))
            {
                s3 = insertNode(s3, newNode(temp2->value));
            }
            temp2 = temp2->next;
        }

        return s3;
    }
}
