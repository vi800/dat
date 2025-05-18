#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value;
	void *next;
} list;

void initl(list *, int[], int);
void append(list *, int);
void rm(list *, int);
void printl(list);

int main()
{
	list l;
	initl(&l, NULL, 0);
	append(&l, 3);
	append(&l, 2);
	append(&l, 9);
	append(&l, 8);
	printl(l);
	rm(&l, 1);
	append(&l, 5);
	printl(l);
	return 0;
}

void initl(list *l, int arr[], int sz)
{
	int i;
	(*l).next = NULL;
	(*l).value = 0;
	for(i=0; i<sz; i++) append(l, arr[i]);
}

void append(list *l, int n)
{
	list *node = l;
	while((*node).next != NULL)
		node = (list*)((*node).next);
	(*node).next = malloc(sizeof(list));
	node = (list*)((*node).next);
	(*node).value = n;
	(*node).next = NULL;
}

void rm(list *l, int i)
{
//	TODO: return integers showing what happened
	list *nx = NULL;

	list *node = l;
	if((list*)((*node).next) == NULL) return;
	while(i-- && (*(list*)(*node).next).next != NULL)
		node = (list*)((*node).next);

	nx = (*(list*)((*node).next)).next;
	free((*node).next);
	(*node).next = nx;
}

void printl(list l)
{
	printf("[ ");
	if(l.next) l = *(list*)(l.next);
	else return;
	while(l.next != NULL) {
		printf("%d, ", l.value);
		l = *(list*)(l.next);
	}
	printf("%d ]\n", l.value);
}
