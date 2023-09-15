#include<stdio.h>
#define SIZE 100

char stack[SIZE];
char prefix[SIZE];
int top = -1;


void push(int n)
{
    top++;
    if(top >= SIZE )
    {
        printf("Stack out of bound");
        return;
    }

    stack[top] = n;
}

int pop()
{
    if(top < 0)
    {
        printf("Stack empty");
        return -9999999;
    }
    return (stack[top--]);
}

int isOperand(char c)
{
    switch(c)
    {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%': return 1;
        default : return 0;
    }
}

int main()
{
    printf("Enter prefix:\n");
    scanf("%s",prefix);

    int i=0;
    for(i=0;prefix[i]!='\0';i++);
    i--;

    while(i>=0)
    {
        if(isOperand(prefix[i]) == 0)
        {
            push(prefix[i]-48);
        }
        else
        {
            int res = 0;
            int a = pop();
            int b = pop();

            switch(prefix[i])
            {
                case '+':
                    res = a+b;
                    break;
                case '-':
                    res = a-b;
                    break;
                case '*':
                    res = a*b;
                    break;
                case '/':
                    res = a/b;
                    break;
                case '%':
                    res = a%b;
                    break;
                default : res = 0;
            }

            push(res);

        }
        i--;
    }

    printf("Answer = %d",pop());

    return 0;
}
