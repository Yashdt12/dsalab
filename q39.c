// WAP to implement queue using stack
#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int top;
    int array[10];
}stack;
typedef struct queue{
    stack *s1;
    stack *s2;
}queue;
int isFull(stack *s){
    return (s->top==(sizeof(s->array)/sizeof(s->array[0])-1));
}
int isEmpty(stack *s){
    return (s->top==-1);
}
void push(stack *s,int value){
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else{
        s->array[++s->top]=value;
    }
}
int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        return s->array[s->top--];
    }
}
void enqueue(queue *q,int value){
    if(isFull(q->s1)){
        printf("Queue is full\n");
    }
    else{
        push(q->s1,value);
    }
}
int dequeue(queue *q){
    if(isEmpty(q->s1)){
        printf("Queue is empty\n");
    }
    else{
        while(q->s1->top!=0){
            push(q->s2,pop(q->s1));
        }
        int temp=pop(q->s1);
        while(!isEmpty(q->s2)){
            push(q->s1,pop(q->s2));
        }
        return temp;
    }
}
void printQueue(queue *q){
    
    printf("Elements in the queue are: ");
    for(int i=0;i<=q->s1->top;i++){
        printf("%d ",q->s1->array[i]);
    }
    printf("\n");
}
void main(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->s1=(stack*)malloc(sizeof(stack));
    q->s2=(stack*)malloc(sizeof(stack));
    q->s1->top=q->s2->top=-1;
    enqueue(q,1);
    enqueue(q,2);
    dequeue(q);
    enqueue(q,3);
    printQueue(q);
    free(q->s1);
    free(q->s2);
    free(q);
}