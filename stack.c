#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value;
	void *next;
} stack;

void init(stack *, int[], int);
void push(stack *, int);
void pop(stack *);
void printstack(stack);

int main()
{
	stack s;
	init(&s, NULL, 0);
	push(&s, 3);
	push(&s, 8);
	printstack(s);
	pop(&s);
	push(&s, 1);
	printstack(s);
	return 0;
}

void init(stack *s, int arr[], int sz)
{
	int i;
	(*s).next = NULL;
	(*s).value = 0;
	for(i=0; i<sz; i++) push(s, arr[i]);
}

void push(stack *s, int n)
{
	stack *node = s;
	while((*node).next != NULL)
		node = (stack*)((*node).next);
	(*node).next = malloc(sizeof(stack));
	node = (stack*)((*node).next);
	(*node).value = n;
	(*node).next = NULL;
}

void pop(stack *s)
{
//	TODO: return integers showing what happened

	stack *node = s;
	while((stack*)((*node).next) != NULL && (*(stack*)(*node).next).next != NULL)
		node = (stack*)((*node).next);
	free((*node).next);
	(*node).next = NULL;
}

void printstack(stack s)
{
	printf("[ ");
	while(s.next != NULL) {
		printf("%d, ", s.value);
		s = *(stack*)(s.next);
	}
	printf("%d ]\n", s.value);
}
