// WAP to implement doubly linked list and its operations
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node *head;
int length(){
    int len=0;
    node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insert(int value,int position){
    int len=length();
    if(position<1 || position>len+1){
        printf("Invalid position\n");
    }
    else if(position==1){
        node *new=(node*)malloc(sizeof(node));
        new->data=value;
        new->prev=NULL;
        head->prev=new;
        new->next=head;
        head=new;
    }
    else if(position==len+1){
        node *new=(node*)malloc(sizeof(node)),*temp=head;
        new->data=value;
        new->next=NULL;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
    else{
        node *new=(node*)malloc(sizeof(node)),*temp=head;
        new->data=value;
        for(int i=0;i<position-2;i++){
            temp=temp->next;
        }
        new->prev=temp;
        new->next=temp->next;
        temp->next->prev=new;
        temp->next=new;
    }
}
void delete(int position){
    int len=length();
    if(position<1 || position>len){
        printf("Invalid position\n");
    }
    else if(position==1){
        head=head->next;
        free(head->prev);
        head->prev=NULL;
    }
    else if(position==len){
        node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    else{
        node *temp=head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void printDoublyLinkedList(){
    printf("Elements in doubly linked list are: ");
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void freeDoublyLinkedList(node *temp){
    if(temp->next==NULL){
        free(temp);
        return;
    }
    else{
        freeDoublyLinkedList(temp->next);
        free(temp);
    }
}
void main(){
    head=(node*)malloc(sizeof(node));
    head->data=5;
    head->next=NULL;
    head->prev=NULL;
    insert(15,2);
    insert(10,2);
    delete(2);
    printDoublyLinkedList();
    freeDoublyLinkedList(head);
}