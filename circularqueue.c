#include <stdio.h>
#include <stdlib.h>
 
#define size 3
 
void insert();
void delete();
void display();
int q[size];
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    } 
} 
 
void insert()
{
    int num;
    printf("enter number to be inserted");
    scanf("%d",&num);
    if (front = 0 && rear == size - 1||front > rear+1)
    scanf("%d",&num);
    else if(rear == -1)
    {
	rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
	q[rear] = num;
	
} 
 
void delete()
{
    if (front == - 1 )
    {
        printf("Queue Underflow \n");
        return ;
    }
	 else if (front == rear)
    {
        printf("\n %d deleted", q[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q[front]);
        front = front + 1;
    }
} 
 
void display()
{
    int i;
   if (front > rear)
    {
        for (i = front; i < size; i++)
        {
            printf("%d ", q[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", q[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", q[i]);
    }
}
