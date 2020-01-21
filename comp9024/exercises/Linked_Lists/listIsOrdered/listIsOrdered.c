
#include "list.h"
#include <ctype.h>

bool listIsIncreasedOrder(Node l)
{
    // increasing order
    if (l == NULL)
    {
        return true;
    } else
    {
        if (l->next == NULL)
        {
            return true;
        } else
        {
            if (l->value <= l->next->value)
            {
                Node new;
                new = l->next;
                return listIsIncreasedOrder(new);
            }
        }
    }
    return false;
}

bool listIsDecreasedOrder(Node l)
{
    // increasing order
    if (l == NULL)
    {
        return true;
    } else
    {
        if (l->next == NULL)
        {
            return true;
        } else
        {
            if (l->value >= l->next->value)
            {
                Node new;
                new = l->next;
                return listIsDecreasedOrder(new);
            }
        }
    }
    return false;
}

bool listIsOrdered(List l)
{
    return (listIsIncreasedOrder(l->head) || listIsDecreasedOrder(l->head));
}
