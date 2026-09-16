#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;          
    int exp;            
    struct Node* next;  
};

struct Node* insertTerm(struct Node* head, int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("0\n");
        return;
    }

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        
        temp = temp->next;
        
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;

    poly = insertTerm(poly, 5, 3);
    poly = insertTerm(poly, 4, 2);
    poly = insertTerm(poly, 2, 1);
    poly = insertTerm(poly, 7, 0);

    printf("Polynomial expression: ");
    printPolynomial(poly); 

    return 0;
}
