//write a c program to convert infix arithmetic expression to postfix expression.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for characters
typedef struct {
    char data[MAX];
    int top;
} CharStack;

// Stack structure for strings (used for postfix and prefix)
typedef struct {
    char data[MAX][MAX];
    int top;
} StringStack;

// Function to initialize character stack
void initCharStack(CharStack* stack) {
    stack->top = -1;
}

// Function to push to character stack
void pushChar(CharStack* stack, char c) {
    stack->data[++stack->top] = c;
}

// Function to pop from character stack
char popChar(CharStack* stack) {
    return stack->data[stack->top--];
}

// Function to get the top element of character stack
char peekChar(CharStack* stack) {
    return stack->data[stack->top];
}

// Function to check if character stack is empty
int isEmptyChar(CharStack* stack) {
    return stack->top == -1;
}

// Function to initialize string stack
void initStringStack(StringStack* stack) {
    stack->top = -1;
}

// Function to push to string stack
void pushString(StringStack* stack, char* str) {
    strcpy(stack->data[++stack->top], str);
}

// Function to pop from string stack
char* popString(StringStack* stack) {
    return stack->data[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    CharStack operators;
    initCharStack(&operators);
    int i, j = 0;
    for (i = 0; infix[i]; i++) {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            pushChar(&operators, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmptyChar(&operators) && peekChar(&operators) != '(') {
                postfix[j++] = popChar(&operators);
            }
            popChar(&operators); // pop '('
        } else if (isOperator(infix[i])) {
            while (!isEmptyChar(&operators) && precedence(peekChar(&operators)) >= precedence(infix[i])) {
                postfix[j++] = popChar(&operators);
            }
            pushChar(&operators, infix[i]);
        }
        printf("Postfix Step %d: %s\n", i, postfix);
    }

    while (!isEmptyChar(&operators)) {
        postfix[j++] = popChar(&operators);
        printf("Postfix Step %d: %s\n", i++, postfix);
    }
    postfix[j] = '\0';
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    CharStack operators;
    StringStack operands;
    initCharStack(&operators);
    initStringStack(&operands);

    int i;
    for (i = strlen(infix) - 1; i >= 0; i--) {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            char op[2] = {infix[i], '\0'};
            pushString(&operands, op);
        } else if (infix[i] == ')') {
            pushChar(&operators, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmptyChar(&operators) && peekChar(&operators) != ')') {
                char op1[MAX], op2[MAX], op[MAX], expr[MAX];
                strcpy(op1, popString(&operands));
                strcpy(op2, popString(&operands));
                sprintf(expr, "%c%s%s", popChar(&operators), op1, op2);
                pushString(&operands, expr);
            }
            popChar(&operators); // pop ')'
        } else if (isOperator(infix[i])) {
            while (!isEmptyChar(&operators) && precedence(peekChar(&operators)) > precedence(infix[i])) {
                char op1[MAX], op2[MAX], op[MAX], expr[MAX];
                strcpy(op1, popString(&operands));
                strcpy(op2, popString(&operands));
                sprintf(expr, "%c%s%s", popChar(&operators), op1, op2);
                pushString(&operands, expr);
            }
            pushChar(&operators, infix[i]);
        }
        printf("Prefix Step %d: %s\n", i, operands.data[operands.top]);
    }

    while (!isEmptyChar(&operators)) {
        char op1[MAX], op2[MAX], op[MAX], expr[MAX];
        strcpy(op1, popString(&operands));
        strcpy(op2, popString(&operands));
        sprintf(expr, "%c%s%s", popChar(&operators), op1, op2);
        pushString(&operands, expr);
        printf("Prefix Step %d: %s\n", i--, operands.data[operands.top]);
    }

    strcpy(prefix, popString(&operands));
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Final Postfix Expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Final Prefix Expression: %s\n", prefix);

    return 0;
}
