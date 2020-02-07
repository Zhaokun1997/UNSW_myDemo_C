
#include <stdlib.h>

#include "tree.h"

int TreeSumOdds(Tree t)
{
    if (t == NULL)
    {
        return 0;
    } else if (t->left == NULL && t->right == NULL)
    {
        if ((t->value % 2) == 0) // node is even
        {
            return 0;
        } else // node is odd
        {
            return t->value;
        }

    } else
    {
        int sumleft = TreeSumOdds(t->left);
        int sumright = TreeSumOdds(t->right);
        if ((t->value % 2) == 0) // node is even
        {
            return sumleft + sumright;
        } else // node is odd
        {
            return t->value + sumleft + sumright;
        }
    }
}
