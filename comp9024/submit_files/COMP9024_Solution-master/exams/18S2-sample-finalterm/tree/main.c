//
// Created by Rui.Mu on 2019-01-30.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main() {

    // create new tree
    Tree tree = newTree();

    // insert data
    tree = insertTree(tree, 10);
    tree = insertTree(tree, 9);
    tree = insertTree(tree, 8);
    tree = insertTree(tree, 7);
    tree = insertTree(tree, 6);
    tree = insertTree(tree, 5);
    tree = insertTree(tree, 4);
    tree = insertTree(tree, 15);
    tree = insertTree(tree, 12);
    tree = insertTree(tree, 14);
    tree = insertTree(tree, 20);

    tree = insertTree(tree, 18);
    tree = insertTree(tree, 22);



    bool isBalanced = isBalancedByNumberOfNodes(tree);

    printf("tree is balanced : %d \n", isBalanced);
    // check height of tree
    int height = heightTree(tree);
    printf("height of tree: %d \n", height);

    int with = widthTree(tree);
    printf("with of tree: %d \n", with);

    // check height of tree
    int numberOfNodes = countNodes(tree);
    printf("number of tree nodes: %d \n", numberOfNodes);

    // check number of tree leaves
    int numberOfLeaves = countLeaf(tree);
    printf("number of tree leaves: %d \n", numberOfLeaves);

    // check number of odd tree nodes
    int numberOfOddNodes = countOdds(tree);
    printf("number of odd tree nodes: %d \n", numberOfOddNodes);

    // print pre order
    printf("\nprint tree by pre order:\n");
    printPreOrderTree(tree);

    // print pre order
    printf("\nprint tree by pre order index:\n");
    printPreOrderTreeIndex(tree);

    // print in order
    printf("\nprint tree by in order:\n");
    printInOrderTree(tree);

    // print post order
    printf("\n print tree by post order:\n");
    printPostOrderTree(tree);

    // print level order
    printf("\n print tree by level order:\n");
    printLevelOrderTree(tree);

    // print level order
    printf("\n print tree height add node value by level order:\n");
    printHeightAddNodeValues(tree);

    // print level order
    printf("\n odder level count nodes :\n ");
    int countOdderLevel = countOdderLevelNodes(tree);
    printf("\n odder level count nodes %d \n",countOdderLevel);

    // print tree
    showTree(tree);
}
