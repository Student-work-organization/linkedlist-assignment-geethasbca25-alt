#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insert at beginning
void insert_at_beginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert at end
void insert_at_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after key
void insert_after_key(int key, int data) {
    struct Node* temp = head;

    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Key not found\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Traverse forward
void traverse() {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_after_key(20, 25);

    printf("Doubly Linked List:\n");
    traverse();

    return 0;
}