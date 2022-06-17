#include <stdio.h>
#include <stdlib.h>

struct _node
{
	int value;
	struct _node *next;
};

struct _node *create();
int delete (struct _node *list);
void insert(struct _node *list, int value);	 // if value is already in the list, skip inserting, if not, append new value at the
void removel(struct _node *list, int value); // remove all instances of value
void printl(struct _node *list);
int detectCycledList(struct _node * list);


int main()
{
	struct _node *linkedList = create();

	insert(linkedList, 1);
	insert(linkedList, 1);
	insert(linkedList, 1);
	printl(linkedList);

	insert(linkedList, 4);
	insert(linkedList, 9);
	insert(linkedList, 100);
	printl(linkedList);

	removel(linkedList, 1);
	printl(linkedList);

	insert(linkedList, 243);
	printl(linkedList);
	linkedList->next->next->next = linkedList->next;

	printf("%d\n", detectCycledList(linkedList));

	printf("%d\n", delete (linkedList));

}

struct _node *create()
{
	struct _node *head = malloc(sizeof(struct _node *));
	if(head != NULL)
	{
		head->value = 0;
		head->next = NULL;
	}
	return head;
}

/*
return the number of nodes
*/
int delete (struct _node *list)
{
	int numberOfNodes = 0;
	struct _node *_browse = list;
	if (_browse->next == NULL)
	{
		free(_browse);
		numberOfNodes++;
		return numberOfNodes;
	}
	while (_browse->next != NULL)
	{
		struct _node *_temp = _browse;
		_browse = _browse->next;
		free(_temp);
		numberOfNodes++;
	}
	return numberOfNodes;
}

void insert(struct _node *list, int value) // if value is already in the list, skip inserting, if not, append new value at the
{
	struct _node *_browse = list;
	if (_browse->next == NULL)
	{
		if (_browse->value == value)
			return;
		struct _node *_new = create();
		_new->value = value;
		_browse->next = _new;
		return;
	}

	while (_browse->next != NULL)
	{
		if (_browse->value == value)
			return;
		_browse = _browse->next;
	}
	if (_browse->value == value)
		return;

	struct _node *_new = create();
	_new->value = value;
	_browse->next = _new;
}

void removel(struct _node *list, int value) // remove all instances of value
{
	struct _node *_browse = list;
	while (_browse->next != NULL && _browse != NULL)
	{
		struct _node *_temp = _browse->next;
		if (_temp->value == value)
		{
			_browse->next = _temp->next;
			_browse = _browse->next;
			free(_temp);
		}
		_browse = _browse->next;
	}
}

void printl(struct _node *list)
{
	struct _node *_browse = list->next;
	while (_browse != NULL)
	{
		printf("%d ", _browse->value);
		_browse = _browse->next;
		if (_browse == NULL)
		{
			printf("\n");
			break;
		}
	}
}

int detectCycledList(struct _node * list)
{
	struct _node *_browse1 = list;
	struct _node *_browse2 = list->next;
	while (_browse1->next != NULL)
	{
		//while(_browse2->next != _browse1)
		//{
			if (_browse1 == _browse2)
			{
				//printf("cycle at %d\n", _browse1->value);
				return 1;
			}
			_browse1 = _browse1->next;
		//}
		if(_browse2->next->next == NULL)	_browse2 = list;
		else	_browse2 = _browse2->next->next;
	}
	return 0;
}