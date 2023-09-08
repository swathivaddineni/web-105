#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
int isOperator(char ch) {
return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int precedence(char ch) {
if (ch == '^')
return 3;
else if (ch == '*' || ch == '/')
return 2;
else if (ch == '+' || ch == '-')
return 1;
else
return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
char stack[MAX_STACK_SIZE];
int top = -1;
int i, j = 0;
for (i = 0; infix[i] != '\0'; i++) {
char ch = infix[i];
if (isalnum(ch)) {
postfix[j++] = ch;
} else if (ch == '(') {
stack[++top] = ch;
} else if (ch == ')') {
while (top >= 0 && stack[top] != '(') {
postfix[j++] = stack[top--];
}
if (top >= 0 && stack[top] == '(') {
top--;
}
} else {
while (top >= 0 && precedence(stack[top]) >= precedence(ch)) {
postfix[j++] = stack[top--];
}
stack[++top] = ch;
}
}
while (top >= 0) {
postfix[j++] = stack[top--];
}
postfix[j] = '\0';
}
int main() {
char infix[MAX_STACK_SIZE];
char postfix[MAX_STACK_SIZE];
printf("Enter an infix expression: ");
gets(infix);
infixToPostfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
return 0;
}
