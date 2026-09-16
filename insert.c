#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    return new_node;
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

    head = insertAtBeginning(head, 78);
    head = insertAtBeginning(head, 56);
    head = insertAtBeginning(head, 34);
    head = insertAtBeginning(head, 23);

    printf("Original List: ");
    printList(head);

    head = insertAtBeginning(head, 54);

    printf("Updated List:  ");
    printList(head); 

    return 0;
}
