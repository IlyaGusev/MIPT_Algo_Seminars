#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	struct Node* next;
	int value;
};

struct List {
	struct Node* first;
	struct Node* last;
};

void PushBack(struct List* list, int value) {
	struct Node* newNode = 
		(struct Node*)malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->next = NULL;
	
	if (list->last) {
		list->last->next = newNode;
		list->last = newNode;
	} else {
		list->first = newNode;
		list->last = newNode;
	}
}

int PopFront(struct List* list) {
	struct Node* oldFirst = list->first;
	if (!list->first) {
		return -1;
	}
	
	list->first = list->first->next;
	if (!list->first) {
		list->last = NULL;
	}
	
	int result = oldFirst->value;
	free(oldFirst);
	return result;
}

int ProcessCommands() {
	int isCorrect = 1;
	
	struct List list;
	list.first = NULL;
	list.last = NULL;
	
	int n = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		if (a == 3) {
			PushBack(&list, b);
		} else if (a == 2) {
			int value = PopFront(&list);
			if (value != b) {
				isCorrect = 0;
				break;
			}
		}
	}
	while (list.first) {
		PopFront(&list);
	}
	return isCorrect;
}

int main() {
	int isCorrect = ProcessCommands();
	printf("%s", isCorrect ? "YES" : "NO");
}