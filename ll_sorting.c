#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node * Node;
Node getnode()
{
	Node p;
	p=(Node)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("memory could not be allocated\n");
		exit(0);
	}
}

Node insert(Node head, int item)
{
    Node p,q;
    q=getnode();
    q->data=item;
    p=head;
	if(head== NULL)
		return q;
    while(p->next!=NULL)
    {
       p=p->next;
       }
    p->next=q;
    q->next=NULL;
	return head;
}
void show(Node head)
{
	Node p;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

Node sort(Node head) {
	Node temp1, temp2, first;
	first = head;
	int swap;

	if(first == NULL)
		printf("Empty\n");
	else{
		for(temp1 = first;temp1->next != NULL; temp1=temp1->next){
			for(temp2=temp1->next;temp2 != NULL; temp2=temp2->next){
				if(temp1->data > temp2->data){
					swap = temp1->data;
					temp1->data = temp2->data;
					temp2->data = swap;
				}
			}
		}
	}
	return head;
}
Node concat(Node head1, Node head2){
	Node temp = head1;
	while(head1->next!=NULL){
		head1 = head1->next;
	}
	head1->next = head2;
	return temp;
}


Node reverse(Node first){
	Node curr, prev, temp;
	prev = NULL;
	curr = first;

	while(curr != NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	first = prev;
	return first;
}

void main(){
	Node head1 = NULL;
	Node head2 = NULL;
	int ch, e;
	
	printf("Enter your choice:\n1:Insert in 1st list\n2:Insert in 2nd list\n3:sort 1st list\n4:reverse 1st list\n5:concatinate\n6:sort 2nd list\n7:reverse 2nd list\n8:display 1st list\n9:display 2nd list\n10:exit\n");
		scanf("%d", &ch);

	do{
		

		switch(ch){
			case 1: printf("Enter element to be inserted \n");
				  scanf("%d",&e);
				  head1=insert(head1,e);
				  break;
          		case 2: printf("Enter element to be inserted \n");
				  scanf("%d",&e);
				  head2=insert(head2,e);
				  break;
			
          		case 3: head1=sort(head1);
				  break;
			case 4: head1=reverse(head1);
				  break;
			case 5: head1=concat(head1, head2);
				  break;
			case 6: head2=sort(head2);
				  break;

			case 7: head2=reverse(head2);
				  break;


			case 8: show(head1);
				break;
			case 9: show(head2);
				break;
			case 10: exit(0);
				break;
		}
           	printf("Enter your choice:\n");
           	scanf("%d",&ch);
           }while(ch!=10);
}
