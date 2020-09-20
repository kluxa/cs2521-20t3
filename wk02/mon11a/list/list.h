
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node {
   int data;
   struct node *next;
} Node;
typedef Node *List;

void listPrintIterative(List L);

void listPrintRecursive(List L);

int listSumIterative(List L);

int listSumRecursive(List L);

int listLengthIterative(List L);

int listLengthRecursive(List L);

int listCountOddsIterative(List L);

int listCountOddsRecursive(List L);

bool listIsSortedIterative(List L);

bool listIsSortedRecursive(List L);

List arrayToList(int A[], int len);

void printList(List l);

#endif
