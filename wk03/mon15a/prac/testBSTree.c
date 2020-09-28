
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

#define LF(value)              newBSTLink(value, NULL,  NULL) // leaf
#define LC(value, left)        newBSTLink(value, left,  NULL) // left child only
#define RC(value, right)       newBSTLink(value, NULL, right) // right child only
#define LR(value, left, right) newBSTLink(value, left, right) // two children

static void initTrees(void);

static void testBSTreeNumNodes(void);
static void testBSTreeCountOdds(void);
static void testBSTreeHeight(void);
static void testBSTreeCountInternal(void);
static void testBSTreeNodeDepth(void);

static BSTree newBSTLink(int value, BSTree left, BSTree right);

static BSTree t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11;


int main(void) {
    initTrees();

    testBSTreeNumNodes();
    testBSTreeCountOdds();
    testBSTreeHeight();
    testBSTreeCountInternal();
    testBSTreeNodeDepth();

    printf("All tests passed!\n");
}

static void initTrees(void) {
    /*
     */
    t01 =
        NULL;
    
    /*
        3
     */
    t02 =
        LF(3);
    
    /*
          6
         /
        3
     */
    t03 =
        LC(6,
            LF(3)
        );
    
    /*
        3
         \
          8
     */
    t04 =
        RC(3,
            LF(8)
        );
    
    /*
          6
         / \
        3   8
     */
    t05 =
        LR(6,
            LF(3),
            LF(8)
        );
    
    /*
             5
            / \
           /   \
          3     7
         / \   / \
        2   4 6   8
     */
    t06 =
        LR(5,
            LR(3,
                LF(2),
                LF(4)
            ),
            LR(7,
                LF(6),
                LF(8)
            )
        );
    
    /*
            8
           /
          2
         / \
        1   7
     */
    t07 =
        LC(8,
            LR(2,
                LF(1),
                LF(7)
            )
        );
    
    /*
          2
         / \
        0   6
           / \
          4   8
     */
    t08 =
        LR(2,
            LF(0),
            LR(6,
                LF(4),
                LF(8)
            )
        );
    
    /*
        1
         \
          8
         /
        3
         \
          6
     */
    t09 =
        RC(1,
            LC(8,
                RC(3,
                    LF(6)
                )
            )
        );
    
    /*
              5
             / \
            4   6
           /     \
          3       7
         /         \
        2           8
     */
    t10 =
        LR(5,
            LC(4,
                LC(3,
                    LF(2)
                )
            ),
            RC(6,
                RC(7,
                    LF(8)
                )
            )
        );
    
    /*
        1
         \
          3
         / \
        2   5
           / \
          4   7
             / \
            6   9
               /
              8
     */
    t11 =
        RC(1,
            LR(3,
                LF(2),
                LR(5,
                    LF(4),
                    LR(7,
                        LF(6),
                        LC(9,
                            LF(8)
                        )
                    )
                )
            )
        );
}

static void testBSTreeNumNodes(void) {
    printf("Testing BSTreeNumNodes...\n");

    assert(BSTreeNumNodes(t01) == 0);
    assert(BSTreeNumNodes(t02) == 1);
    assert(BSTreeNumNodes(t03) == 2);
    assert(BSTreeNumNodes(t04) == 2);
    assert(BSTreeNumNodes(t05) == 3);
    assert(BSTreeNumNodes(t06) == 7);
    assert(BSTreeNumNodes(t07) == 4);
    assert(BSTreeNumNodes(t08) == 5);
    assert(BSTreeNumNodes(t09) == 4);
    assert(BSTreeNumNodes(t10) == 7);
    assert(BSTreeNumNodes(t11) == 9);

    printf("BSTreeNumNodes tests passed!\n");
}

