#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *,int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int main(int argc, char *argv[])
{
	int val,option;
	do{
		printf("\n******MAIN MENU********\n");
		printf("!: PUSH\n");
		printf("2: POP\n");
		printf("3: DISPLAY\n");
		printf("0: EXIT\n");
		printf("Enter your option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: 
				printf("Enter the number to be inserted\n");
				scanf("%d",&val);
				top = push(top,val);
				break;
			case 2: 
				top = pop(top);
				break;
			case 3:
				top = display(top);
				break;
		}
	   }while(option!=0);
	return 0;
}
struct stack *push(struct stack *top,int val)
{
	struct stack *ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack));
	ptr -> data = val;
	if(top == NULL)
	{
		ptr -> next = NULL;
		top = ptr;
	}
	else
	{
		ptr -> next = top;
		top = ptr;
	}
	return top;
}
struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top == NULL)
	printf("Stack Underflow\n");
	else
	{
		top = top -> next;
		printf("the value being deleted is: %d",ptr -> data);
		free(ptr);
	}
	return top;
}
struct stack *display(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top == NULL)
	{
	printf("Stack is empty\n");
	}
	else
	{
		while(ptr!= NULL)
		{
			printf("%d", ptr -> data);
			ptr = ptr -> next;
		}
	}
	  return top;
}

