#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct Node* result = NULL;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}
void split(struct Node* source, struct Node** front, struct Node** back) 
{
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL)
     {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}
void mergeSort(struct Node** headRef) 
{
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    if (head == NULL || head->next == NULL)  
    {
        return;
    }

    
    split(head, &a, &b);

    
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge(a, b);
}
void append(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) 
    {
        *headRef = newNode;
        return;
    }

    struct Node* last = *headRef;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
}
void printList(struct Node* head)
 {
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &data);
        append(&head, data);
    }
    mergeSort(&head);
    printf("Sorted list:\n");
    printList(head);

    return 0;
}

