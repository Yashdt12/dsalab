// WAP to implement circular linked list and its operations
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head;
int length(){
    int len=0;
    node *temp=head;
    while(temp->next!=head){
        len++;
        temp=temp->next;
    }
    return ++len;
}
void insert(int value,int position){
    int len=length();
    if(position<1 || position>len+1){
        printf("Invalid position\n");
    }
    else if(position==1){
        node *new=(node*)malloc(sizeof(node)),*temp=head;
        new->data=value;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new;
        new->next=head;
        head=new;
    }
    else{
        node *new=(node*)malloc(sizeof(node)),*temp=head;
        new->data=value;
        for(int i=0;i<position-2;i++){
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
}
void delete(int position){
    int len=length();
    if(position<1 || position>len){
        printf("Invalid position\n");
    }
    else if(position==1){
        node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        head=head->next;
        free(temp->next);
        temp->next=head;
    }
    else{
        node *temp1=head,*temp2;
        for(int i=0;i<position-2;i++){
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
    }
}
void printCircularList(){
    printf("Elements in the circular linked list are: ");
    node* temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void freeCircularList(node* temp){
    if(temp->next==head){
        free(temp);
        return;
    }
    else{
        freeCircularList(temp->next);
        free(temp);
    }
}
void main(){
    head=(node*)malloc(sizeof(node));
    head->data=3;
    head->next=head;
    insert(5,1);
    insert(10,3);
    delete(3);
    printCircularList();
    freeCircularList(head);
}