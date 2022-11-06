// WAP to get to the middle of a linked list in single operation
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head;
void createLinkedList(){
    node *new,*temp=(node*)malloc(sizeof(node));
    temp->data=1;
    temp->next=NULL;
    head=temp;
    for(int i=2;i<=4;i++){
        new=(node*)malloc(sizeof(node));
        new->data=i;
        new->next=NULL;
        temp->next=new;
        temp=new;
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
void printMiddleElement(){
    node *temp1=head,*temp2=head;
    while(1){
        if(temp2->next==NULL){
            printf("Middle element is: %d\n",temp1->data);
            break;
        }
        else if(temp2->next->next==NULL){
            printf("Middle elements are: %d and %d\n",temp1->data,temp1->next->data);
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
}
void main(){
    createLinkedList();
    printLinkedList();
    printMiddleElement();
    freeLinkedList(head);
}