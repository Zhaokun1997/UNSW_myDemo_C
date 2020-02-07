//
// Created by Rui.Mu on 2019-01-30.
//

#include "Tree.h"

// tree node
struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};

/**
 * insert value to tree
 * @param tree tree structure
 * @param val value
 * @return tree node
 */
Tree insertAVLTree(Tree tree, int val)
{
    // check tree is null
    if (tree == NULL)
    {
        // create new node
        tree = newNode(val);
    } else
    {
        // equal 0
        if (val != data(tree))
        {
            // check result
            if (val < data(tree))
            {
                // if val less than current data
                left(tree) = insertTree(left(tree), val);
            } else if (val > data(tree))
            {
                // if val more than current data
                right(tree) = insertTree(right(tree), val);
            }

            // left height
            int leftHeight = heightTree(left(tree));
            int rightHeight = heightTree(right(tree));
            // check left height more than right height
            if (leftHeight - rightHeight > 1)
            {
                //          20
                //      15      25
                //   10
                //      insert 12
                // compare current node
                if (val > data(left(tree)))
                {
                    left(tree) = rotateLeft(left(tree));
                }

                // rotate right
                tree = rotateRight(tree);
            } else if (rightHeight - leftHeight > 1)
            {
                //          20
                //       15     25
                //             22
                //      insert 21
                // compare current and right
                if (val < data(right(tree)))
                {
                    right(tree) = rotateRight(right(tree));
                }
                // rotate right
                tree = rotateLeft(tree);
            }
        }
    }
    // return pointer of tree
    return tree;
}

/**
 * check number of nodes in a tree is balanced
 * @param tree
 * @return
 */
bool isBalancedByNumberOfNodes(Tree tree)
{
    // if tree is null, then true
    bool result = (tree == NULL);
    if (!result)
    {
        // check left and right and current node
        result = isBalancedByNumberOfNodes(left(tree)) && isBalancedByNumberOfNodes(right(tree)) && abs(countNodes(left(tree)) - countNodes(right(tree))) < 2;

        printf("tree node is: %d, check result is: %d\n", data(tree), result);
    }
    // return result
    return result;
}

/**
 * show tree right
 * @param t tree
 * @param depth depth
 */
void showTreeR(Tree t, int depth)
{
    if (t != NULL)
    {
        // show tree R
        showTreeR(right(t), depth + 1);
        for (int i = 0; i < depth; i++)
            putchar('\t'); // TAB character
        printf("%d\n", data(t));
        showTreeR(left(t), depth + 1);
    }
}

/**
 * show tree
 * @param t tree
 */
void showTree(Tree t)
{
    showTreeR(t, 0);
}
