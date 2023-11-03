#include <stdio.h>
#include <stdlib.h>
struct Node 
{
int data;
int priority;
struct Node* next;
};
struct Node* newNode(int data, int priority) 
{
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = data;
temp->priority = priority;
temp->next = NULL;
return temp;
}
void insert(struct Node** head, int data, int priority) 
{
struct Node* temp = newNode(data, priority);

if (*head == NULL || priority < (*head)->priority) 
{
temp->next = *head;
*head = temp;
} 
else 
{
struct Node* current = *head;
while (current->next != NULL && current->next->priority <= priority) 
{
current = current->next;
}
temp->next = current->next;
current->next = temp;
}
}
void deleteHighestPriority(struct Node** head) 
{
if (*head == NULL)
{
printf("Priority queue is empty.\n");
} 
else 
{
struct Node* temp = *head;
*head = (*head)->next;
free(temp);
}
}
void display(struct Node* head) 
{
if (head == NULL) 
{

printf("Priority queue is empty.\n");
} 
else 
{
printf("Priority Queue: ");
while (head != NULL) 
{
printf("(%d, %d) ", head->data, head->priority);
head = head->next;
}
printf("\n");
}
}

int main() 
{
struct Node* pq = NULL;

insert(&pq, 5, 2);
insert(&pq, 10, 1);
insert(&pq, 15, 3);
insert(&pq, 25, 2);

display(pq);

deleteHighestPriority(&pq);

display(pq);

return 0;
}
