
#include "list.h"

void reverseDLList(List l)
{
    if (l->size == 0 || l->size == 1)
    {
        return;
    }
    // TODO
    Node prev = NULL;
    Node curr = l->first;
    Node temp;
    temp = l->first;
    l->first = l->last;
    l->last = temp;
    while (curr != NULL)
    {
        Node curr_next = curr->next;
        curr->prev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr_next;
    }
}
