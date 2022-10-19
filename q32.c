// WAP to reverse a string using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    int top;
    char word[100];
}stack;
int isFull(stack *s){
    if(s->top==(sizeof(s->word)/sizeof(s->word[0])-1)){
        return 1;
    }
    return 0;
}
int isEmpty(stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
void push(stack *s,char ch){
    if(isFull(s)){
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->word[s->top]=ch;
}
char pop(stack *s){
    char temp;
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return '\0';
    }
    else if(s->top==0){
        temp=s->word[s->top];
        s->top=-1;
        return temp;
    }
    temp=s->word[s->top];
    s->top--;
    return temp;
}
void main(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    char word[100];
    printf("Enter a word: ");
    scanf("%s",word);
    int len=strlen(word);
    for(int i=0;i<len;i++){
        push(s,word[i]);
    }
    for(int i=0;i<len;i++){
        word[i]=pop(s);
    }
    printf("Word after reversing: %s\n",word);
    free(s);
}