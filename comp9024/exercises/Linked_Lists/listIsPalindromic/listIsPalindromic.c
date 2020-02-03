
#include "list.h"
#include <ctype.h>

bool listIsPalindromic(List l)
{
    if (l->size == 0)
    {
        return true;
    } else
    {
        Node first = l->first;
        Node last = l->last;
        while (first != NULL && last != NULL)
        {
            if (first->value != last->value)
            {
                return false;
            }

            first = first->next;
            last = last->prev;
        }
        return true;
    }
}