static void testBSTreeCountOdds(void) {
    printf("Testing BSTreeCountOdds...\n");

    assert(BSTreeCountOdds(t01) == 0);
    assert(BSTreeCountOdds(t02) == 1);
    assert(BSTreeCountOdds(t03) == 1);
    assert(BSTreeCountOdds(t04) == 1);
    assert(BSTreeCountOdds(t05) == 1);
    assert(BSTreeCountOdds(t06) == 3);
    assert(BSTreeCountOdds(t07) == 2);
    assert(BSTreeCountOdds(t08) == 0);
    assert(BSTreeCountOdds(t09) == 2);
    assert(BSTreeCountOdds(t10) == 3);
    assert(BSTreeCountOdds(t11) == 5);

    printf("BSTreeCountOdds tests passed!\n");
}

static void testBSTreeHeight(void) {
    printf("Testing BSTreeHeight...\n");

    assert(BSTreeHeight(t01) == -1);
    assert(BSTreeHeight(t02) ==  0);
    assert(BSTreeHeight(t03) ==  1);
    assert(BSTreeHeight(t04) ==  1);
    assert(BSTreeHeight(t05) ==  1);
    assert(BSTreeHeight(t06) ==  2);
    assert(BSTreeHeight(t07) ==  2);
    assert(BSTreeHeight(t08) ==  2);
    assert(BSTreeHeight(t09) ==  3);
    assert(BSTreeHeight(t10) ==  3);
    assert(BSTreeHeight(t11) ==  5);

    printf("BSTreeHeight tests passed!\n");
}

static void testBSTreeCountInternal(void) {
    printf("Testing BSTreeCountInternal...\n");

    assert(BSTreeCountInternal(t01) == 0);
    assert(BSTreeCountInternal(t02) == 0);
    assert(BSTreeCountInternal(t03) == 1);
    assert(BSTreeCountInternal(t04) == 1);
    assert(BSTreeCountInternal(t05) == 1);
    assert(BSTreeCountInternal(t06) == 3);
    assert(BSTreeCountInternal(t07) == 2);
    assert(BSTreeCountInternal(t08) == 2);
    assert(BSTreeCountInternal(t09) == 3);
    assert(BSTreeCountInternal(t10) == 5);
    assert(BSTreeCountInternal(t11) == 5);

    printf("BSTreeCountInternal tests passed!\n");
}

