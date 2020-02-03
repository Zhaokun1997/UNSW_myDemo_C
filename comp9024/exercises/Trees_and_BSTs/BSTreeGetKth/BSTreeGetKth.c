
#include <stdlib.h>

#include "BSTree.h"

int nb_of_Nodes(BSTree t)
{
    if (t == NULL)
    {
        return 0;
    } else if (t->left == NULL && t->right == NULL)
    {
        return 1;
    } else
    {
        int nb_left = nb_of_Nodes(t->left);
        int nb_right = nb_of_Nodes(t->right);
        return 1 + nb_left + nb_right;
    }
}

int BSTreeGetKth(BSTree t, int k)
{
    if (t == NULL)
    {
        return -1;
    } else
    {
        int nb_left = nb_of_Nodes(t->left);
        if (k < nb_left)
        {
            return BSTreeGetKth(t->left, k);
        } else if (k > nb_left)
        {
            return BSTreeGetKth(t->right, k - nb_left - 1);
        } else // k == nb_left
        {
            return t->value;
        }
    }
}
