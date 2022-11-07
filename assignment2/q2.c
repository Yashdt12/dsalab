// WAP to implement priority queue and its operations using linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int priority;
    struct node* next;
}node;
typedef struct queue{
    node *front;
    node *rear;
}queue;
int isEmpty(queue *q){
    return q->front==NULL;
}
void enqueue(queue *q,int data,int priority){
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->priority=priority;
    if(isEmpty(q)){
        new->next=NULL;
        q->front=new;
        q->rear=new;
    }
    else{
        node *temp=q->front;
        while(priority<=temp->priority && temp!=q->rear){
            temp=temp->next;
        }
        if(temp==q->front && priority>temp->priority){
            new->next=temp;
            q->front=new;
        }
        else if(temp==q->rear){
            new->next=NULL;
            temp->next=new;
            q->rear=new;
        }
        else{
            new->next=temp->next;
            temp->next=new;
        }
    }
}
int dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->front==q->rear){
        int n=q->front->data;
        free(q->front);
        q->front=NULL;
        q->rear=NULL;
        return n;
    }
    else{
        node *temp=q->front;
        int n=temp->data;
        q->front=temp->next;
        free(temp);
        return n;
    }
}
int peek(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    return q->front->data;
}
queue* createQueue(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
void printQueue(queue *q){
    printf("Elements(and their priorities) in the queue are: ");    
    node *temp=q->front;
    while(temp!=NULL){
        printf("%d(%d) ",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}
void freeList(node *temp){
    if(temp==NULL){
        return;
    }
    else{
        freeList(temp->next);
        free(temp);
    }
}
void freeQueue(queue *q){
    freeList(q->front);
    free(q);
}
void main(){
    queue *q=createQueue();
    enqueue(q,5,2);
    enqueue(q,10,1);
    enqueue(q,15,3);
    dequeue(q);
    printQueue(q);
    printf("Next element to be removed: %d\n",peek(q));
    freeQueue(q);
}