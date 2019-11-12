/* AVL tree implementation in c
left rotation ,right rotation, insertion and deletion
and all traversals
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
	int ht;
};
struct node*root=NULL;

struct node *insert(struct node *,int);
struct node *delete_node(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
int height(struct node *);
struct node *rotateright(struct node *);
struct node *rotateleft(struct node *);
struct node *RR(struct node *);
struct node *LL(struct node *);
struct node *LR(struct node *);
struct node *RL(struct node *);
int BF(struct node *);

int main()
{
	struct node *root=NULL;
	int x,n,i,choice;
    printf("\n 1.Insert:");
    printf("\n 2.Delete:");
    printf("\n 3.Print:");
    printf("\n 4.Quit:");
	while(1)
	{
		printf("\n\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;

			case 2: printf("\nEnter a data:");
					scanf("%d",&x);
					root=delete_node(root,x);
					break;

			case 3: printf("\nPreorder sequence:\n");
					preorder(root);
					printf("\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;
            case 4:
                    exit(0);
                    break;
            default:
                    printf("\n Wrong Choice:\n");
                    break;
		}
	}
	return 0;
}

struct node * insert(struct node *temp,int x)
{
	if(temp==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
	}
	else
		if(x > temp->data)
        {
			temp->right=insert(temp->right,x);
			if(BF(temp)==-2)
				if(x>temp->right->data)
					temp=RR(temp);
				else
					temp=RL(temp);
		}
		else
			if(x<temp->data)
			{
				temp->left=insert(temp->left,x);
				if(BF(temp)==2)
					if(x < temp->left->data)
						temp=LL(temp);
					else
						temp=LR(temp);
			}

		temp->ht=height(temp);
		return(temp);
}

struct node * delete_node(struct node *temp,int x)
{
	struct node *p;
	if(temp==NULL)
	{
		return NULL;
	}
	else
		if(x > temp->data)
        {
			temp->right=delete_node(temp->right,x);
			if(BF(temp)==2)
				if(BF(temp->left)>=0)
					temp=LL(temp);
				else
					temp=LR(temp);
		}
		else
			if(x<temp->data)
			{
				temp->left=delete_node(temp->left,x);
				if(BF(temp)==-2)
					if(BF(temp->right)<=0)
						temp=RR(temp);
					else
						temp=RL(temp);
			}
			else
			{
				if(temp->right!=NULL)
				{
					p=temp->right;
					while(p->left!= NULL)
						p=p->left;
					temp->data=p->data;
					temp->right=delete_node(temp->right,p->data);

					if(BF(temp)==2)
						if(BF(temp->left)>=0)
							temp=LL(temp);
						else
							temp=LR(temp);
				}
				else
					return(temp->left);
			}
	temp->ht=height(temp);
	return(temp);
}

int height(struct node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return(0);

	if(temp->left==NULL)
		lh=0;
	else
		lh=1+temp->left->ht;

	if(temp->right==NULL)
		rh=0;
	else
		rh=1+temp->right->ht;

	if(lh>rh)
		return(lh);

	return(rh);
}

struct node * rotateright(struct node *x)
{
	struct node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

struct node * rotateleft(struct node *x)
{
	struct node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);

	return(y);
}

struct node * RR(struct node *temp)
{
	temp=rotateleft(temp);
	return(temp);
}

struct node * LL(struct node *temp)
{
	temp=rotateright(temp);
	return(temp);
}

struct node * LR(struct node *temp)
{
	temp->left=rotateleft(temp->left);
	temp=rotateright(temp);

	return(temp);
}

struct node * RL(struct node *temp)
{
	temp->right=rotateright(temp->right);
	temp=rotateleft(temp);
	return(temp);
}
int BF(struct node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return(0);

	if(temp->left==NULL)
		lh=0;
	else
		lh=1+temp->left->ht;

	if(temp->right==NULL)
		rh=0;
	else
		rh=1+temp->right->ht;

	return(lh-rh);
}

void preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d(Bf=%d)",temp->data,BF(temp));
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d(Bf=%d)",temp->data,BF(temp));
		inorder(temp->right);
	}
}
