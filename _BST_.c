#include<stdio.h>
#include<stdlib.h>

struct binary_tree
{
	struct binary_tree *lptr;
	int data;
	struct binary_tree *rptr;
};
typedef struct binary_tree node;

node *root,*new,*pre,*save;

int i=1;
void construct(node *);
void in_order(node *);
void pre_order(node *);
void post_order(node *);
void search(node *);
void count_node();
void delete_node(node *,int);
void min_max(node *);
void height_of_bst(node *);

int count=0;
int d;
main()
{
	int n,x;
	
	x:
	printf("\n1 - Create tree\n");
	printf("2 - In_order traversal\n");
	printf("3 - Pre_order traversal\n");
	printf("4 - Post_order traversal\n");
	printf("5 - Search\n");
	printf("6 - Count No. of nodes\n");
	printf("7 - Delete_node\n");
	printf("8 - Max_ and Min_Data\n");
	printf("9 - height of binary tree\n");
	printf("10 - Exit\n");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1:
			new=(node *)malloc(sizeof(node));
			printf("Enter data : ");
			//fflush(stdin);
			scanf("%d",&d);
			new->data=d;
			new->lptr=NULL;
			new->rptr=NULL;
			construct(root);
			break;
		case 2:
			in_order(root);
			break;
		case 3:
			pre_order(root);
			break;
		case 4:
			post_order(root);
			break;
		case 5:
			
			printf("\nEnter data: ");
			//fflush(stdin);
			scanf("%d",&d);
			search(root);
			break;
		case 6:
			count_node();
			break;
		case 7:
			printf("Enter Data : ");
			//fflush(stdin);
			scanf("%d",&d);
			delete_node(root,d);
			break;
		case 8:
			min_max(root);
			break;
		case 9:
			height_of_bst(root);
			break;
		case 10:
			exit(0);
			break;
		default:
			printf("\nEntered wrong entry\n");
			break;
	}
	goto x;
}

void construct(node *temp)
{		
	node *save,*pre;
	
	if(count==0)
	{
		root=new;
		printf("%d",root->data);
		count++;
	}
	else
	{
		save=temp;
		
		if(new->data < save->data)
		{
			pre=save;
			if(save->lptr!=NULL)
			construct(save->lptr);
			else
			{
			
				if(new->data < pre->data)
				{
				pre->lptr=new;
				//printf("left: %d",pre->lptr->data);
				}
				else
				{
				pre->rptr=new;
				//printf("left: %d",pre->rptr->data);
				}
				count++;
			}
				
		}
		else
		{
			pre=save;
			if(save->rptr!=NULL)
			construct(save->rptr);
			
			else
			{
			
				if(new->data < pre->data)
				{
				pre->lptr=new;
				//printf("right: %d",pre->lptr->data);
				}
				else
				{
				pre->rptr=new;
				//printf("right: %d",pre->rptr->data);
				}
				count++;
			}
		}
		
	}
	
}

void in_order(node *temp)
{
	if(temp!=NULL)
	{
		in_order(temp->lptr);
		printf("%d ",temp->data);
		in_order(temp->rptr);
	}
	
}

void pre_order(node *temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		pre_order(temp->lptr);
	
		pre_order(temp->rptr);
	}
	
}

void post_order(node *temp)
{
	if(temp!=NULL)
	{
		
		post_order(temp->lptr);
	
		post_order(temp->rptr);
		printf("%d ",temp->data);
	}
	
}

void count_node()
{
	printf("\nNo.of nodes in Tree : %d\n",count);
}

void search(node *temp)
{
	
	if(count==0)
	{
		printf("Tree is empty\n");
	}
	else
	{
		
		if(d < temp->data)
		 {
		 	if(temp->lptr!=NULL)
			search(temp->lptr);
			else
			printf("Data not found..!!\n");
		}
		
		
		else if(d > temp->data)
		{	
			if(temp->rptr!=NULL)
			search(temp->rptr);
			else
			printf("Data not found..!!\n");
		}
			
		else if(d == temp->data)
		printf("Your data %d found in Tree\n",d);
		
		else
		printf("Data not found..!!\n");
	}

}

void delete_node(node *temp,int key)
{
	node *p;
	
	if(temp==NULL)
	{
		printf("\nData Not Found in Tree\n");
	}
	else if(key < temp->data)
	{	
		pre=temp;
		delete_node(temp->lptr,key);
	}
	else if(key > temp->data)
	
	{
		pre=temp;
		delete_node(temp->rptr,key);
	}
	
	else
	{
		//printf("\n Data found : %d, %d",temp->data,pre->data);
		
		
		if(temp->lptr==NULL && temp->rptr==NULL)
		{
			
			if(pre->lptr==temp)
			pre->lptr = NULL;
			else 
			pre->rptr=NULL;
			
			free(temp);
			printf("\nNode deleted\n");
		}
		
		else if(temp->lptr!=NULL && temp->rptr==NULL)
		{
			if(temp==root)
			{
		
				root=root->lptr;
				free(temp);
			}
			
			else
			{
			
				if(pre->lptr==temp)
				pre->lptr = temp->lptr;
				else
				pre->rptr=temp->lptr;
				
				free(temp);
				
			}
				printf("\nNode deleted\n");
		}
		
		else if(temp->lptr==NULL && temp->rptr!=NULL)
		{
				if(temp==root)
			{
				root=root->rptr;
				free(temp);
			}
			else
			{
			
				if(pre->lptr==temp)
				pre->lptr = temp->rptr;
				else
				pre->rptr=temp->rptr;
				
				free(temp);
				
			}
				printf("\nNode deleted\n");
		}
		
		else
		{
			save=temp->lptr;
			
			while(save->rptr!=NULL)
				save=save->rptr;
				
			//printf("value left high: %d\n",save->data);
			
			temp->data=save->data;
			
			//printf("value temp: %d\n",temp->data);
			
			pre=temp;
			temp=temp->lptr;
			
			//printf("value temp: %d\n",temp->data);
			
			delete_node(temp,save->data);
		}
		
	}
}

void min_max(node *temp)
{
	node *save,*save1;
	
	if(temp->lptr==NULL && temp->rptr==NULL)
	printf("\nMax. and Min. value are equal : %d\n",root->data);
	
	else 
	{
		save=temp;
		while(save->lptr!=NULL)
		save=save->lptr;
		
		save1=temp;
		while(save1->rptr!=NULL)
		save1=save1->rptr;
		
		printf("\nMax.value : %d\nMin.value: %d\n",save1->data,save->data);
	}
	
}

void height_of_bst(node *temp)
{
	node *save; int h=0,h1=0;
	save=temp;
	//height of left sub tree...
	while(save->lptr!=NULL || save->rptr!=NULL)
	{
		if(save->lptr==NULL)
		save=save->rptr;
		else
		save=save->lptr;
		
		h++;
	}
	// height of right sub-tree...
	save=temp;
	while(save->lptr!=NULL || save->rptr!=NULL)
	{
		if(save->rptr==NULL)
		save=save->lptr;
		else
		save=save->rptr;
		
		h1++;
	}
	if(h > h1)
	printf("Height of tree : %d\n",h+1);
	else if (h1 > h)
	printf("Height of tree : %d\n",h1+1);
	else
	printf("Height of tree : %d\n",h+1);
}



















