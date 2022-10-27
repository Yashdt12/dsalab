// WAP to implement queue using array and its operations
#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
    int front;
    int rear;
    int array[10];
}queue;
int isFull(queue *q){
    return (q->rear==(sizeof(q->array))/sizeof(q->array[0])-1);
}
int isEmpty(queue *q){
    return (q->front==-1 && q->rear==-1);
}
void enqueue(queue *q,int value){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else if(isEmpty(q)){
        q->front++;
        q->array[++q->rear]=value;
    }
    else{
        q->array[++q->rear]=value;
    }
}
int dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->rear==0){
        q->rear--;
        return (q->array[q->front--]);
    }
    else{
        return (q->array[q->front++]);
    }
}
void print(queue *q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->array[i]);
    }
    printf("\n");
}
void main(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=-1;
    q->rear=-1;
    dequeue(q);
    enqueue(q,5);
    enqueue(q,9);
    dequeue(q);
    enqueue(q,2);
    printf("Elements in stack are: ");
    print(q);
    free(q);
}