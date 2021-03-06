
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// defined in list.h
//
// typedef struct node {
//    int data;
//    struct node *next;
// } Node;
// typedef Node *List;

////////////////////////////////////////////////////////////
// listPrint

void listPrintIterative(List L) {
    for (Node *curr = L; curr != NULL; curr = curr->next) {
        printf("%d -> ", curr->data);
    }
    printf("X\n");
}

void listPrintRecursive(List L) {
    if (L == NULL) {
        printf("X\n");
    } else {
        printf("%d -> ", L->data);
        listPrintRecursive(L->next);
    }
}

////////////////////////////////////////////////////////////
// listSum

int listSumIterative(List L) {
    int sum = 0;
    for (Node *curr = L; curr != NULL; curr = curr->next) {
        sum += curr->data;
    }
    return sum;
}

int listSumRecursive(List L) {
    // TODO
    return 0;
}

////////////////////////////////////////////////////////////
// listLength

int listLengthIterative(List L) {
    int length = 0;
    for (Node *curr = L; curr != NULL; curr = curr->next) {
        length++;
    }
    return length;
}

int listLengthRecursive(List L) {
    // TODO
    return 0;
}

////////////////////////////////////////////////////////////
// listCountOdds

int listCountOddsIterative(List L) {
    int count = 0;
    for (Node *curr = L; curr != NULL; curr = curr->next) {
        if (curr->data % 2 != 0) {
            count++;
        }
    }
    return count;
}

int listCountOddsRecursive(List L) {
    // TODO
    return 0;
}

////////////////////////////////////////////////////////////
// listIsSorted

bool listIsSortedIterative(List L) {
    if (L == NULL) {
        return true;
    }

    for (Node *curr = L; curr->next != NULL; curr = curr->next) {
        if (curr->data > curr->next->data) {
            return false;
        }
    }
    return true;
}

bool listIsSortedRecursive(List L) {
    // TODO
    return false;
}

////////////////////////////////////////////////////////////

static List newNode(int val);

List arrayToList(int A[], int len) {
    List head = NULL;
    List curr = NULL;
    for (int i = 0; i < len; i++) {
        List node = newNode(A[i]);
        if (head == NULL) {
            head = node;
            curr = node;
        } else {
            curr->next = node;
            curr = node;
        }
    }
    return head;
}

static List newNode(int val) {
    List n = malloc(sizeof(*n));
    if (n == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }
    n->data = val;
    n->next = NULL;
    return n;
}

////////////////////////////////////////////////////////////
