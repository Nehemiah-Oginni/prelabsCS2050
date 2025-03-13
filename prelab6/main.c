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
void printList(LinkedList *head);


int main (void)
{
    int ErrorCheck = 0;

    LinkedList* baby = initializeLinkedList(&ErrorCheck);


    for(int i=0; i<10 ; i++)
    {
        baby = insertAtHead(i, baby, &ErrorCheck);
    }
    getAtIndex(5, baby);

    printf("list length issssss %d\n\n", getLinkedListLength(baby));

    printback(baby);
    printList(baby);

}

LinkedList* initializeLinkedList(int* ErrorCheck)
{
    LinkedList * dummy = malloc(sizeof(LinkedList));//allocates space only for one LinkedList
    if(dummy == NULL)//checking that malloc worked
    {
        *ErrorCheck = 1;
    }
    dummy->object = 900;
    dummy->next = NULL;// setting the tail

    // LinkedList * dummy = malloc(sizeof(LinkedList));
    // dummy->object = 0;
    // dummy->next = list;


    return dummy;
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
    if(list->next != NULL)
    {
        head->next = list->next;
    }
    else
    {
        head->next = NULL;
    }
    
    list->next = head;//puts it at front


    return list;

}

int getAtIndex(int Index, LinkedList* list)
{
    LinkedList* temp = list->next;

    for(int i=0; i < Index && temp->next != NULL; i++) //only end of list points to NULL. when i = index, it will return the object :)
    {
       

        temp = temp->next;//temp = temp next moves through the linked list.
    }
    printf("%d\n", temp->object);
    return temp->object;
}

int getLinkedListLength(LinkedList* list)
{
    LinkedList* temp = list->next;
    int length = 0;

    for(int i=1;temp != NULL; i++) //only end of list points to NULL. when i = index, it will return the object :)
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
    headNextHold = head->next;// holds the pointer to next LinkedList before freeing 
    //free(head->data);
    free(head);
    head = headNextHold;// resets head to next LinkedList
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
void printList(LinkedList *head)//was told to print in regular order
{
    LinkedList * headHold = head;

    while(headHold != NULL)
    {
        printf("%d ",headHold->object);//prints data
        headHold = headHold->next;//moved down the line
    } 
    printf("\n");
}  

// mucsmake 2050 lab6 lab6.c