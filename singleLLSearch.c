#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int searchList(struct Node* head, int target) {
    struct Node* temp = head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == target) {
            return index; 
        }
        
        temp = temp->next;
        index++;
    }

    return -1; 
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

    int target1 = 56;
    int target2 = 99;

    int pos1 = searchList(head, target1);
    if (pos1 != -1) {
        printf("Element %d found at index %d.\n", target1, pos1);
    } else {
        printf("Element %d not found.\n", target1);
    }

    int pos2 = searchList(head, target2);
    if (pos2 != -1) {
        printf("Element %d found at index %d.\n", target2, pos2);
    } else {
        printf("Element %d not found.\n", target2);
    }

    return 0;
}
