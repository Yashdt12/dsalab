// WAP to implement singly linked list and it operations: creation, traversal, insertion and deletion
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node *head;
int length(){
    node *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void create(int value){
    node *new=(node*)malloc(sizeof(node));
    new->data=value;
    new->next=NULL;
    head=new;
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
        head=new;
    }
    else if(position==len+1){
        node *new=(node*)malloc(sizeof(node));
        new->data=value;
        new->next=NULL;
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
    else{
        node *new=(node*)malloc(sizeof(node));
        new->data=value;
        node *temp=head;
        for(int i=0;i<position-2;i++){
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
}
void delete(int position){
    int len=length();
    if(position<1||position>len){
        printf("Invalid position\n");
    }
    else if(position==1){
        node *temp=head;
        head=temp->next;
        free(temp);
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
        node *temp1,*temp2=head;
        for(int i=0;i<position-2;i++){
            temp2=temp2->next;
        }
        temp1=temp2->next;
        temp2->next=temp1->next;
        free(temp1);
    }
}
void printLinkedList(){
    node *temp=head;
    printf("Elements in linked list are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void freeLinkedList(node *temp){
    if(temp->next==NULL){
        free(temp);
        return;
    }
    else{
        freeLinkedList(temp->next);
        free(temp);
    }
}
void main(){
    create(5);
    insert(3,2);
    insert(7,3);
    insert(100,3);
    delete(2);
    printLinkedList();
    freeLinkedList(head);
}