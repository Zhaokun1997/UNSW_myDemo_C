
#include <stdlib.h>

#include "tree.h"

int getTreeSize(Tree t)
{
    if (t == NULL)
    {
        return 0;
    } else if (t->left == NULL && t->right == NULL)
    {
        return 1;
    } else
    {
        int leftSize = getTreeSize(t->left);
        int rightSize = getTreeSize(t->right);
        return 1 + leftSize + rightSize;
    }
}

bool TreeIsPerfectlyBalanced(Tree t)
{
    if (t == NULL)
    {
        return true;
    } else if (t->left == NULL && t->right == NULL)
    {
        return true;
    } else
    {
        // test leftTree and rightTree in order to test for every node
        bool leftBalanced = TreeIsPerfectlyBalanced(t->left);
        bool rightBalanced = TreeIsPerfectlyBalanced(t->right);
        if (!leftBalanced || !rightBalanced)
        {
            return false;
        }

        // test process
        int leftSize = getTreeSize(t->left);
        int rightSize = getTreeSize(t->right);
        int diff = abs(leftSize - rightSize);
        if (diff >= 2)
        {
            return false;
        } else
        {
            return true;
        }
    }
}
