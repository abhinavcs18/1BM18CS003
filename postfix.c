#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void push( char c,char s[100],int *t)
{
	if(*t==99)
		printf("stack overflow");
	else
	{
		*t=*t+1;
		s[*t] = c;
	}
}
char pop( char s[100], int *t)
{
	if(*t == -1)
	{
		printf("stack underflow");
		exit(0);
	}
	else
	{
		return s[(*t)--];
	}
}
int pre(char c)
{
	if(c=='/' || c=='*')
	return 2;
	else if(c=='^')
	return 3;
	else if(c=='+'||c=='-')
	return 1;
	else
	return 0;
}
int main()
{
	char stack[100],infix[100];
	char e;
	int top=-1;
	printf("Enter the infix expression");
        scanf("%s",infix);

	int i=0;
	int j;
	while(infix[i]!='\0')
	{
		if((infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='a'&&infix[i]<='z'))
			printf("%c",infix[i]);
		else if(infix[i]=='(')
			push(infix[i],stack,&top);
		else if(infix[i]==')')
		{
			while((e=pop(stack,&top))!='(')
				printf("%c",e);
		}
		else
		{
			while(pre(stack[top])>=pre(infix[i]))
			printf("%c",pop(stack,&top));
			push(infix[i],stack,&top);
		
			
		}
		i++;
	}

	while(top!=-1)
	{
		printf("%c",pop(stack,&top));

	}
	return 0;
}
