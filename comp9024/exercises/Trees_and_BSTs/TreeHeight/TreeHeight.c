
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t)
{
    if (t == NULL)
    {
        return -1;
    } else if (t->left == NULL && t->right == NULL) // leaf
    {
        return 0;
    } else if (t->left == NULL && t->right != NULL) // left empty
    {
        return 1 + TreeHeight(t->right);
    } else if (t->left != NULL && t->right == NULL) // right empty
    {
        return 1 + TreeHeight(t->left);
    } else // both left and right are not empty
    {
        int lh = TreeHeight(t->left);
        int rh = TreeHeight(t->right);
        if (lh >= rh)
        {
            return 1 + lh;
        } else
        {
            return 1 + rh;
        }
    }
}
