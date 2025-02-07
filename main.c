#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include "structures/lists/linked_list.h"
#include <malloc.h>

void PrintList(LinkedList* linkedList){
    if(linkedList == NULL || linkedList->head == NULL){
        printf("\nLista vazia!\n");
    }

    Node* node = linkedList->head;

    while(node != NULL){
        printf("Dado: %c\n", node->data);
        node = node->next;
    }
}

void PrintHeadAndTail(LinkedList* linkedList){
    if(linkedList == NULL || linkedList->head == NULL){
        printf("\nLista vazia!\n");
    }

    printf("\nCabeca: %c\n", linkedList->head->data);
    printf("Cauda: %c\n", linkedList->tail->data);
}

void TestLinkedList(){

}

int main() {
    
    TestLinkedList();

    return 0;
}
