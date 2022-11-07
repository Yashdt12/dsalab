// WAP to implement Circular Doubly Linked List and its operations
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node *head;
int length(){
    node *temp=head;
    int len=0;
    while(temp->next!=head){
        temp=temp->next;
        len++;
    }
    return ++len;
}
void create(int value){ // Creates first node
    head=(node*)malloc(sizeof(node));
    head->data=value;
    head->next=head;
    head->prev=head;
}
void insert(int value,int position){
    int len=length();
    if(position<1 || position>len+1){
        printf("Invalid position\n");
    }
    else if(position==1){
        node *new=(node*)malloc(sizeof(node));
        new->data=value;
        new->next=head;
        new->prev=head->prev;
        head->prev->next=new;
        head->prev=new;
    }
    else{
        node *new=(node*)malloc(sizeof(node)),*temp=head;
        new->data=value;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        new->next=temp;
        new->prev=temp->prev;
        temp->prev->next=new;
        temp->prev=new;
    }
}
void delete(int position){
    int len=length();
    if(position<1 || position>len){
        printf("Invalid position\n");
    }
    else if(position==1){
        node *temp=head;
        head=head->next;
        head->prev=temp->prev;
        temp->prev->next=head;
        free(temp);
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
void printList(){
    printf("Elements in the list are: ");
    node *temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void freeList(node* temp){
    if(temp->next==head){
        free(temp);
        return;
    }
    else{
        freeList(temp->next);
        free(temp);
    }
}
void main(){
    create(5);
    insert(15,2);
    insert(10,2);
    delete(2);
    printList();
    freeList(head);
}