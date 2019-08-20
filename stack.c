#include<stdio.h>
int top=0 ;
int stack[10] ;
void push(int n)
{
    if(top>=10)
    {
        printf("Stack Overflow") ;
        return ;
    }
    stack[top]=n ;
    top++ ;
}
int pop(void)
{
    if(top--<=0)
    {
        printf("Stack Underflow\n") ;
        return  ;
    }
    return stack[top] ;

}
void display(void)
{
    if(top==0)
    {
        printf("Stack is empty") ;
    }
    else
    {
        for(int x=top-1;x>=0;x--)
        {
            printf("%d\n",stack[x]) ;
        }

    }
}
void main()
{
    int n;
    char c ;
    printf("for pushing an element print y and for not print n\n") ;
    scanf("%c",&c) ;
    while(c=='y')
    {
        printf("give a number\n") ;
        scanf("%d",&n) ;
        push(n) ;
        printf("wanna push \n") ;
        fflush(stdin) ;
        scanf("%c",&c) ;
    }
    printf("for popping element press y\n") ;
    fflush(stdin) ;
    scanf("%c",&c) ;
    while(c=='y')
    {
        printf("%d is popped out of the stack\n",pop()) ;
        printf("wanna pop again\n") ;
        fflush(stdin) ;
        scanf("%c",&c);
    }
    display() ;

}