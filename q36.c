// WAP to implement circular queue and implement all its operations
#include <stdio.h>
#include <stdlib.h>
typedef struct circularQueue{
    int front;
    int rear;
    int array[3];
}circularQueue;
int isFull(circularQueue *q){
    return ((q->rear+1)%(sizeof(q->array)/(sizeof(q->array[0])))==q->front);
}
int isEmpty(circularQueue *q){
    return (q->front==-1);
}
void enqueue(circularQueue *q,int value){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else if(isEmpty(q)){
        q->front++;
        q->array[++q->rear]=value;
    }
    else{
        q->rear=(q->rear+1)%(sizeof(q->array)/sizeof(q->array[0]));
        q->array[q->rear]=value;
    }
}
int dequeue(circularQueue *q){
    int temp;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->front==q->rear){
        temp=q->array[q->front];
        q->front--;
        q->rear--;
        return temp;
    }
    else{
        temp=q->array[q->front];
        q->front=(q->front+1)%(sizeof(q->array)/sizeof(q->array[0]));
        return temp;
    }
}
void print(circularQueue *q){
    for(int i=0;i<(sizeof(q->array)/sizeof(q->array[0]));i++){
        printf("%d ",q->array[i]);
    }
    printf("\n");
}
void main(){
    circularQueue *q=(circularQueue*)malloc(sizeof(circularQueue));
    q->front=-1;
    q->rear=-1;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    dequeue(q);
    enqueue(q,4);
    print(q);
    free(q);
}