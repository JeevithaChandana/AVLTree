/* Binary tree implementation in c
insertion ,deletion,searching,inorder,preorder,postorder  traversal,finding the minimum.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};
struct node *root = NULL;
void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;
      while(1) {
         parent = current;
         if(data < parent->data) {
            current = current->leftChild;
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }
         else {
            current = current->rightChild;
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
struct node* search(int data) {
   struct node *current = root;
   while(current->data != data) {
      if(current != NULL)
      if(current->data > data) {
         current = current->leftChild;
      }
      else {
         current = current->rightChild;
      }
      if(current == NULL) {
         return NULL;
      }
   }
   return current;
}
struct node* findMin(struct node*node)
{
    struct node* current=node;
    while(current->leftChild!=NULL)
    {
        current=current->leftChild;

    }
    return current;
}
struct node* delete_node(struct node* root,int data)
{
	if(root==NULL)
		return root;
	if(data< root->data)
	{
		root->leftChild= delete_node(root->leftChild,data);
	}
	else if(data> root->data)
	{
		root->rightChild= delete_node(root->rightChild,data);
	}
	else
	{
		if(root->leftChild==NULL&&root->rightChild==NULL)
		{
			free(root);
			root=NULL;
			return root;
		}
		else if(root->leftChild==NULL)
		{
			struct node* temp=root;
			root=root->rightChild;
			free( temp);
			return root;
		}
		else if(root->rightChild==NULL)
		{
			struct node* temp=root;
			root=root->leftChild;
			free(temp);
			return root;
		}
		else
		{
			struct node*temp=findMin(root->rightChild);
			root->data=temp->data;
			root->rightChild=delete_node(root->rightChild,temp->data);
		}
	}
	return root;
}

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);
   }
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);
      inorder_traversal(root->rightChild);
   }
}
void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);
   }
}
int main() {
    int i,s,data,del_ele;
    int choice;
            printf("\n 1.Insert the element");
            printf("\n 2.search the given element");
            printf("\n 3.Delete the given element");
            printf("\n 4.PreOrder Traversal");
            printf("\n 5.postOrder Traversal");
            printf("\n 6.inorder Traversal");
            printf("\n 7.Minimum element");
    while(1)
        {
            printf("\n enter the choice");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                        printf("\nenter the data u want to insert");
                        scanf("%d",&data);
                        insert(data);
                        break;
                case 2:
                        printf("\nenter the element u want to search");
                        scanf("%d",&s);
                        struct node * temp = search(s);
                        if(temp != NULL) {
                            printf("\nElement found");
                        }else {
                            printf("\nElement not found");
                        }
                        break;
                case 3:
                        printf("\nenter the element u want to delete");
                        scanf("%d",&del_ele);
                        delete_node(root,del_ele);
                        break;
                case 4:
                        printf("\npre order traversal");
                        pre_order_traversal(root);
                        printf("\n");
                        break;
                case 5:
                        printf("\npost order traversal");
                        post_order_traversal(root);
                        printf("\n");
                        break;
                case 6:
                        printf("\nin order traversal");
                        inorder_traversal(root);
                        printf("\n");
                        break;
                case 7:
                        printf("\nfinding the minimum");
                        temp=findMin(root);
                        printf("%d",temp->data);
                        printf("\n");
                        break;
                case 8:
                        exit(0);
                        break;
                default:
                        printf("\n Wrong Choice:\n");
                        break;
        }
}
return 0;
}
