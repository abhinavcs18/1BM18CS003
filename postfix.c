#include<stfdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void push( char s[100], int *t, char c)
{
	if(*t==99)
		printf("stack overflow");
	else
	{
		*t=*t+1;
		s[*t] = c;
	}
char pop( char [100], int *t
{
	if(*t == -1)
	{
		printf("stack underflow");
	}
	else
	{
		return s[*t--];
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
void main()
{
char s[100],st[100];
int top = -1,n;
printf("enter the length of infix expression");
scanf("%d",&n);
for(int i=0;i<n+1;i++)
{
	scanf("%c",&st[i]);
	if(st[i]=='A')
	{
		printf("%c",st[i]);
	}
