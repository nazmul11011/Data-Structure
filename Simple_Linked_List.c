#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data){
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

void printList(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }printf("END\n");
}

int main(){
    Node *head=createNode(1);
    head->next=createNode(3);
    head->next->next=createNode(5);
    head->next->next->next=createNode(6);

    printList(head);
    return 0;
}