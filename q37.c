// WAP to implement double ended queue and all its operations
#include <stdio.h>
#include <stdlib.h>
typedef struct doubleEndedQueue{
    int front;
    int rear;
    int array[3];
}doubleEndedQueue;
int isFull(doubleEndedQueue *q){
    return q->front==(q->rear+1)%(sizeof(q->array)/sizeof(q->array[0]));
}
int isEmpty(doubleEndedQueue *q){
    return (q->front==-1 && q->rear==-1);
}
void insertFront(doubleEndedQueue *q,int value){
    if(q->front==0){
        printf("Cannot insert at front\n");
    }
    else if(isEmpty(q)){
        q->rear++;
        q->array[++q->front]=value;
    }
    else{
        q->array[--q->front]=value;
    }
}
void insertRear(doubleEndedQueue *q,int value){
    if(q->rear==(sizeof(q->array)/sizeof(q->array[0]))){
        printf("Cannot insert at rear\n");
    }
    else if(isEmpty(q)){
        q->front++;
        q->array[++q->rear]=value;
    }
    else{
        q->array[++q->rear]=value;
    }
}
int deleteFront(doubleEndedQueue *q){
    int temp;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->front==q->rear){
        temp=q->array[q->front--];
        q->rear--;
        return temp;
    }
    else{
        temp=q->array[q->front++];
        return temp;
    }
}
int deleteRear(doubleEndedQueue *q){
    int temp;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->front==q->rear){
        temp=q->array[q->front--];
        q->rear--;
        return temp;
    }
    else{
        temp=q->array[q->rear--];
        return temp;
    }
}
void print(doubleEndedQueue *q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->array[i]);
    }
    printf("\n");
}
void main(){
    doubleEndedQueue *q=(doubleEndedQueue*)malloc(sizeof(doubleEndedQueue));
    q->front=-1;
    q->rear=-1;
    insertFront(q,1);
    insertRear(q,2);
    deleteFront(q);
    insertFront(q,3);
    deleteRear(q);
    insertRear(q,4);
    print(q);
    free(q);
}