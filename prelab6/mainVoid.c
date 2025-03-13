#include <stdio.h>
#include <stdlib.h>

typedef struct linkedListStruct {
    void* object;
    struct linkedListStruct* next;
} LinkedList;

// prototypes
LinkedList* initializeLinkedList(int*);
LinkedList* insertAtHead(void*, LinkedList*, int*);
void* getAtIndex(int, LinkedList*);
int getLinkedListLength(LinkedList*);
LinkedList* freeLinkedList(LinkedList*);
void printback(LinkedList* head, void (*printFunc)(void*));
void printList(LinkedList* head, void (*printFunc)(void*));

// Helper function to print integers (for demonstration)
void printInt(void* data) {
    printf("%d", *((int*)data));
}

int main(void) {
    int ErrorCheck = 0;
    LinkedList* baby = initializeLinkedList(&ErrorCheck);

    for(int i = 0; i < 10; i++) {
        // Need to allocate memory for each integer
        int* num = malloc(sizeof(int));
        if(num == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        *num = i;
        baby = insertAtHead(num, baby, &ErrorCheck);
    }

    // Get the value at index 5
    int* value = (int*)getAtIndex(5, baby);
    if(value != NULL) {
        printf("Value at index 5: %d\n", *value);
    }

    printf("list length issssss %d\n\n", getLinkedListLength(baby));

    printback(baby, printInt);
    printList(baby, printInt);

    // Free memory for each object before freeing the list
    LinkedList* current = baby;
    while(current != NULL) {
        free(current->object);  // Free the data
        current = current->next;
    }
    baby = freeLinkedList(baby);

    return 0;
}

LinkedList* initializeLinkedList(int* ErrorCheck) {
    LinkedList* dummy = malloc(sizeof(LinkedList));
    if(dummy == NULL) {
        *ErrorCheck = 1;
        return NULL;
    }
    
    // Create and initialize a dummy object
    int* dummyValue = malloc(sizeof(int));
    if(dummyValue == NULL) {
        free(dummy);
        *ErrorCheck = 1;
        return NULL;
    }
    *dummyValue = 900;
    
    dummy->object = dummyValue;
    dummy->next = NULL;

    return dummy;
}

LinkedList* insertAtHead(void* object, LinkedList* list, int* ErrorCheck) {
    LinkedList* head = malloc(sizeof(LinkedList));

    if(head == NULL || list == NULL) {
        *ErrorCheck = 1;
        return list;
    }
    
    head->object = object;
    if(list->next != NULL) {
        head->next = list->next;
    } else {
        head->next = NULL;
    }
    
    list->next = head;

    return list;
}

void* getAtIndex(int Index, LinkedList* list) {
    if(list == NULL || list->next == NULL) {
        return NULL;
    }
    
    LinkedList* temp = list->next;

    for(int i = 0; i < Index && temp->next != NULL; i++) {
        temp = temp->next;
    }
    
    // Print the value (assuming it's an int for demonstration)
    printf("%d\n", *((int*)temp->object));
    
    return temp->object;
}

int getLinkedListLength(LinkedList* list) {
    if(list == NULL) {
        return 0;
    }
    
    LinkedList* temp = list->next;
    int length = 0;

    for(int i = 1; temp != NULL; i++) {
        temp = temp->next;
        length = i;
    }
    
    return length;
}

LinkedList* freeLinkedList(LinkedList* head) {
    LinkedList* headNextHold;

    while(head != NULL) {
        headNextHold = head->next;
        // Note: We don't free head->object here because it should be freed separately
        // to avoid memory leaks if the same object is used in multiple places
        free(head);
        head = headNextHold;
    }
    
    return NULL;
}

void printback(LinkedList* head, void (*printFunc)(void*)) {
    if(head == NULL) {
        return;
    }
    
    LinkedList* headNextHold = head;
    if(headNextHold->next != NULL) {
        headNextHold = headNextHold->next;
        printback(headNextHold, printFunc);
    }
    
    printFunc(head->object);
    printf("\n");
}

void printList(LinkedList* head, void (*printFunc)(void*)) {
    LinkedList* headHold = head;

    while(headHold != NULL) {
        printFunc(headHold->object);
        printf(" ");
        headHold = headHold->next;
    } 
    
    printf("\n");
}

/*
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;    // Store next
        current->next = prev;    // Reverse current node's pointer
        
        prev = current;          // Move pointers ahead
        current = next;
    }
    
    return prev;
}

void printReverseByReversing(struct Node* head) {
    // Reverse the list
    struct Node* reversed = reverseList(head);
    
    // Print the reversed list
    struct Node* current = reversed;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    // Reverse back to original (if needed)
    reverseList(reversed); // Note: This would need to be assigned back to head in the calling function
}
 */