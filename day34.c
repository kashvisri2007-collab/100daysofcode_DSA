#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push function
void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop function
int pop()
{
    struct node *temp;
    int val;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

// Function to evaluate postfix
int evaluatePostfix(char exp[])
{
    int i = 0, op1, op2;

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0'); // convert char to int
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}