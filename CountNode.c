#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

struct Node* insertAtEnd(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) return new_node;
    struct Node* last = head;
    while (last->next != NULL) last = last->next;
    last->next = new_node;
    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 23);
    head = insertAtEnd(head, 34);
    head = insertAtEnd(head, 56);
    head = insertAtEnd(head, 78);

    int total_nodes = countNodes(head);
    printf("Total number of nodes: %d\n", total_nodes); 

    return 0;
}
