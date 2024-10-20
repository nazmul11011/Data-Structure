// #include <stdio.h>
// #include <string.h>

// int isPali(char *s, int l, int r)
// {
//     return ((l >= r) || (s[l] == s[r] && isPali(s, l+1, r-1)));
// }

// int main()
// {
//     char str[100];
//     scanf("%s", str);
//     if(isPali(str, 0, strlen(str)-1))
//         printf("Palindrome\n");
//     else
//         printf("Not palindrome\n");
// }

// Circular Queue implementation in C

// #include <stdio.h>

// #define SIZE 5

// int items[SIZE];
// int front = -1, rear = -1;

// // check if the queue is full
// int isFull() {
//   if ((front == (rear + 1) % SIZE) || (front == 0 && rear == SIZE - 1)) return 1;
//   return 0;
// }

// // check if the queue is empty
// int isEmpty() {
//   if (front == -1) return 1;
//   return 0;
// }

// // adding an element
// void enQueue(int element) {
//   if (isFull())
//     printf("\n Queue is full!! \n");
//   else {
//     if (front == -1) front = 0;
//     rear = (rear + 1) % SIZE;
//     items[rear] = element;
//     printf("\n Inserted -> %d", element);
//   }
// }

// // removing an element
// int deQueue() {
//   int element;
//   if (isEmpty()) {
//     printf("\n Queue is empty !! \n");
//     return (-1);
//   } else {
//     element = items[front];
//     if (front == rear) {
//       front = -1;
//       rear = -1;
//     } 
//     // Q has only one element, so we reset the 
//     // queue after dequeing it. ?
//     else {
//       front = (front + 1) % SIZE;
//     }
//     printf("\n Deleted element -> %d \n", element);
//     return (element);
//   }
// }

// // display the queue
// void display() {
//   int i;
//   if (isEmpty())
//     printf(" \n Empty Queue\n");
//   else {
//     printf("\n Front -> %d ", front);
//     printf("\n Items -> ");
//     for (i = front; i != rear; i = (i + 1) % SIZE) {
//       printf("%d ", items[i]);
//     }
//     printf("%d ", items[i]);
//     printf("\n Rear -> %d \n", rear);
//   }
// }

// int main() {
//   // fails because front = -1
//   deQueue();

//   enQueue(1);
//   enQueue(2);
//   enQueue(3);
//   enQueue(4);
//   enQueue(5);

//   // fails to enqueue because front == 0 && rear == SIZE - 1
//   enQueue(6);

//   display();
//   deQueue();

//   display();

//   enQueue(7);
//   display();

//   // fails to enqueue because front == rear + 1
//   enQueue(8);

//   return 0;
// }


// #include <stdio.h>

// int main() {
//     int num = 10;         // Declare an integer variable
//     int *p;              // Declare a pointer to an integer

//     p = &num;            // Assign the address of num to the pointer p

//     printf("Value of num: %d\n", num);         // Output the value of num
//     printf("Address of num: %p\n", (void*)&num); // Output the address of num
//     printf("Value of p (address of num): %p\n", (void*)p); // Output the value of p
//     printf("Value pointed to by p: %d\n", *p); // Output the value at the address stored in p

//     // Modifying the value of num using the pointer
//     *p = 20;  // Change the value of num through the pointer

//     printf("\nAfter modifying num through pointer:\n");
//     printf("Value of num: %d\n", num);         // Output the modified value of num
//     printf("Value pointed to by p: %d\n", *p); // Output the value at the address stored in p

//     return 0;
// }


// #include <stdio.h>
// #include <string.h>

// #define pf printf

// // Define a structure named 'Student'
// struct Student {
//     int id;                // Integer to store student ID
//     char name[50];        // String to store student name
//     float gpa;            // Float to store student GPA
// };

// int main() {
//     // Declare and initialize a Student structure
//     struct Student student1;
//     student1.id = 101;
//     strcpy(student1.name, "Md. Nazmul Alam"); // Use strcpy to copy a string
//     student1.gpa = 3.75;

//     // Print the information of student1
//     pf("Student ID: %d\n", student1.id);
//     printf("Student Name: %s\n", student1.name);
//     printf("Student GPA: %.2f\n", student1.gpa);

//     // Declare and initialize another Student structure using a compound literal
//     struct Student student2 = {102, "John Doe", 3.90};

//     // Print the information of student2
//     printf("\nStudent ID: %d\n", student2.id);
//     printf("Student Name: %s\n", student2.name);
//     printf("Student GPA: %.2f\n", student2.gpa);

//     return 0;
// }


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