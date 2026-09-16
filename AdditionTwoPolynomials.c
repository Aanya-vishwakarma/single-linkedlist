#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insertTerm(struct Node* head, int coeff, int exp) {
    if (coeff == 0) return head; 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;

    if (head == NULL) return new_node;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum_coeff = p1->coeff + p2->coeff;
            result = insertTerm(result, sum_coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } 
        else {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
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
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* polySum = NULL;

    poly1 = insertTerm(poly1, 5, 3);
    poly1 = insertTerm(poly1, 4, 2);
    poly1 = insertTerm(poly1, 2, 0);

    poly2 = insertTerm(poly2, 6, 2);
    poly2 = insertTerm(poly2, 3, 1);
    poly2 = insertTerm(poly2, 5, 0);

    printf("First Polynomial:  ");
    printPolynomial(poly1);

    printf("Second Polynomial: ");
    printPolynomial(poly2);

    polySum = addPolynomials(poly1, poly2);

    printf("Sum Polynomial:    ");
    printPolynomial(polySum); 

    return 0;
}
