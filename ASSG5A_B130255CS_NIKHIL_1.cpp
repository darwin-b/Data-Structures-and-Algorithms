#include<iostream>
using namespace std;

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int v2,ti=0,t=0,c1;

struct arr
{
  int co;
  int val;
} d1[100];

struct node
{
   struct node *up;
   int cost;
   struct graph *nt;
};

struct graph
{
   graph *next; 
   graph *prev;
   node *up;
   int colour;
   int f;
   struct graph * p;
   int d;
   int value;

}*root1,*b[200],*temp,*head,*tail,*u;


struct node *cnode(int e)
{
   struct node *temp = new (node);
   temp->nt = b[e];
   temp->cost=c1;
   temp->up=NULL;
   return temp;
}


struct graph * creategraph(int e)
 {
    struct graph *temp= new (graph);
  
     temp->colour=1;
     temp->d=INT_MAX;
     temp->value=e;
     temp->p=NULL;
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

int a[100],l2=0,l1=0;
void push(int e)
{
  a[l2]=e;
 l2++;
}
void print(int n)
{
  struct graph *temp;
  struct node *end;
  int i;

  for(i=0;i<n;i++)
  {
     end=b[i]->up;
  printf("%d ",b[i]->value);
      while(end!=NULL)
      {
	 printf("%d",end->nt->value);
         printf( " " );
         end=end->up;

      }
      printf("\n");
   }

}


void col(int n)
{ int i;

   for(i=0;i<n;i++)
   {
    printf("%d ",b[i]->colour);

   }
   printf("\n\n");
}

struct graph *DFS_visit(struct graph *u,int n)
{ 

struct node *v;
  ti=ti+1;
//printf("%d ",u->value);
 
u->d=ti;
 u->colour=2;
    v=u->up;
  //  col(n);
   if(v==NULL)
   {
//     printf("HI ");
   }
   else
   while(v!=NULL)
   {
        if(v->nt->colour==1)
          {
            v->nt->p=u;
             DFS_visit(v->nt,n);
          }
        //printf("yes\n");
/*
        if(v->up==NULL)
        {
           break;
        } */

        v=v->up;
  }

push(u->value);

u->colour=3;
ti=ti+1;
u->f=ti;

}

int hash(int x,int n)
{
  return((x+t)%n);
}


int main()
{
struct node *temp1,*temp2;
struct node *end;

int x,i=0,j,e,e1,e2,v1,c,s,s1,n,y[100],y1[100];
char p1,p2,x1,x2;
scanf("%d%d\n",&n,&e);

scanf("%c\n",&x1);
scanf("%c",&x2);


for(i=0;i<n;i++)
{
  b[i]= creategraph(i);
}


for(i=0;i<e;i++)
{

  c=0;
  scanf("\n%c %c %d",&p1,&p2,&c1);
  v1=p1-65;
  v2=p2-65;

  struct node *temp1;
  temp1 = cnode(v2);
//printf("%d",temp1->nt->value);
//printf("%d",temp2->nt->value);
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

y[i]=v1;
y1[i]=v2;
  //printf("%d",b[v1]->up->nt->value);
  
 }
s=x1-65;

if(s<0 || s>n-1)
{
  printf("invalid\n");
  exit(1);
}
int n1;
n1=0;
while(n1!=n)
{ 
  s1=hash(s,n);
  if(b[s1]->colour==1)
    DFS_visit(b[s1],n);
  t++;
  n1++;
}

 

j=0;
for(i=l2-1;i>=0;i--)
{
  d1[j].val=a[i];
  d1[j].co=INT_MAX;
j++;
}





struct node* v;


for(i=0;i<n;i++)
{

  if(d1[i].val==s)
   {
      d1[i].co=0;
   }
}

//exit(1);
int j1,i1,s2;
s2=x2-65;
for(i=0;i<n;i++)
{

  if(d1[i].val==s)
   {
      i1=i;
   }
}

for(i=i1;i<n;i++)
{
     
     u=b[d1[i].val];
    v=u->up;

if(d1[i].val==s2)
break;

  

   while(v!=NULL)
   {

      for(j=0;j<n;j++)
       {
         if(v->nt->value==d1[j].val)
          { 
               break;
          }      
        }
 
           if(v->cost+d1[i].co<d1[j].co)
            {
            d1[j].co=v->cost+d1[i].co;
            v->nt->p=u;
            
            } 

        v=v->up;
   }

}


int w[100],sum=0;


u=b[s2];
j=0;

for(i=0;i<n;i++)
{
if(d1[i].val==s2)
 sum=d1[i].co;

}

while(u!=NULL&&u->value!=s)
{
  w[j]=u->value;
//printf("%d->",u->value);
for(i=0;i<n;i++)
 {
    if(u->value==d1[i].val)
     {
       if(d1[i].co==INT_MAX)
        {
            printf("no route possible!\n");
            exit(1);
        }

       break;
     }
 }
 j++;
 u=u->p;
}


if(u!=NULL && u->value==s)
{
//printf("%d",u->value);
w[j]=u->value;
j++;
for(i=0;i<n;i++)
 {
    if(u->value==d1[i].val)
     {
        if(d1[i].co==INT_MAX)
        {
            printf("no route possible!\n");
            exit(1);
        }
       
       break;
     }
}

} 
printf("\n");
printf("%d\n",sum);
for(i=j-1;i>0;i--)
{
  printf("%c->",w[i]+'A');
}
printf("%c\n",w[0]+'A');


  
//col(n);
return 0;
}
  








