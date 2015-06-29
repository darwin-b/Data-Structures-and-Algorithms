#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int v2;

struct node
{
   struct node *up;
   struct graph *nt;
}*v;

struct graph
{
   struct graph *next; 
   struct graph *prev;
   struct node *up;
   int colour;
   struct graph * p;
   int d;
   int value;

}*root1,*b[2000],*temp,*head,*tail,*u;


struct graph * enqueue(struct graph * node) 
{
  if(head==NULL)
      {
      head=(struct graph *) malloc(sizeof(struct graph));
    
   
    head=node;
    head->prev=NULL;
    tail=head;
   
       }
     else
     { 
       temp=(struct graph *) malloc(sizeof(struct graph));  
        temp=node;
        tail->prev=temp;
        tail=temp;
        tail->prev=NULL;
      }
 }               
        
struct graph *dequeue()
{ 
struct graph * temp1;
  if(head==NULL) 
  {
      return NULL;     
   }
   else
   {
    temp1=head;
   temp=head->prev;
   free(head);
   head=temp;  
   return(temp1);
   } 
}

struct node *cnode(int e)
{
   struct node *temp = (struct node *) malloc(sizeof(struct node 	));
   temp->nt = b[e];
   return temp;
}


struct graph * creategraph(int e)
 {
    struct graph *temp= (struct graph *) malloc(sizeof(struct graph ));
  
     temp->colour=1;
     temp->d=INT_MAX;
     temp->value=e;
     temp->up=NULL;
     return (temp);
 }  


struct graph * insert(struct graph *root,struct graph *node)
{
   if(root==NULL)
    {
      return(node);
    }
   else
     {
         root->next=insert(root->next,node);
     }
  return root;
}

void print(int n)
{
  struct graph *temp;
  struct node *end;
  int i;

  for(i=0;i<n;i++)
  {
     end=b[i]->up;
      while(end!=NULL)
      {
	 printf("%d",end->nt->value);
         printf( " " );
         end=end->up;

      }
      printf("\n");
   }

}

int m1[1000],n1[1000],save[1000],t2=0,ctr=0,uni=0;

int main()
{
  	struct node *temp1,*temp2;
	struct node *end;

	int x,i=0,j,e,e1,e2,v1,c,s,n;

	scanf("%d%d",&n,&e);

	for(i=0;i<e;i++)
	{
  	scanf("%d %d",&m1[i],&n1[i]);
	}

	int i1;
	for(i1=-1;i1<e;i1++)
	{
		for(i=1;i<=n;i++)
		{
		  b[i]= creategraph(i);
		}
		for(i=0;i<e;i++)
		{
		  c=0;
		 if(i!=i1 || i1==-1)
 		{
			  v1=m1[i];
			  v2=n1[i];
  
		  struct node *temp1;
		  temp1 = cnode(v2);

  struct node *temp2;
  temp2 = cnode(v1);

  end= b[v1]->up;
  if(b[v1]->up==NULL)
  {
    b[v1]->up = temp1;
  }
  else{
  while(end->up!=NULL)
  {
    end=end->up;
  }
  end->up = temp1;
  }
  //printf("%d",b[v1]->up->nt->value);
  
  end= b[v2]->up;
  if(b[v2]->up==NULL)
  {
    b[v2]->up = temp2;
  }
  else{
  while(end->up!=NULL)
  {
    end=end->up;
  }
  end->up = temp2;
  }
 }
}

int visited[1000];
struct node* v;

for(i=1;i<=n;i++)
{
  visited[i]=0;
}

int compnum=0;

for(i=1;i<=n;i++)
{
  if(!visited[i])
   {
      compnum++;
     enqueue(b[i]);
      visited[i]=1;
    for(;head!=NULL;)
     {
         u=dequeue();
           v=u->up;
  for(;v!=NULL;)
  {
     if(visited[v->nt->value]==0)
       {
           visited[v->nt->value]=1;
          enqueue(v->nt);
       }
      v=v->up;
   }
  }
}
}

	if(i1==-1)
	{
	uni=compnum;
	}
	else
	{
		if(compnum>uni)
		{
		//printf("%d\n",compnum);
		save[t2]=i1;
		t2++;
		}
	}
}


int t3;
printf("count -- %d\n",t2);
for(t3=0;t3<t2;t3++)
{
  printf("%d %d\n",m1[save[t3]],n1[save[t3]]);
}

return 0;
}
  


