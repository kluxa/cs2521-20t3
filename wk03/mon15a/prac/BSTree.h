
#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode *BSTree;
typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

/**
 * Returns the number of nodes in the tree.
 */
int BSTreeNumNodes(BSTree t);

/**
 * Returns the number of odd values in the given tree.
 */
int BSTreeCountOdds(BSTree t);

/**
 * Returns  the  height  of  the given tree. The height of a tree is the
 * number  of  edges  on  the  longest path from the root node to a leaf
 * node. The height of an empty tree is -1.
 */
int BSTreeHeight(BSTree t);

/**
 * Returns the number of internal nodes in the tree. An internal node is
 * a  node  that  has  one  or more children, i.e., a node that is not a
 * leaf.
 */
int BSTreeCountInternal(BSTree t);

/**
 * Returns the depth of the node containing the given key in the tree if
 * it exists, or -1 otherwise.
 */
int BSTreeNodeDepth(BSTree t, int key);

#endif
