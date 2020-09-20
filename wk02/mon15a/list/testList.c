
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void initLists(void);

void testListSum(void);
void testListLength(void);
void testListCountOdds(void);
void testListIsSorted(void);

List l1, l2, l3, l4, l5, l6;

int main(void) {
    initLists();

    testListSum();
    testListLength();
    testListCountOdds();
    testListIsSorted();
}

void initLists(void) {
    int A1[] = {};
    l1 = arrayToList(A1, 0);

    int A2[] = {3};
    l2 = arrayToList(A2, 1);

    int A3[] = {3, 1};
    l3 = arrayToList(A3, 2);

    int A4[] = {3, 1, 4};
    l4 = arrayToList(A4, 3);

    int A5[] = {3, 1, 4, 1};
    l5 = arrayToList(A5, 4);

    int A6[] = {3, 1, 4, 1, 2};
    l6 = arrayToList(A6, 5);

    printf("l1: "); listPrintRecursive(l1);
    printf("l2: "); listPrintRecursive(l2);
    printf("l3: "); listPrintRecursive(l3);
    printf("l4: "); listPrintRecursive(l4);
    printf("l5: "); listPrintRecursive(l5);
    printf("l6: "); listPrintRecursive(l6);
}

void testListSum(void) {
    assert(listSumIterative(l1) ==  0);
    assert(listSumRecursive(l1) ==  0);
    assert(listSumIterative(l2) ==  3);
    assert(listSumRecursive(l2) ==  3);
    assert(listSumIterative(l3) ==  4);
    assert(listSumRecursive(l3) ==  4);
    assert(listSumIterative(l4) ==  8);
    assert(listSumRecursive(l4) ==  8);
    assert(listSumIterative(l5) ==  9);
    assert(listSumRecursive(l5) ==  9);
    assert(listSumIterative(l6) == 11);
    assert(listSumRecursive(l6) == 11);
    printf("listSum tests passed!\n");
}

void testListLength(void) {
    assert(listLengthIterative(l1) == 0);
    assert(listLengthRecursive(l1) == 0);
    assert(listLengthIterative(l2) == 1);
    assert(listLengthRecursive(l2) == 1);
    assert(listLengthIterative(l3) == 2);
    assert(listLengthRecursive(l3) == 2);
    assert(listLengthIterative(l4) == 3);
    assert(listLengthRecursive(l4) == 3);
    assert(listLengthIterative(l5) == 4);
    assert(listLengthRecursive(l5) == 4);
    assert(listLengthIterative(l6) == 5);
    assert(listLengthRecursive(l6) == 5);
    printf("listLength tests passed!\n");
}

void testListCountOdds(void) {
    assert(listCountOddsIterative(l1) == 0);
    assert(listCountOddsRecursive(l1) == 0);
    assert(listCountOddsIterative(l2) == 1);
    assert(listCountOddsRecursive(l2) == 1);
    assert(listCountOddsIterative(l3) == 2);
    assert(listCountOddsRecursive(l3) == 2);
    assert(listCountOddsIterative(l4) == 2);
    assert(listCountOddsRecursive(l4) == 2);
    assert(listCountOddsIterative(l5) == 3);
    assert(listCountOddsRecursive(l5) == 3);
    assert(listCountOddsIterative(l6) == 3);
    assert(listCountOddsRecursive(l6) == 3);
    printf("listCountOdds tests passed!\n");
}

void testListIsSorted(void) {
    int A1[] = {};
    List ll1 = arrayToList(A1, 0);
    assert(listIsSortedIterative(ll1) == true);
    assert(listIsSortedRecursive(ll1) == true);

    int A2[] = {2};
    List ll2 = arrayToList(A2, 1);
    assert(listIsSortedIterative(ll2) == true);
    assert(listIsSortedRecursive(ll2) == true);

    int A3[] = {3, 6};
    List ll3 = arrayToList(A3, 2);
    assert(listIsSortedIterative(ll3) == true);
    assert(listIsSortedRecursive(ll3) == true);

    int A4[] = {3, 3};
    List ll4 = arrayToList(A4, 2);
    assert(listIsSortedIterative(ll4) == true);
    assert(listIsSortedRecursive(ll4) == true);

    int A5[] = {6, 3};
    List ll5 = arrayToList(A5, 2);
    assert(listIsSortedIterative(ll5) == false);
    assert(listIsSortedRecursive(ll5) == false);

    int A6[] = {1, 4, 6};
    List ll6 = arrayToList(A6, 3);
    assert(listIsSortedIterative(ll6) == true);
    assert(listIsSortedRecursive(ll6) == true);
    
    int A7[] = {1, 6, 4};
    List ll7 = arrayToList(A7, 3);
    assert(listIsSortedIterative(ll7) == false);
    assert(listIsSortedRecursive(ll7) == false);
}
