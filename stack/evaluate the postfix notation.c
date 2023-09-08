#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int x) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
int pop() 
{
    if (top == NULL) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}
int isEmpty() 
{
    return top == NULL;
}
int evaluatePostfix(char* expression) 
{
    int i = 0;
    while (expression[i] != '\0') 
    {
        if (isdigit(expression[i])) 
        {
            int operand = expression[i] - '0';
            push(operand);
        } 
        else 
        {
            int operand2 = pop();
            int operand1 = pop();
            switch (expression[i]) 
            {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
        i++;
    }
    return pop();
}
int main() 
{
    char postfixExpression[] = "23*4+";
    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);
    return 0;
}
