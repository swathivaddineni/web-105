#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* reverseLL(struct node *head)
{
    if(head == NULL){
        return head;
    }
    else {
        struct node *current = NULL;
        struct node *nextLL = head->next;
        head->next=NULL;

        while(nextLL != NULL){
            current=nextLL;
            nextLL=nextLL->next;
            current->next=head;
            head=current;
        }
    }
    return head;
}

struct node *push(struct node *head, int val)
{
    struct node *newptr=malloc (sizeof(struct node));
    newptr->data=val;
    newptr->next=head;
    head=newptr;
    return head;
}

struct node *addition(struct node *head1, struct node *head2)
{
    if(head1->data==0) {
        return head2;
    }
    if(head2->data==0) {
        return head1;
    }

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    int carry =0, sum;

    while(ptr1 || ptr2){
        sum = 0;
        if(ptr1){
            sum+=ptr1->data;
        }
        if(ptr2){
            sum+=ptr2->data;
        }
        sum+=carry;
        carry = sum /10;
        sum = sum%10;

        head3= push(head3, sum);

        if(ptr1){
            ptr1=ptr1->next;
        }
        if(ptr2){
            ptr2=ptr2->next;
        }
    }
    if(carry){
        head3=push(head3, carry);
    }
    return head3;
}
struct node *add_node(struct node *head, int val)
{
    struct node *newnode =  malloc(sizeof (struct node));
    newnode->data=val;
    newnode->next=NULL;

    newnode->next=head;
    head=newnode;
    return head;
}

struct node *createLL(struct node *head, int n)
{
    while (n!=0)
   {
        head=add_node(head, n%10);
        n=n/10;
    }
    return head;
}

void print(struct node *head)
{
    struct node *temp=head;
    if(head == NULL)
    {
        printf("NO Number.");
    }

    else
    {
        while(temp->next!=NULL)
        {
            printf("%d  ", temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d  %d", &a, &b);

    printf("Linked List representation of 1st number: \n");
    struct node *head1 = NULL;
    head1 = createLL(head1, a);
    print(head1);

    printf("\nLinked List representation of 2nd number: \n");
    struct node *head2 = NULL;
    head2 = createLL(head2, b);
    print(head2);

    printf("\nThe reversed linked list are: \n");
    head1= reverseLL(head1);
    head2= reverseLL(head2);
    print(head1);
    printf("\n");
    print(head2);


    struct node *head3=NULL;
    head3= addition(head1, head2);
    printf("\nThe resultant linked list is: \n");
    print(head3);
    return 0;
}
