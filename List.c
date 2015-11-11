#include <stdlib.h>
#include "List.h"

int main(void) {
	List* list = createNewList();

	//--------------------------------
	int* value = malloc(sizeof(int));
	*(value) = 13;

	addItem(list, value);

	//--------------------------------
	int* value2 = malloc(sizeof(int));
	*(value2) = 1337;

	addItem(list, value2);

	//--------------------------------
	int* value3 = malloc(sizeof(int));
	*(value3) = 31337;

	addItem(list, value3);

	printf("\n------------ List properties --------------");
	printf("\nFirst item @ %p", list->firstItem);
	printf("\nLast item @ %p ", list->lastItem);
	printf("\nSize @ %d", list->size);
	printf("\n-------------- print() --------------------");
	print(list);
	printf("\n------------- Remove item @ pos 1() -----------------");
	removeAt(list, 1);
	printf("\n-------------- print() --------------------");
	print(list);
	printf("\n------------- clearList() -----------------");
	clearList(list);

	return 0;
}

List* createNewList() {
	List* list = (List*) malloc(sizeof(List));
	list->size = 0;
	list->firstItem = 0;
	list->lastItem = 0;

	return list;
}

Node* createNewNode() {
	Node* node = malloc(sizeof(Node));
	node->nextItem = 0;
	node->prevItem = 0;
	node->value = 0;

	return node;
}

void addItem(List* list, void* object) {
	Node* current = list->lastItem;

	if (current != 0) {
		Node* last = createNewNode();
		last->value = object;
		last->prevItem = current;
		current->nextItem = last;
		list->lastItem = last;

		printf("\nAdded item @ %p (parent =%p)", last, current);
	} else {
		list->firstItem = createNewNode();
		Node* first = list->firstItem;
		list->lastItem = first;
		first->prevItem = 0;
		printf("\nAdded first item @ %p (parent =%p)", first, 0);
		first->value = object;
	}
	list->size++;
}

Node* getAt(List* list, unsigned int pos) {

	Node* value = 0;
	Node* current = list->firstItem;

	if (current != 0) {
		unsigned int currentPos = 0;
		Node* iter = current;
		while (iter != 0) {

			if (currentPos == pos) {
				value = iter;
				break;
			}

			iter = iter->nextItem;
			++currentPos;
		}
	}

	return value;
}

void removeAt(List* list, unsigned int pos) {

	//Get the element at the position
	Node* current = getAt(list, pos);

	if (current != 0) {
		Node* parent = current->prevItem;
		Node* children = current->nextItem;

		free(current);
		list->size--;

		if (parent != 0) {
			parent->nextItem = children;
		} else if (children != 0) {
			children->prevItem = parent;
		}
	}
}

void print(List* list) {
	int size = list->size;

	if (size > 0) {
		unsigned int i;
		Node* node = 0;
		for (i = 0; i < size; ++i) {
			node = getAt(list, i);

			printf("\nItem (%d) -> %d", i, *((int*) node->value));
		}
	}
}


void clearList(List* list) {

	//Get the second element
	Node* current = getAt(list, 1);

	if (current != 0) {
		Node* parent = 0;
		while (current != 0) {
			Node* toDelete = current->prevItem;
			printf("\nCleared item @ %p", toDelete);
			free(toDelete);

			parent = current;
			current = parent->nextItem;
		}
		printf("\nCleared item @ %p", parent);
		free(parent);
	}
}
