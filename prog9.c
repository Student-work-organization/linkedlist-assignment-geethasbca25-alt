#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at end
void insert_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete node
void delete_node(int key) {
    if(head == NULL) return;

    struct Node *temp = head, *prev = NULL;

    // If head needs deletion
    if(head->data == key) {
        while(temp->next != head)
            temp = temp->next;

        if(temp == head) {
            free(head);
            head = NULL;
            return;
        }

        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }

    temp = head;
    do {
        prev = temp;
        temp = temp->next;

        if(temp->data == key) {
            prev->next = temp->next;
            free(temp);
            return;
        }
    } while(temp != head);

    printf("Value not found\n");
}

// Traverse
void traverse() {
    if(head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(back to head)\n");
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);

    delete_node(20);

    printf("Circular List after deletion:\n");
    traverse();

    return 0;
}