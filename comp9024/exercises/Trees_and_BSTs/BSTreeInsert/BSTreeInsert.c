
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree BSTreeInsert(BSTree t, int val)
{
    if (t == NULL)
    {
        // allocate a new node
        BSTree new = malloc(sizeof(*new));

        if (new == NULL)
        {
            fprintf(stderr, "Insufficient memory!\n");
            exit(EXIT_FAILURE);
        }
        new->value = val;
        new->left = NULL;
        new->right = NULL;
        t = new;
    } else if (val < t->value)
    {
        t->left = BSTreeInsert(t->left, val);
    } else if (val > t->value)
    {
        t->right = BSTreeInsert(t->right, val);
    }
    return t;
}
