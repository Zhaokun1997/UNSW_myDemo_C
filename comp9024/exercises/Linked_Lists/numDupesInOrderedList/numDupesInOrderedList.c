
#include "list.h"
#include <ctype.h>

int numDupesInOrderedList2(Node l)
{
    // TODO
    if (l == NULL || l->next == NULL)
    {
        return 0;
    } else
    {
        if (l->value == l->next->value)
        {
            return (1 + numDupesInOrderedList2(l->next));
        } else
        {
            return numDupesInOrderedList2(l->next);
        }
    }
}

int numDupesInOrderedList(List l)
{
    // TODO
    if (l->head == NULL || l->head->next == NULL)
    {
        return 0;
    } else
    {
        if (l->head->value == l->head->next->value)
        {
            return (1 + numDupesInOrderedList2(l->head->next));
        } else
        {
            return numDupesInOrderedList2(l->head->next);
        }
    }
}
