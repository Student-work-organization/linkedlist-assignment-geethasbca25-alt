#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning (for initial data)
void insert_at_beginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Delete from beginning
void delete_from_beginning() {
    if(head == NULL) return;

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void delete_from_end() {
    if(head == NULL) return;

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete node with given value
void delete_node(int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if(prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Traverse
void traverse() {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);

    delete_from_beginning();
    delete_from_end();
    delete_node(20);

    printf("Linked List after deletion:\n");
    traverse();

    return 0;
}