
#include "BSTree.h"

#include <stdlib.h>

BSTree BSTreeGetSmallest(BSTree t)
{
    if (t == NULL)
    {
        return NULL;
    } else
    {
        BSTree temp = t;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
}
