#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"
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

void TestLinkedList(){
    LinkedList* linkedList = CreateList(); 

    if (linkedList == NULL) { 
        printf("Falha ao criar a lista.\n");
        return ;
    }

    printf("Lista criada!\n");
    printf("Tamanho da lista: %d\n", linkedList->size);

    printf("\n");

    printf("Populando fim da lista...\n");
    AddNodeAtEnd(linkedList, 'A');
    AddNodeAtEnd(linkedList, 'B');
    AddNodeAtEnd(linkedList, 'C');
    AddNodeAtEnd(linkedList, 'D');

    PrintList(linkedList);

    printf("\n");

    printf("Primeiro da lista: %c\n", linkedList->head->data);
    printf("Ultimo da lista: %c\n", linkedList->tail->data);

    printf("\n");

    printf("Populando inicio da lista...\n");

    AddNodeAtStart(linkedList, 'X');
    AddNodeAtStart(linkedList, 'Y');
    AddNodeAtStart(linkedList, 'Z');

    PrintList(linkedList);

    bool removedHead = RemoveNode(linkedList, 'Z');
    if(removedHead) printf("\nApagando primeiro No...\n");

    PrintList(linkedList);

    bool removedTail = RemoveNode(linkedList, 'D');
    if(removedTail) printf("\nApagando ultimo No...\n");

    PrintList(linkedList);

    bool removedMiddleNode = RemoveNode(linkedList, 'A');
    if(removedMiddleNode) printf("\nApagando No do meio...\n");

    PrintList(linkedList);

    printf("\nProcurando dado B na lista...\n");
    Node* nodeSearched = SearchNode(linkedList, 'B');

    printf("Dado encontrado: %c\n", nodeSearched->data);

    printf("\nInserindo novo No 'P' apos cabeca %c...\n", linkedList->head->data);
    bool insertedAfterHead = InsertNodeAfter(linkedList, linkedList->head->data, 'P');
    if(insertedAfterHead) PrintList(linkedList); 
    
    printf("\nInserindo novo No 'J' apos cauda %c...\n", linkedList->tail->data);
    bool insertedAfterTail = InsertNodeAfter(linkedList, linkedList->tail->data, 'J');
    if(insertedAfterTail) PrintList(linkedList);

    printf("\nInserindo novo No 'R' no meio...\n");
    bool insertedInMiddle = InsertNodeAfter(linkedList, 'X', 'R');
    if(insertedInMiddle) PrintList(linkedList);

    printf("\nTamanho da lista ligada: %d\n", linkedList->size);

    printf("\nDestruindo lista ligada...\n");
    DestroyLinkedList(linkedList);

    PrintList(linkedList);

    free(linkedList); // Libera a memória alocada
}

int main() {
    
    TestLinkedList();

    return 0;
}
