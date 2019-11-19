#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node * NODE;
NODE getnode(int item)
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	p->data=item;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
NODE insert(NODE root,int item)
{
	if(root==NULL)
		return getnode(item);
	if(item<root->data)
		root->lchild=insert(root->lchild,item);
	else if(item>=root->data)
		root->rchild=insert(root->rchild,item);
	return root;
}
void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->lchild);
	printf("%d\n",root->data);
	inorder(root->rchild);
}
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d\n",root->data);
	preorder(root->lchild);
	
	preorder(root->rchild);
}
void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->lchild);
	
	postorder(root->rchild);
	printf("%d\n",root->data);
}
int main()
{
	int item,ch,n,i;
	NODE root=NULL;
	printf("enter\n1.insert\n2.inorder\n3.preorder\n4.postorder\n-1.exit\n");
	scanf("%d",&ch);
	while(ch!=-1)
	{
		switch(ch)
		{
			case 1:printf("enter the no.of items\n");
				scanf("%d",&n);
				printf("enter the items\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&item);
					root=insert(root,item);
				}
				break;
			case 2: inorder(root);
				break;
			case 3: preorder(root);
				break;
			case 4: postorder(root);
				break;
			default:printf("invalid input\n");
		}
		printf("next choice\n");
		scanf("%d",&ch);
	}
	return 0;
}
