#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	struct node *prev;
	int data;
};
typedef struct node* Node;
Node start = NULL;
Node insert_beg(Node start);
Node insert_end(Node start);
Node delete_beg(Node start);
Node delete_end(Node start);
Node delete_val(Node start);
Node display(Node start);
void main()
{
	int ch;
	do
	{
		printf("Enter your choice\n");
		printf("1:Insert at beginning\n2:Insert at end\n3:Delete from beg\n4:Delete from end\n5:Delete a specific value\n6:Display\n0:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: start = insert_beg(start);
			break;
		case 2: start = insert_end(start);
			break;
		case 3: start = delete_beg(start);
			break;
		case 4: start = delete_end(start);
			break;
		case 5: start = delete_val(start);
			break;
		case 6: start = display(start);
			break;
		}
	}while(ch!=0);
}
Node insert_beg(Node start)
{
	Node ptr,new_node;
	int val;
	new_node = (Node)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d",&val);
	new_node->data = val;
	if(start == NULL)
	{
		start = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else 
	{
		new_node->prev = NULL;
		new_node->next = start;
		start = new_node;
	}
	return start;
}
Node insert_end(Node start)
{
	Node ptr,new_node;
	int val;
	new_node = (Node)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d",&val);
	new_node->data = val;
	if(start == NULL)
	{
		start = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else 
	{
		ptr = start;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
		new_node->prev = ptr;
		new_node->next = NULL;
	}
	return start;
}
Node delete_beg(Node start)
{
	Node ptr;
	if(start == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
	ptr = start;
	start = ptr->next;
	start->prev = NULL;
	}
	return start;
}
Node delete_end(Node start)
{
	Node ptr,preptr;
	if(start == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
	ptr = start;
	while(ptr->next!=NULL)
	{
	preptr = ptr;
	ptr = ptr->next;
	}
	preptr->next = NULL;
	}
	return start;
}
Node delete_val(Node start)
{
	Node ptr,preptr;
	int val;
	printf("Enter the value to be deleted\n");
	scanf("%d",&val);
	ptr = start;
	if(start == NULL)
	{
		printf("Linked list is empty\n");
	}
	else 
	{
		while(ptr->data!=val)
		{
			ptr = ptr->next;
		}
		preptr = ptr->prev;
		if(ptr==start)
		{
			start = delete_beg(start);
		}
		else if(ptr->next==NULL)
		{
			start = delete_end(start);
		}
		else
		{
			preptr->next = ptr->next;
			ptr->next->prev = preptr;
		}
	}
	return start;
}
Node display(Node start)
{
	Node ptr;
	ptr = start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	return start;
}
