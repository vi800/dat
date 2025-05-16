#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value;
	void *next;
} list;

void initl(list *, int[], int);
void push(list *, int);
void pop(list *);
void printl(list);

int main()
{
	list l;
	initl(&l, NULL, 0);
	return 0;
}

void initl(list *l, int arr[], int sz)
{
	int i;
	(*l).next = NULL;
	(*l).value = 0;
	for(i=0; i<sz; i++) push(l, arr[i]);
}

void push(list *l, int n)
{
	list *node = l;
	while((*node).next != NULL)
		node = (list*)((*node).next);
	(*node).next = malloc(sizeof(list));
	node = (list*)((*node).next);
	(*node).value = n;
	(*node).next = NULL;
}

void pop(list *l)
{
//	TODO: return integers showing what happened

	list *node = l;
	while((list*)((*node).next) != NULL && (*(list*)(*node).next).next != NULL)
		node = (list*)((*node).next);
	free((*node).next);
	(*node).next = NULL;
}

void printl(list l)
{
	while(l.next != NULL) {
		l = *(list*)(l.next);
		printf("%d\n", l.value);
	}
}
