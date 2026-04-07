#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insert at end (for initial data)
void insert_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete node with given value
void delete_node(int key) {
    struct Node* temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Delete from end
void delete_end() {
    if(head == NULL) return;

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Traverse backward
void traverse_backward() {
    struct Node* temp = head;

    if(temp == NULL) return;

    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    delete_node(20);
    delete_end();

    printf("Backward Traversal:\n");
    traverse_backward();

    return 0;
}