#include <stdio.h>
#include <stdlib.h>


typedef struct linkedListStruct {
    int object;
    struct linkedListStruct* next;
    } LinkedList;

//prototypes
LinkedList* initializeLinkedList(int*);
LinkedList* insertAtHead(int, LinkedList*, int*);
int getAtIndex(int, LinkedList*);
int getLinkedListLength(LinkedList*);
LinkedList * freeLinkedList(LinkedList*);
void printback(LinkedList* head);


int main (void)
{
    int ErrorCheck = 0;

    LinkedList* baby = initializeLinkedList(&ErrorCheck);


    for(int i=0; i<10 ; i++)
    {
        baby = insertAtHead(i, baby, &ErrorCheck);
    }
    getAtIndex(10, baby);

    printback(baby);

}

LinkedList* initializeLinkedList(int* ErrorCheck)
{
    LinkedList * list = malloc(sizeof(LinkedList));//allocates space only for one node
    if(list == NULL)//checking that malloc worked
    {
        *ErrorCheck = 1;
    }
    list->object = 900;
    list->next = NULL;// setting the tail

    LinkedList * dummy = malloc(sizeof(LinkedList));
    dummy->object = 0;
    dummy->next = list;


    return list;
}

LinkedList* insertAtHead(int object, LinkedList* list, int* ErrorCheck)
{
    LinkedList * head = malloc(sizeof(LinkedList));//make space for head

    if(head == NULL || list == NULL)//safe check
    {
        *ErrorCheck = 1;
        
        return list;
    }
    
    head->object = object;

    head->next = list;//puts it at front

    return head;

}

int getAtIndex(int Index, LinkedList* list)
{
    LinkedList* temp = list;

    for(int i=1; i < Index && temp->next != NULL; i++) //only end of list points to NULL. when i = index, it will return the object :)
    {
       // printf("%d\n", temp->object);

        temp = temp->next;//temp = temp next moves through the linked list.
    }
    return temp->object;
}

int getLinkedListLength(LinkedList* list)
{
    LinkedList* temp = list;
    int length = 0;

    for(int i=1;temp->next != NULL; i++) //only end of list points to NULL. when i = index, it will return the object :)
    {
        temp = temp->next;//temp = temp next moves through the linked list.
        length = i;
    }
    return length;
}

LinkedList * freeLinkedList(LinkedList* head)
{
    LinkedList * headNextHold;// make hold variable

    while(head != NULL)//goes until reaches end (can tell with NULL pointer)
    {
    headNextHold = head->next;// holds the pointer to next node before freeing 
    free(head);
    head = headNextHold;// resets head to next node
    }
    
    return NULL;
}

void printback(LinkedList* head)
{
    LinkedList * headNextHold = head;
    if(headNextHold->next != NULL)// if(headNextHold->next->object != 900) (wont get 900)
    {
        headNextHold = headNextHold->next;
        printback(headNextHold);
    }
    printf("%d\n", head->object);

}