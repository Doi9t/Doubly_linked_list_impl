#include "List.h"

int main(void) {
	DoublyLinkedList* list = createNewList();

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

	return 0;
}

DoublyLinkedList* createNewList() {
	DoublyLinkedList* list = (DoublyLinkedList*) malloc(
			sizeof(DoublyLinkedList));
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

void addItem(DoublyLinkedList* list, void* object) {
	Node* current = list->lastItem;

	if (current != 0) {
		Node* last = createNewNode();
		last->value = object;
		last->prevItem = current;
		current->nextItem = last;
		list->lastItem = last;
	} else {
		list->firstItem = createNewNode();
		Node* first = list->firstItem;
		list->lastItem = first;
		first->prevItem = 0;
		first->value = object;
	}
	list->size++;
}

void addAt(DoublyLinkedList* list, unsigned int pos, void* object) {

	Node* current = getAt(list, pos);

	if (current != 0) {
		Node* added = createNewNode();
		added->value = object;

		Node* parent = current->prevItem;
		Node* children = current;

		if (parent != 0) {
			added->prevItem = parent;
			parent->nextItem = added;
			current->prevItem = added;
		}

		if (children != 0) {
			added->nextItem = children;
			children->prevItem = added;
		}

		list->size++;
	}
}

Node* getAt(DoublyLinkedList* list, unsigned int pos) {

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

void removeAt(DoublyLinkedList* list, unsigned int pos) {

	//Get the element at the position
	Node* current = getAt(list, pos);

	if (current != 0) {
		Node* parent = current->prevItem;
		Node* children = current->nextItem;

		clearNode(current);
		list->size--;

		if (parent != 0) {
			parent->nextItem = children;
		} else if (children != 0) {
			children->prevItem = parent;
		}
	}
}

void print(DoublyLinkedList* list) {

	Node* node = list->firstItem;

	while(node != 0) {

		int* value = node->value;

		if(value != 0) {
			printf("\nItem -> %d (%p)", *(value), node);
		}

		node = node->nextItem;
	}
}

void clearList(DoublyLinkedList* list) {

	//Get the second element
	Node* current = getAt(list, 1);

	if (current != 0) {
		Node* parent = 0;
		while (current != 0) {
			clearNode(current->prevItem);

			parent = current;
			current = parent->nextItem;
		}
		clearNode(parent);
	}

	list->firstItem = 0;
	list->lastItem = 0;
	list->size = 0;
}

void clearNode(Node* node) {
	free(node->value);
	free(node);
	node = 0;
}
