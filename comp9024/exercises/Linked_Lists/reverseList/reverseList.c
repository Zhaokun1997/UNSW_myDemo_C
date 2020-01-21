
#include "list.h"

void listReverse(List l)
{
    // TODO
    if (l->head == NULL || l->head == NULL)
    {
        // do nothing
        return;
    } else
    {
        Node prev = NULL;
        Node curr = l->head;
        while (curr != NULL)
        {
            Node curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        l->head = prev;
    }
}
