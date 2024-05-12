#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *head;

Node *create_node(int item, Node *next){

    Node *new_node = (Node *)malloc(sizeof(Node));

    if(new_node == NULL){
        printf("Error!Memory Allocation Failed");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node *head, int item){
    Node *new_node = create_node(item, head);

    return new_node;
}

int main(){

    Node *n1, *n2, *head, *n3;

    n1 = create_node(10, NULL);
    head = n1;

    head = prepend(head, 20);

    n2 = head;

    printf("First data = %d\n", n2->data);

    n3 = n2->next;
    printf("Second data = %d\n", n3->data);

    return 0;
}