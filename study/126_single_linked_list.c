#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;    
}Node;

void insert_at_head(Node* head,int data){
    Node* current=(Node*)malloc(sizeof(Node));
    if(current == NULL)return;
    current->data=data;//先上值后链接
    current->next=head->next;
    head->next=current;
}

void traverse_list(Node* head){
    Node* current=head->next;//不用malloc分配空间
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
}

void free_list(Node* head){
    Node* current=head; //头指针也要删
    while(current != NULL){
        Node* temp=current;
        current=current->next;
        free(temp);
    }
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    if(head == NULL)return 1;
    head->next=NULL;
    insert_at_head(head,30);
    insert_at_head(head,20);
    insert_at_head(head,10);
    traverse_list(head);
    free_list(head);
}