static void testBSTreeNodeDepth(void) {
    printf("Testing BSTreeNodeDepth...\n");

    assert(BSTreeNodeDepth(t01, 1) == -1);

    assert(BSTreeNodeDepth(t02, 3) ==  0);
    assert(BSTreeNodeDepth(t02, 0) == -1);
    assert(BSTreeNodeDepth(t02, 6) == -1);
    
    assert(BSTreeNodeDepth(t03, 6) ==  0);
    assert(BSTreeNodeDepth(t03, 3) ==  1);
    assert(BSTreeNodeDepth(t03, 2) == -1);
    assert(BSTreeNodeDepth(t03, 5) == -1);
    assert(BSTreeNodeDepth(t03, 9) == -1);
    
    assert(BSTreeNodeDepth(t04, 3) ==  0);
    assert(BSTreeNodeDepth(t04, 8) ==  1);
    assert(BSTreeNodeDepth(t04, 0) == -1);
    assert(BSTreeNodeDepth(t04, 7) == -1);
    assert(BSTreeNodeDepth(t04, 4) == -1);
    
    assert(BSTreeNodeDepth(t05, 6) ==  0);
    assert(BSTreeNodeDepth(t05, 3) ==  1);
    assert(BSTreeNodeDepth(t05, 8) ==  1);
    assert(BSTreeNodeDepth(t05, 1) == -1);
    assert(BSTreeNodeDepth(t05, 4) == -1);
    assert(BSTreeNodeDepth(t05, 7) == -1);
    assert(BSTreeNodeDepth(t05, 9) == -1);
    
    assert(BSTreeNodeDepth(t06, 5) ==  0);
    assert(BSTreeNodeDepth(t06, 3) ==  1);
    assert(BSTreeNodeDepth(t06, 7) ==  1);
    assert(BSTreeNodeDepth(t06, 2) ==  2);
    assert(BSTreeNodeDepth(t06, 4) ==  2);
    assert(BSTreeNodeDepth(t06, 6) ==  2);
    assert(BSTreeNodeDepth(t06, 8) ==  2);
    assert(BSTreeNodeDepth(t06, 0) == -1);
    assert(BSTreeNodeDepth(t06, 9) == -1);
    
    assert(BSTreeNodeDepth(t07, 8) ==  0);
    assert(BSTreeNodeDepth(t07, 2) ==  1);
    assert(BSTreeNodeDepth(t07, 1) ==  2);
    assert(BSTreeNodeDepth(t07, 7) ==  2);
    assert(BSTreeNodeDepth(t07, 0) == -1);
    assert(BSTreeNodeDepth(t07, 5) == -1);
    assert(BSTreeNodeDepth(t07, 9) == -1);

    assert(BSTreeNodeDepth(t08, 2) ==  0);
    assert(BSTreeNodeDepth(t08, 0) ==  1);
    assert(BSTreeNodeDepth(t08, 6) ==  1);
    assert(BSTreeNodeDepth(t08, 4) ==  2);
    assert(BSTreeNodeDepth(t08, 8) ==  2);
    assert(BSTreeNodeDepth(t08, 1) == -1);
    assert(BSTreeNodeDepth(t08, 3) == -1);
    assert(BSTreeNodeDepth(t08, 5) == -1);
    assert(BSTreeNodeDepth(t08, 7) == -1);
    assert(BSTreeNodeDepth(t08, 9) == -1);

    assert(BSTreeNodeDepth(t09, 1) ==  0);
    assert(BSTreeNodeDepth(t09, 8) ==  1);
    assert(BSTreeNodeDepth(t09, 3) ==  2);
    assert(BSTreeNodeDepth(t09, 6) ==  3);
    assert(BSTreeNodeDepth(t09, 0) == -1);
    assert(BSTreeNodeDepth(t09, 2) == -1);
    assert(BSTreeNodeDepth(t09, 5) == -1);
    assert(BSTreeNodeDepth(t09, 7) == -1);
    assert(BSTreeNodeDepth(t09, 9) == -1);

    assert(BSTreeNodeDepth(t10, 5) ==  0);
    assert(BSTreeNodeDepth(t10, 4) ==  1);
    assert(BSTreeNodeDepth(t10, 6) ==  1);
    assert(BSTreeNodeDepth(t10, 3) ==  2);
    assert(BSTreeNodeDepth(t10, 7) ==  2);
    assert(BSTreeNodeDepth(t10, 2) ==  3);
    assert(BSTreeNodeDepth(t10, 8) ==  3);
    assert(BSTreeNodeDepth(t10, 1) == -1);
    assert(BSTreeNodeDepth(t10, 9) == -1);

    assert(BSTreeNodeDepth(t11,  1) ==  0);
    assert(BSTreeNodeDepth(t11,  3) ==  1);
    assert(BSTreeNodeDepth(t11,  2) ==  2);
    assert(BSTreeNodeDepth(t11,  5) ==  2);
    assert(BSTreeNodeDepth(t11,  4) ==  3);
    assert(BSTreeNodeDepth(t11,  7) ==  3);
    assert(BSTreeNodeDepth(t11,  6) ==  4);
    assert(BSTreeNodeDepth(t11,  9) ==  4);
    assert(BSTreeNodeDepth(t11,  8) ==  5);
    assert(BSTreeNodeDepth(t11,  0) == -1);
    assert(BSTreeNodeDepth(t11, 10) == -1);

    printf("BSTreeNodeDepth tests passed!\n");
}

// ----------------------------------------

static BSTree newBSTLink(int value, BSTree left, BSTree right) {
    BSTree t = malloc(sizeof(*t));
    if (t == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    t->value = value;
    t->right = right;
    t->left = left;
    return t;
}
