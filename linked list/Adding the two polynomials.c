#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient;
    int power;
    struct Term *next;
} Term;

Term *poly1, *poly2, *result;

Term *createPolynomial(int numTerms) {
    Term *head = NULL, *current = NULL;

    for (int i = 0; i < numTerms; i++) {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        newTerm->next = NULL;

        printf("Enter coefficient: ");
        scanf("%d", &newTerm->coefficient);

        printf("Enter power: ");
        scanf("%d", &newTerm->power);

        if (head == NULL) {
            head = newTerm;
            current = head;
        } else {
            current->next = newTerm;
            current = newTerm;
        }
    }

    return head;
}

void displayPolynomial(Term *head, char var) {
    Term *current = head;
    while (current != NULL) {
        printf("%d", current->coefficient);

        if (current->power != 0) {
            printf("%c^%d", var, current->power);
        }

        if (current->next != NULL) {
            printf(" + ");
        }

        current = current->next;
    }
}
Term *addPolynomials(Term *poly1, Term *poly2) {
    Term *head = NULL, *current = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        newTerm->next = NULL;

        if (head == NULL) {
            head = newTerm;
            current = head;
        } else {
            current->next = newTerm;
            current = newTerm;
        }

        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->power == poly2->power) {
                newTerm->power = poly1->power;
                newTerm->coefficient = poly1->coefficient + poly2->coefficient;
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->power < poly2->power) {
                newTerm->power = poly2->power;
                newTerm->coefficient = poly2->coefficient;
                poly2 = poly2->next;
            } else {
                newTerm->power = poly1->power;
                newTerm->coefficient = poly1->coefficient;
                poly1 = poly1->next;
            }
        } else if (poly1 != NULL && poly2 == NULL) {
            newTerm->power = poly1->power;
            newTerm->coefficient = poly1->coefficient;
            poly1 = poly1->next;
        } else if (poly1 == NULL && poly2 != NULL) {
            newTerm->power = poly2->power;
            newTerm->coefficient = poly2->coefficient;
            poly2 = poly2->next;
        }
    }

    return head;
}

int main() {
    int numTerms1, numTerms2;
    printf("Enter the number of terms for polynomial 1: ");
    scanf("%d", &numTerms1);
    poly1 = createPolynomial(numTerms1);

    printf("Enter the number of terms for polynomial 2: ");
    scanf("%d", &numTerms2);
    poly2 = createPolynomial(numTerms2);

    char variable;
    printf("Enter the variable: ");
    scanf(" %c", &variable);

    printf("Polynomial 1: ");
    displayPolynomial(poly1, variable);
    printf("\nPolynomial 2: ");
    displayPolynomial(poly2, variable);

    result = addPolynomials(poly1, poly2);
    printf("\nAdded polynomial: ");
    displayPolynomial(result, variable);

    return 0;
}
