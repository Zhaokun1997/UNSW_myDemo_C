
#include "list.h"
#include <ctype.h>

bool contains(List s, int value)
{
    if (s == NULL)
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
        return s;
    }
    new->next = s->head;
    s->head = new;
    return s;
}

List listSetIntersection(List s1, List s2)
{
    List s3 = newList();
    if (s1->head == NULL && s2->head == NULL)
    {
        return s3;
    } else if (s1->head == NULL && s2->head != NULL)
    {
        for (Node temp = s2->head; temp != NULL; temp = temp->next)
        {
            s3 = insertNode(s3, newNode(temp->value));
        }
        return s3;
    } else if (s1->head != NULL && s2->head == NULL)
    {
        for (Node temp = s1->head; temp != NULL; temp = temp->next)
        {
            s3 = insertNode(s3, newNode(temp->value));
        }
        return s3;
    } else
    {
        for (Node temp = s1->head; temp != NULL; temp = temp->next)
        {
            if (contains(s1, temp->value) && contains(s2, temp->value))
            {
                s3 = insertNode(s3, newNode(temp->value));
            }
        }
        return s3;
    }
}
