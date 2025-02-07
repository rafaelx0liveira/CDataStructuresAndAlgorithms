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

bool AddNodeAfter(LinkedList* linkedList, unsigned char target, unsigned char data){

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

bool AddNodeIfNotExists(LinkedList* linkedList, unsigned char data){
    
    if(linkedList == NULL || linkedList->head == NULL){
        return false;
    }

    Node* current = linkedList->head;
    Node* node = malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

    while(current != NULL){
        if(current->data == data) return false;
        current = current->next;
    }

    AddNodeAtEnd(linkedList, data);

    return true;
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

void RemoveAllOccurrences(LinkedList* linkedList, unsigned char target){
    Node* current = linkedList->head;

    while(current != NULL){
        RemoveNode(linkedList, target);

        current = current->next;
    }
}

void RemoveAllDuplicatesInSortedList(LinkedList* linkedList) {
    if (linkedList == NULL || linkedList->head == NULL) return;
    Node* current = linkedList->head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;  // Salva o nó duplicado
            current->next = current->next->next;  // Ajusta o ponteiro
            free(duplicate);  // Libera a memória corretamente
        } else {
            current = current->next;  // Avança apenas se não houver remoção
        }
    }
}

void ChangeNodes(LinkedList* lista, Node* node1, Node* node2) {
    if (node1 == node2 || lista == NULL || lista->head == NULL) {
        return;
    }

    Node* prev1 = NULL;
    Node* prev2 = NULL;
    Node* current = lista->head;

    while (current != NULL) {
        if (current->next == node1) {
            prev1 = current;
        }
        if (current->next == node2) {
            prev2 = current;
        }
        current = current->next;
    }

    // Caso especial: Se um dos nós for o `head`
    if (lista->head == node1) {
        prev1 = NULL; // Não há predecessor para o head
    }
    if (lista->head == node2) {
        prev2 = NULL; // Não há predecessor para o head
    }

    // Ajustar os ponteiros
    if (prev1 != NULL) {
        prev1->next = node2; 
    } else {
        lista->head = node2;
    }

    if (prev2 != NULL) {
        prev2->next = node1; 
    } else {
        lista->head = node1; 
    }

    // Trocar os ponteiros next de node1 e node2
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

bool IsLinkedListSorted(LinkedList* linkedList){
    Node* current = linkedList->head;

    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }


    return true;
}

bool AreListsEqualUnordered(LinkedList* firstLinkedList, LinkedList* secondLinkedList) {
    if (firstLinkedList->size != secondLinkedList->size) return false;
    if (firstLinkedList->head == NULL && secondLinkedList->head == NULL) return true;
    if (firstLinkedList->head == NULL || secondLinkedList->head == NULL) return false;

    Node* currentFirstList = firstLinkedList->head;

    while (currentFirstList != NULL) {
        Node* currentSecondList = secondLinkedList->head;
        bool found = false;

        while (currentSecondList != NULL) {
            if (currentFirstList->data == currentSecondList->data) {
                found = true;
                break; // Elemento encontrado
            }
            currentSecondList = currentSecondList->next;
        }

        if (!found) return false; // Se não encontrou o elemento
        currentFirstList = currentFirstList->next; // Avança para o próximo nó
    }

    // Agora verifica no sentido oposto (para garantir bidirecionalidade)
    Node* currentSecondList = secondLinkedList->head;

    while (currentSecondList != NULL) {
        currentFirstList = firstLinkedList->head;
        bool found = false;

        while (currentFirstList != NULL) {
            if (currentSecondList->data == currentFirstList->data) {
                found = true;
                break; // Elemento encontrado
            }
            currentFirstList = currentFirstList->next;
        }

        if (!found) return false; // Se não encontrou o elemento
        currentSecondList = currentSecondList->next; // Avança para o próximo nó
    }

    return true;
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

