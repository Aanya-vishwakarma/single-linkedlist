#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    struct Node* temp = head;

    head = head->next;
    free(temp);
    return head;
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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 23);
    head = insertAtEnd(head, 34);
    head = insertAtEnd(head, 56);
    head = insertAtEnd(head, 78);

    printf("Original List: ");
    printList(head);

    head = deleteAtBeginning(head);

    printf("Updated List:  ");
    printList(head); 

    return 0;
}
