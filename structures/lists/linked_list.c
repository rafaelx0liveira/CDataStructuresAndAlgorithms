#include "linked_list.h"
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

LinkedList* CreateList(){
    LinkedList* linkedList = malloc(sizeof(LinkedList)); 

    if(linkedList == NULL) return NULL;

    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->size = 0;

    return linkedList;
}

void AddNodeAtEnd(LinkedList* linkedList, unsigned char data) {
    Node* node = malloc(sizeof(Node));

    if (node == NULL) return; 

    node->data = data;
    node->next = NULL;

    if (linkedList->head == NULL) {
        linkedList->head = node;
        linkedList->tail = node;
    } else {
        linkedList->tail->next = node;
        linkedList->tail = node;
    }

    linkedList->size++;
}

void AddNodeAtStart(LinkedList* linkedList, unsigned char data){
    Node* node = malloc(sizeof(Node));
    
    if(node == NULL) return;

    node->data = data;

    node->next = linkedList->head;

    linkedList->head = node;

    if (linkedList->tail == NULL) {
        linkedList->tail = node;
    }

    linkedList->size++;
}

bool RemoveNode(LinkedList* linkedList, unsigned char data) {
    if (linkedList == NULL || linkedList->head == NULL) {
        return false; 
    }

    Node* head = linkedList->head;
    Node* tail = linkedList->tail;

    Node* current = linkedList->head;
    Node* previousNode = NULL;

    if (head->data == data) {
        linkedList->head = head->next;
        if (linkedList->head == NULL) {
            linkedList->tail = NULL;
        }
        linkedList->size--;
        free(head);
        return true;
    }

    if (tail->data == data) {
        while (current->next != tail) {
            current = current->next;
        }
        current->next = NULL;
        linkedList->tail = current; 
        linkedList->size--;
        free(tail);
        return true;
    }

    current = linkedList->head;
    while (current != NULL) {
        if (current->data == data) {
            previousNode->next = current->next;
            if (current == linkedList->tail) {
                linkedList->tail = previousNode; 
            }
            free(current);
            linkedList->size--;
            return true;
        }
        previousNode = current;
        current = current->next;
    }

    return false; 
}

Node* SearchNode(LinkedList* linkedList, unsigned char data){
    
    if(linkedList == NULL || linkedList->head == NULL) return false;
    
    Node* current = linkedList->head;
    
    while(current != NULL){
        if(current->data == data){
            return current;
        }

        current = current->next;
    }

    return NULL;
}

bool InsertNodeAfter(LinkedList* linkedList, unsigned char target, unsigned char data){

    if(linkedList == NULL || linkedList->head == NULL) return false;

    Node* node = malloc(sizeof(Node));
    Node* current = linkedList->head;

    if(node == NULL) return false;

    node->data = data;
    node->next = NULL;

    while(current != NULL){
        if(current->data == target){
            if(current == linkedList->tail){
                AddNodeAtEnd(linkedList, data);

                return true;
            } 

            node->next = current->next;
            current->next = node;

            linkedList->size++;
            return true;
        }

        current = current->next;
    }

    return false;
}

void DestroyLinkedList(LinkedList* linkedList){
    Node* current = linkedList->head;
    Node* nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;

        free(current);

        current = nextNode;
    }

    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->size = 0;
}

