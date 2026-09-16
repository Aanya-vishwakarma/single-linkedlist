#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverseList(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Traversing the list: ");
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        
        temp = temp->next;
    }
    printf("NULL\n");
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

    traverseList(head); 

    return 0;
}
