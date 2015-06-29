#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int v2,count=0;

struct node
{
   struct node *up;
   struct graph *nt;
   int  cost;
}*v;

struct graph
{
   struct graph *next; 
   struct graph *prev;
   struct graph *next1;
   struct node *up;
   int colour;
   struct graph * p;
   int d;
   int value;
 int key;

}*root1,*b[200],*temp,*head,*tail,*u;


struct graph * enqueue(struct graph * node) 
{
  if(head==NULL)
      {
      head=new (graph); 
    
     count++;
    head=node;
    head->prev=NULL;
    head->next1=NULL;
    tail=head;
   
       }
     else
     {  
      count++;

       temp=new (graph);
        temp=node;
        temp->next1=tail; 
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
   count--;
    temp1=head;
  
   temp=head->prev;
   free(head);
   head=temp;  
   return(temp1);
   } 
}                   

struct node *cnode(int e,int c)
{
   struct node *temp = new (node);
   temp->nt = b[e];
   temp->cost=c;
   return temp;
}


struct graph * creategraph(int e)
 {
    struct graph *temp= new (graph);
  
     temp->colour=1;
     temp->d=INT_MAX;
     temp->value=e;
     temp->up=NULL;
     temp->key=INT_MAX;
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
	       cout<<end->nt->value<<" ";
         end=end->up;

      }
      cout<<endl;
   }

}

struct graph *bubblesort ()
{
  int count = 0, i;
  struct graph *start = head;
   struct graph  *curr = NULL;
    struct graph *trail = NULL;
  struct graph *temp = NULL;

  while(start != NULL) { 
    count++;
    start = start->prev;
  }

  for(i = 0; i<count; i++) { 

    curr = trail = head; 

    while (curr->prev != NULL) { 
      if (curr->key > curr->prev->key) 
      { 

        temp = curr->prev; 
        curr->prev = curr->prev->prev;
        temp->prev = curr;

       
        if(curr == head) 
          head = trail = temp;
        else 
          trail->prev = temp;
        curr = temp; 
      }
   
      trail = curr;
      curr = curr->prev;
    }
  }
}


int search(struct graph * tempo)
 {
    struct graph * temp;
    temp=head; 
  while(temp!=NULL)
   {
        if(temp->value==tempo->value)
         {
           return 1;
          }
      temp=temp->prev;
    }
   return 0;
  }
   


int main()
{
struct node *temp1,*temp2;
struct graph *temp;
struct node *end;

int x,i=0,j,e,e1,e2,v1,c,s,n;

cin>>n>>e;
if((n<=0)||(e<=0))
    {
       cout<<" INVALID ENTRY "<<endl;
       exit(1);
    }
for(i=0;i<n;i++)
{
  b[i]= creategraph(i);
}

for(i=0;i<e;i++)
{
  c=0;
  cin>>v1>>v2>>c;
   if((v1>=n)||(v2>=n))
        {
            cout<<" ERROR "<<endl;
            exit(1);
        }
        if((v1<0)||(v2<0))
        {
            cout<<" ERROR "<<endl;
            exit(1);
        }
  
  struct node *temp1;
  temp1 = cnode(v2,c);
  struct node *temp2;
  temp2 = cnode(v1, c);

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


//print(n);


cin>>s;
if((s>=n)||(s<0))
{
  cout<<" error \n";
  exit(1);
}

b[s]->key=0;
for(i=0;i<n;i++)
{
  enqueue(b[i]);
}
cout<<count<<endl;

int sum=0;

temp=head;
while(temp!=NULL)
{
   printf("%d ",temp->value);
temp=temp->prev;
} 

bubblesort();
temp=head;
printf("\n");
while(temp!=NULL)
{
   printf("%d ",temp->value);
temp=temp->prev;
}
printf("%d",head->value);

printf("\n");

sum=0;
int u1=1;
while(head!=NULL)
{
  u=dequeue();
printf("%d\n",u->value);
 if(u1!=1) 
{
sum=sum+u->key;
}   
u1=2;
v=u->up;
  while(v!=NULL)
  {
   
     if(v->cost<v->nt->key && search(v->nt))
            { 
                
                 v->nt->p=u;
                 v->nt->key=v->cost;
            }
     
       v=v->up; 
   }
bubblesort();
}

int c1[100][100];
for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
   {
         c1[i][j]=0;
   }
 }

for(i=0;i<n;i++)
{ 
   if(b[i]->p!=NULL)
    {
        c1[b[i]->value][b[i]->p->value]=b[i]->key;
         c1[b[i]->p->value][b[i]->value]=b[i]->key;
    }
}

printf("\nsum=%d\n",sum);

for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
   {
       if(c1[i][j]<10)
        printf("%d  ",c1[i][j]);
      else
       printf("%d ",c1[i][j]);
   }
printf("\n");
}

return 0;
}
   













