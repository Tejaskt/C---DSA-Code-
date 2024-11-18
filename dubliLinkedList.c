#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

// Function to create a new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the doubly linked list
void insertAtEnd(int data) {
    struct node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert a node at the beginning of the doubly linked list
void insertAtBeginning(int data) {
    struct node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Delete a node by value
void deleteByValue(int value) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If the node to be deleted is the head
    if (head->data == value) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    // Traverse to find the node to be deleted
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return;
    }

    // Unlink the node from the list
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to print the doubly linked list
void printList() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: \n");
    while (temp != NULL) {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the doubly linked list
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    printList(); // Output: 5  10  20  30

    deleteByValue(20); // Delete node with value 20
    printList(); // Output: 5  10  30

    deleteByValue(5); // Delete head node
    printList(); // Output: 10  30

    deleteByValue(100); // Try to delete a value not in the list

    return 0;
}
