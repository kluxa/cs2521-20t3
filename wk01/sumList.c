
typedef struct node {
	int value;
	struct node *next;
} Node;

typedef Node *List;

// while loop
int sumList(List list) {
	int total = 0;
	Node *curr = list;
	
	while (curr != NULL) {
		total += curr->value;
		curr = curr->next;
	}
	
	return total;
}

// for loop
int sumList(List list) {
	int total = 0;
	
	for (Node *curr = list; curr != NULL; curr = curr->next) {
		total += curr->value;
	}
	
	return total;
}

// recursion
int sumList(List list) {
	if (list == NULL) {
		return 0;
	} else {
		return list->value + sumList(list->next);
	}
}
