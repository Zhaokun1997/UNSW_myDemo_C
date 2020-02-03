
#include <stdlib.h>

#include "BSTree.h"

int BSTreeNodeDepth(BSTree t, int key)
{
    if (t == NULL)
    {
        return -1;
    } else
    {
        if (key > t->value)
        {
            int temp_depth = BSTreeNodeDepth(t->right, key);
            if (temp_depth == -1)
            {
                return -1;
            } else
            {
                return 1 + BSTreeNodeDepth(t->right, key);
            }
        } else if (key < t->value)
        {
            int temp_depth = BSTreeNodeDepth(t->left, key);
            if (temp_depth == -1)
            {
                return -1;
            } else
            {
                return 1 + BSTreeNodeDepth(t->left, key);
            }
        } else // key == t->value
        {
            return 0;
        }
    }
}
