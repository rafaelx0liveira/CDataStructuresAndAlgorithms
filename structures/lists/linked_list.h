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

void AddNodeAtStart(LinkedList* linkedList, unsigned char data);
void AddNodeAtEnd(LinkedList* list, unsigned char data);
bool AddNodeIfNotExists(LinkedList* linkedList, unsigned char data);
bool AddNodeAfter(LinkedList* linkedList, unsigned char target, unsigned char data);

Node* SearchNode(LinkedList* linkedList, unsigned char data);

bool RemoveNode(LinkedList* linkedList, unsigned char data);
void RemoveAllOccurrences(LinkedList* linkedList, unsigned char target);
void RemoveAllDuplicatesInSortedList(LinkedList* linkedList);

void ChangeNodes(LinkedList* linkedList, Node* node1, Node* node2);

bool IsLinkedListSorted(LinkedList* linkedList);
bool AreListsEqualUnordered(LinkedList* LinkedList1, LinkedList* LinkedList2);

void DestroyLinkedList(LinkedList* linkedList);

#endif
