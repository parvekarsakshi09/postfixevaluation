

#include<stdio.h>
char stack[20];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
    return 1;
    else
 return stack[top--];
}
int priority(char x)
{
     if(x=='(')
    return 0;
    else if(x=='+'|| x=='-')
    return 1;
    else if(x=='*'|| x=='/')
    return 2;
}

int main()
{
char exp[20];
char *e,x;
int num1,num2,num3,n;

printf("enter the expression");
scanf("%s",exp);
e=exp;
while(*e!='\0')
{
    if(isdigit(*e))
    {
        n=*e-48;
        push(n);

    }
    else
    {
        num1=pop();
        num2=pop();
        switch(*e)
        {
            case '-':
            {
            num3=num2-num1;
            break;
            }
            case '+':
            {
            num3=num1+num2;
            break;
            }
            case '*':
            {
            num3=num1*num2;
            break;
            }
            case '/' :
            {
            num3=num2/num1;
            break;
            }
        }
        push(num3);
    }
e++;
}
printf("%d",pop());

}