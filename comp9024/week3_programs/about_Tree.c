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
 * create new node
 * @return
 */
Tree newTree(void)
{
    return NULL;
}

/**
 * create new node
 * @param val value
 * @return create new node
 */
Tree newNode(int val)
{
    // apply memories
    Tree tree = malloc(sizeof(struct TreeNode));
    assert(tree != NULL);
    // copy data to tree
    data(tree) = val;
    // set left and right
    left(tree) = right(tree) = NULL;
    // return new tree
    return tree;
}

Tree insertTree(Tree t, int key)
{
    if (t == NULL)
    {
        Tree new = newNode(key);
        t = new;
    } else
    {
        if (key < t->data)
        {
            t->left = insertTree(t->left, key);
        } else if (key > t->data)
        {
            t->right = insertTree(t->right, key);
        } else
        {
            // do nothing
        }
    }
    return t;
}

/**
 * insert val at root
 * @return
 */
Tree insertAtRoot(Tree t, int key)
{
    if (t == NULL)
    {
        t = newNode(key);
    } else if (key < t->data)
    {
        t->left = insertAtRoot(t->left, key);
        t = rotateRight(t);
    } else if (key > t->data)
    {
        t->right = insertAtRoot(t->right, key);
        t = rotateLeft(t);
    } else
    {
        // do nothing
    }

    return t;
}

/**
 * insert value to AVL tree
 * @return tree node
 */
Tree insertAVLTree(Tree t, int key)
{
    if (t == NULL)
    {
        t = newNode(key);
        return t;
    } else if (key == t->data)
    {
        return t;
    } else
    {
        if (key < t->data)
        {
            t->left = insertAVLTree(t->left, key);
        } else if (key > t->data)
        {
            t->right = insertAVLTree(t->right, key);
        }

        // begin check
        int leftHeight = heightTree(t->left);
        int rightHeight = heightTree(t->right);
        if (leftHeight - rightHeight > 1)
        {
            if (key > t->left->data)
            {
                t->left = rotateLeft(t->left);
                t = rotateRight(t);
            } else
            {
                t = rotateRight(t);
            }
        } else if (rightHeight - leftHeight > 1)
        {
            if (key < t->right->data)
            {
                t->right = rotateRight(t->right);
                t = rotateLeft(t);
            } else
            {
                t = rotateLeft(t);
            }
        }
        return t;
    }
}

/**
 * insert value to Splay tree
 * @return
 */
Tree insertSplayTree(Tree t, int key)
{
    if (t == NULL)
    {
        t = newNode(key);
    } else if (key < t->data)
    {
        // get left tree
        Tree leftT = t->left;
        if (leftT == NULL)
        {
            t->left = newNode(key);
        } else if (key < leftT->data) // case 1: left left
        {
            leftT->left = insertSplayTree(leftT->left, key);
            t = rotateRight(t);
        } else if (key > leftT->data) // case 2: left right
        {
            leftT->right = insertSplayTree(leftT->right, key);
            t->left = rotateLeft(t->left);
        }
        t = rotateRight(t);
    } else if (key > t->data)
    {
        // get right tree
        Tree rightT = t->right;
        if (rightT == NULL)
        {
            t->right = newNode(key);
        } else if (key < rightT->data) // case 3: right left
        {
            rightT->left = insertSplayTree(rightT->left, key);
            t->right = rotateRight(t->right);
        } else if (key > rightT->data) // case 4: right tight
        {
            rightT->right = insertSplayTree(rightT->right, key);
            t = rotateLeft(t);
        }
        t = rotateLeft(t);
    }
    return t;
}

/**
 * delete val from tree
 * @return delete tree
 */
Tree deleteTree(Tree t, int key)
{
    if (t == NULL)
    {
        return NULL;
    } else if (t->data > key)
    {
        t->left = deleteTree(t->left, key);
    } else if (t->data < key)
    {
        t->right = deleteTree(t->right, key);
    } else // t->date == key
    {
        Tree new = NULL;
        if (t->left == NULL && t->right == NULL)
        {
            free(t);
            t = new;
        } else if (t->left == NULL && t->right != NULL)
        {
            new = t->right;
            free(t);
        } else if (t->left != NULL && t->right == NULL)
        {
            new = t->left;
            free(t);
        } else
        {
            new = joinTrees(t->left, t->right);
            free(t);
        }
        return new;
    }
}

/**
 * get height of tree
 * @return height
 */
int heightTree(Tree t)
{
    if (t == NULL)
    {
        return -1;
    } else if (t->left == NULL && t->right == NULL)
    {
        return 0;
    } else
    {
        int left_height = heightTree(t->left);
        int right_height = heightTree(t->right);
        if (left_height > right_height)
        {
            return left_height + 1;
        } else
        {
            return right_height + 1;
        }
    }
}

/**
 * get number of tree nodes
 * @return number of tree nodes
 */
int countNodes(Tree t)
{
    if (t == NULL)
    {
        return 0;
    } else if (t->left == NULL && t->right == NULL)
    {
        return 1;
    } else
    {
        return 1 + countNodes(t->left) + countNodes(t->right);
    }
}

