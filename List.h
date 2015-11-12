#ifndef _LIST_H
#define _LIST_H

typedef struct {
	struct Node* nextItem;
	struct Node* prevItem;
	void* value;
} Node;

typedef struct {
	Node* firstItem;
	Node* lastItem;
	unsigned int size;
} DoublyLinkedList;

extern DoublyLinkedList* createNewList();

extern Node* createNewNode();

extern void addItem(DoublyLinkedList* list, void* object);

extern void addAt(DoublyLinkedList* list, unsigned int pos, void* object);

extern Node* getAt(DoublyLinkedList* list, unsigned int pos);

extern void removeAt(DoublyLinkedList* list, unsigned int pos);

extern void print(DoublyLinkedList* list);

extern void clearList(DoublyLinkedList* list);

extern void clearNode(Node* node);

#endif
