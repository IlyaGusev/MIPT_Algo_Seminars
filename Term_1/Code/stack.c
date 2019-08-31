#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Stack {
	int* array;
	unsigned int topIndex;
	unsigned int capacity;
};

void InitStack(struct Stack* stack, unsigned int startCapacity) {
	stack->array = (int*)malloc(sizeof(int) * startCapacity);
	stack->topIndex = 0;
	stack->capacity = startCapacity;
	printf("initial capacity %d\n", startCapacity);
}

void DestroyStack(struct Stack* stack) {
	free(stack->array);
	stack->topIndex = 0;
	stack->capacity = 0;
	stack->array = NULL;
}

unsigned int StackSize(struct Stack* stack) {
	return stack->topIndex;
}

short StackPop(struct Stack* stack, int* element) {
	if (stack->topIndex <= 0) {
		return -1;
	}
	(*element) =  stack->array[stack->topIndex - 1];
	stack->topIndex -= 1;
	if (stack->topIndex <= (unsigned int)(stack->capacity / 4)) {
		unsigned int newCapacity = (unsigned int)(stack->capacity / 2);
		stack->array = (int*)realloc(stack->array, sizeof(int) * newCapacity);
		stack->capacity = newCapacity;
		printf("capacity changed to %d\n", newCapacity);
	}
	return 0;
}

void StackPush(struct Stack* stack, int element) {
	if (stack->topIndex >= stack->capacity) {
		unsigned int newCapacity = 2 * stack->capacity;
		stack->array = (int*)realloc(stack->array, sizeof(int) * newCapacity);
		stack->capacity = newCapacity;
		printf("capacity changed to %d\n", newCapacity);
	}
	stack->array[stack->topIndex] = element;
	stack->topIndex += 1;
}

int main() {
	Stack stack;
	InitStack(&stack, 2);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int command;
		int element;
		scanf("%d %d", &command, &element);
		if (command == 0) {
			StackPush(&stack, element);
			printf("topIndex: %d\n", stack.topIndex);
		} else if (command == 1) {
			int returnElement;
			int rv = StackPop(&stack, &returnElement);
			assert(rv == 0);
			assert(returnElement == element);
		} else {
			assert(0);
		}
	}

	DestroyStack(&stack);
}
