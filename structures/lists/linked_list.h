#include <stdbool.h>
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node{
    unsigned char data;       
    struct Node *next;        
} Node;

typedef struct LinkedList{
    int size;
    Node *head;
    Node *tail;
} LinkedList;

LinkedList* CreateList();
Node* SearchNode(LinkedList* linkedList, unsigned char data);
void AddNodeAtStart(LinkedList* linkedList, unsigned char data);
void AddNodeAtEnd(LinkedList* list, unsigned char data);
bool RemoveNode(LinkedList* linkedList, unsigned char data);
bool InsertNodeAfter(LinkedList* linkedList, unsigned char target, unsigned char data);
void DestroyLinkedList(LinkedList* linkedList);

#endif
