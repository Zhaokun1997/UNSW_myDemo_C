
#include "list.h"

int listDeleteLargest(List l)
{
    if (l->head == NULL)
    {
        return 0;
    } else if (l->head->next == NULL)
    {
        int returnValue;
        returnValue = l->head->value;
        free(l->head);
        return returnValue;
    } else
    {
        int maxValue = 0;
        for (Node temp = l->head; temp != NULL; temp = temp->next)
        {
            if (temp->value > maxValue)
            {
                maxValue = temp->value;
            }
        }
        Node prev = NULL;
        Node curr = l->head;
        while (curr->value != maxValue)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) // max value is in the first
        {
            l->head = curr->next;
            free(curr);
            return maxValue;
        }

        prev->next = curr->next;
        free(curr);
        return maxValue;
    }
}
