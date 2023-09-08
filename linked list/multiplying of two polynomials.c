#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int power;
    struct Node *next;
} Node;

Node *poly1, *poly2, *result;

Node *createPolynomial(int numTerms) {
    Node *head = NULL, *current = NULL;
    for (int i = 0; i < numTerms; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;

        printf("Enter coefficient: ");
        scanf("%d", &newNode->coefficient);
        printf("Enter power: ");
        scanf("%d", &newNode->power);

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

void displayPolynomial(Node *head, char var) {
    Node *current = head;
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

Node *multiply(Node *poly1, Node *poly2) {
    Node *result = NULL;

    for (Node *curr1 = poly1; curr1 != NULL; curr1 = curr1->next) {
        for (Node *curr2 = poly2; curr2 != NULL; curr2 = curr2->next) {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = result;
            result = newNode;
            newNode->power = curr1->power + curr2->power;
            newNode->coefficient = curr1->coefficient * curr2->coefficient;
        }
    }
    return result;
}
Node *combineTerms(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *runner = current;
        while (runner->next != NULL) {
            if (runner->next->power == current->power) {
                current->coefficient += runner->next->coefficient;
                Node *temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return head;
}

void quickSort(Node *start, Node *end) {
    if (start == NULL || start == end || start == end->next) {
        return;
    }

    Node *pivotPrev = start;
    Node *curr = start;
    int pivotCoefficient = end->coefficient;

    while (start != end) {
        if (start->coefficient < pivotCoefficient) {
            pivotPrev = curr;
            int tempCoefficient = curr->coefficient;
            int tempPower = curr->power;
            curr->coefficient = start->coefficient;
            curr->power = start->power;
            start->coefficient = tempCoefficient;
            start->power = tempPower;
            curr = curr->next;
        }
        start = start->next;
    }

    int tempCoefficient = curr->coefficient;
    int tempPower = curr->power;
    curr->coefficient = end->coefficient;
    curr->power = end->power;
    end->coefficient = tempCoefficient;
    end->power = tempPower;

    pivotPrev = curr;

    quickSort(start, pivotPrev);
    quickSort(pivotPrev->next, end);
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

    result = multiply(poly1, poly2);
    result = combineTerms(result);
    quickSort(result, NULL);

    printf("\nMultiplied and sorted polynomial: ");
    displayPolynomial(result, variable);

    return 0;
}
