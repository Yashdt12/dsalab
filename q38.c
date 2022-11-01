// WAP to implement stack using queue
#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
    int front;
    int rear;
    int array[10];
}queue;
typedef struct stack{
    queue *q1;
    queue *q2;
}stack;
int isFull(queue *q){
    return (q->rear)==(sizeof(q->array)/sizeof(q->array[0])-1);
}
int isEmpty(queue *q){
    return q->front==-1;
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
    int temp;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if(q->front==q->rear){
        temp=q->array[q->front];
        q->rear=-1;
        q->front=-1;
        return temp;
    }
    else{
        temp=q->array[q->front++];
        return temp;
    }
}
void push(stack *s,int value){
    if(isFull(s->q1)){
        printf("Stack is full\n");
    }
    else{
        enqueue(s->q1,value);
    }
}
int pop(stack *s){
    int temp;
    if(isEmpty(s->q1)){
        printf("Stack is empty\n");
    }
    else if(s->q1->front==s->q1->rear){
        return dequeue(s->q1);
    }
    else{
        for(int i=s->q1->front;i<s->q1->rear;i++){
            enqueue(s->q2,dequeue(s->q1));
        }
        temp=dequeue(s->q1);
        for(int i=s->q2->front;i<=s->q2->rear;i++){
            enqueue(s->q1,dequeue(s->q2));
        }
        return temp;
    }
}
void printStack(stack *s){
    if(isEmpty(s->q1)){
        printf("Stack is empty\n");
    }
    else{
        printf("Elements in stack are:\n");
        for(int i=s->q1->rear;i>=s->q1->front;i--){
            printf("%d\n",s->q1->array[i]);
        }     
    }
}
void main(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->q1=(queue*)malloc(sizeof(queue));
    s->q2=(queue*)malloc(sizeof(queue));
    s->q1->front=s->q1->rear=s->q2->front=s->q2->rear=-1;
    pop(s);
    push(s,1);
    push(s,2);
    pop(s);
    push(s,3);
    printStack(s);
    free(s->q1);
    free(s->q2);
    free(s);
}