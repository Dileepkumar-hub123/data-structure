#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int stack[20];
int top = -1;

void push(int x)
{
    if(top == 19)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1, n2, n3, num;

    printf("Enter the prefix expression: ");
    scanf("%s", exp);


    e = exp + strlen(exp) - 1;

    while(e >= exp)
    {
        if(isdigit(*e))
        {
            num = *e - '0';
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();

            switch(*e)
            {
                case '+': n3 = n1 + n2; break;
                case '-': n3 = n1 - n2; break;
                case '*': n3 = n1 * n2; break;
                case '/': n3 = n1 / n2; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(n3);
        }
        e--;
    }

    printf("\nResult of prefix expression %s = %d\n", exp, pop());
    return 0;
}