/**
 * get number of tree leaves
 * @return
 */
int countLeaf(Tree t)
{
    if (t == NULL)
    {
        return 0;
    } else if (t->left == NULL && t->right == NULL)
    {
        return 1;
    } else
    {
        return countLeaf(t->left) + countLeaf(t->right);
    }
}

/**
 * get number of tree odd nodes
 * @return
 */
int countOdds(Tree t)
{
    if (t == NULL)
    {
        return 0;
    } else if (t->left == NULL && t->right == NULL)
    {
        return (t->data % 2 == 1);
    } else
    {
        int leftOdds = countOdds(t->left);
        int rightOdds = countOdds(t->right);
        return (t->data % 2 == 1) + leftOdds + rightOdds;
    }
}

/**
 * count odder level nodes
 * @return count
 */

int countEvenerLevelNodesByLevel(Tree t, int level)
{
    if (t == NULL)
    {
        return 0;
    } else
    {
        int result = 0;
        result = (level % 2 == 0) + countOdderLevelNodesByLevel(t->left, level - 1) + countOdderLevelNodesByLevel(t->right, level - 1);
        return result;
    }
}

int countOdderLevelNodesByLevel(Tree t, int level)
{
    if (t == NULL)
    {
        return 0;
    } else
    {
        int result = 0;
        result = (level % 2) + countOdderLevelNodesByLevel(t->left, level - 1) + countOdderLevelNodesByLevel(t->right, level - 1);
        return result;
    }
}

int countOdderLevelNodes(Tree t)
{
    int height = heightTree(t);
    if (height % 2 == 0) // height == 0, 2, 4, 6... (even)
    {
        return countOdderLevelNodesByLevel(t, height);
    } else // height == 1, 3, 5, 7... (odd)
    {
        return countEvenerLevelNodesByLevel(t, height);
    }
}

/**
 * search val in tree
 * @return return target tree
 */
Tree searchTree(Tree t, int key)
{
    if (t == NULL)
    {
        return NULL;
    } else
    {
        if (t->data == key)
        {
            return t;
        } else if (t->data > key)
        {
            Tree result = searchTree(t->left, key);
            return result;

        } else
        {
            Tree result = searchTree(t->right, key);
            return result;
        }
    }
}

/**
 * rotate right
 * @return new tree
 */
Tree rotateRight(Tree n1)
{
    if (n1 == NULL || n1->left == NULL)
    {
        return n1;
    } else
    {
        Tree n2 = n1->left;
        n1->left = n2->right;
        n2->right = n1;
        return n2;
    }
}

/**
 * rotate left
 * @return new tree
 */
Tree rotateLeft(Tree n2)
{
    if (n2 == NULL || n2->right == NULL)
    {
        return n2;
    } else
    {
        Tree n1 = n2->right;
        n2->right = n1->left;
        n1->left = n2;
        return n1;
    }
}

/**
 * print level order tree
 */

void printGivenLevel(Tree t, int level)
{
    if (t == NULL)
    {
        return;
    } else
    {
        if (level == 0)
        {
            printf("%d ", t->data);
        } else if (level > 0)
        {
            // print left and right
            printGivenLevel(t->left, level - 1);
            printGivenLevel(t->right, level - 1);
        }
    }
}

void printLevelOrderTree(Tree t)
{
    if (t == NULL)
    {
        return;
    } else if (t->left == NULL && t->right == NULL)
    {
        printf("%d ", t->data);
    } else
    {
        int height = heightTree(t);
        for (int i = 0; i <= height; i++)
        {
            printf("\n");
            printGivenLevel(t, i);
        }
    }
}

/**
 * print height add node values
 */
void printHeightAddNodeValues(Tree);

/**
 * join two tree
 * max(key(t1)) < min(key(k2))
 *
 * @return
 */
Tree joinTrees(Tree t1, Tree t2)
{
    if (t1 == NULL)
    {
        return t2;
    } else if (t2 == NULL)
    {
        return t1;
    } else
    {
        Tree curr = t2;
        Tree parent = NULL;
        while (curr->left != NULL)
        {
            parent = curr;
            curr = curr->left;
        }
        if (parent != NULL)
        {
            parent->left = curr->right;
            curr->right = t2;
        }
        curr->left = t1;
        return curr;
    }
}

/**
 * check number of nodes in a tree is balanced
 * @return
 */
bool isBalancedByNumberOfNodes(Tree);

Tree partition(Tree t, int i)
{
    assert(0 <= i && i < countNodes(t));
    int m = countNodes(t->left);
    if (i < m)
    {
        t->left = partition(t->left, i);
        t = rotateRight(t);
    } else if (i > m)
    {
        t->right = partition(t->right, i - m - 1);
        t = rotateLeft(t);
    }
    return t;
}

/**
 * re balance
 * @param tree tree
 * @return
 */
Tree reBalance(Tree t)
{
    int nb_nodes = countNodes(t);
    if (nb_nodes >= 3)
    {
        t = partition(t, nb_nodes / 2);
        t->left = reBalance(t->left);
        t->right = reBalance(t->right);
    }
    return t;
}
