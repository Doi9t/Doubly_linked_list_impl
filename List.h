#ifndef _LIST_H
#define _LIST_H

typedef struct
{
	struct Node* nextItem;
	struct Node* prevItem;
	void* value;
} Node;

typedef struct 
{
	Node* firstItem;
	Node* lastItem;
	unsigned int size;
} List;


extern List* createNewList();

extern Node* createNewNode();

extern void addItem(List* list, void* object);

extern Node* getAt(List* list, unsigned int pos);

extern void removeAt(List* list, unsigned int pos);

extern void print(List* list);

extern Node* getLastNode(List* list);

extern void clearList(List* list);

#endif
