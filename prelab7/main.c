#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    void * data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int listLen;
    int errorCode;
} Queue;

int getQueueErrorCode(Queue *);
Queue * queueInit();
int enqueue(void *, Queue *);
void * dequeue(Queue *);
int getQueueSize(Queue *);
void freeQueue(Queue *);

int main (void)
{

}

int getQueueErrorCode(Queue *list)
{
    return list->errorCode;
}

Queue * queueInit()
{
    Queue * Q = malloc(sizeof(Queue));
    Q->front = Q->rear = NULL;
    Q->listLen = 0;
    return Q;
}

int enqueue(void * data, Queue * Q)
{
    Node * newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        Q->errorCode = 1;
        return 1;
    }
    else if (Q->front == NULL)
    {
        Q->errorCode = 0;
        newNode->next = NULL;
        Q->rear = newNode;
        Q->front = newNode;
        Q->rear->data = data;

    } else
    {
        Q->errorCode = 0;
        newNode->next = Q->rear;
        newNode->data = data;
        Q->rear = newNode;
        
    }
    Q->listLen += 1;
    return 0;
}

void * dequeue(Queue * Q)
{

    if(Q == NULL || Q->front == NULL)
    {
        return NULL;
    }

    Node *nodeHold = Q->front;
    Node *QrearHold = Q->rear;

    // Q->front = Q->front->next;
    // Q->front = NULL;

    while(QrearHold->next != Q->front)
    {
        QrearHold = QrearHold->next;
    }
    Q->front = QrearHold;
    Q->front->next = NULL;

    void *dataHold = nodeHold->data;
    free(nodeHold);
    
    Q->listLen -= 1;

    return dataHold;
}

int getQueueSize(Queue * Q)
{
    return Q->listLen;
}

void freeQueue(Queue *Q)
{
    while (Q->rear != NULL)
    {
        free(dequeue(Q));// frees data too BC returns data;
    }
}

