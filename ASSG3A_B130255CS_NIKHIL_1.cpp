#include<iostream>
using namespace std;

#include<stdio.h>
#include<cstdlib>

struct lnk_lst
{
  int val;
  struct lnk_lst *next;
  struct lnk_lst *prev;
  struct lnk_lst *down;
}*ptr,*ptr1,*ptr2,*ptr3,*ptr4,*ptr5,lnk_lst,*start,*end;

struct lnk_lst* merge(struct lnk_lst* x,struct lnk_lst* y)
{   
    if (x == NULL)
        return y;      
    if (y == NULL)
        return x;
        
  struct  lnk_lst* fin;
    if( x->val < y->val)
    {
        fin = x;
        fin->down = merge(x->down, y);
    }
    else
    {
        fin = y;
        fin->down = merge(x,y->down);
    } 
    return fin;
}

struct lnk_lst* flatten (struct lnk_lst* start)
{
    if ( start == NULL || start->next == NULL )
        return start;
    return merge( start, flatten(start->next) );
}

void read_dwn(int p) 
{
   //lnk_lst *temp; 
   if(start==NULL)
   {
      //temp= new (struct lnk_lst);
      //start=temp;
      start=(struct lnk_lst *) malloc(sizeof(struct lnk_lst));
      start->val=p;
      start->next=NULL;
      start->prev=NULL;
      start->down=NULL;
      end=start;
   }
   else
   {   
      //lnk_lst *temp= new (struct lnk_lst);;
      //ptr =temp;
      ptr=(struct lnk_lst *) malloc(sizeof(struct lnk_lst));  
      ptr->val=p;
      end->next=ptr;
      end->prev=end;
      end=ptr;
      end->next=NULL;
      end->down=NULL;     
  } 
}  

void read_nxt(int p) 
{
      //lnk_lst *temp=new (struct lnk_lst);
      //ptr =temp;
      ptr=(struct lnk_lst *) malloc(sizeof(struct lnk_lst));  
      ptr->val=p;
      ptr5->down=ptr;
      ptr5=ptr5->down;
      ptr5->down=NULL;

}
int main()
{
   
  start=NULL;  
  int i=0,n,m,track,k;
  char ch;
  while(1)
  {
   
    if(!(scanf("%d%c",&m,&ch)==2 && ch==' '))
      break;
      read_dwn(m);
    i++;
  }  
  read_dwn(m); 
  n=i+1;
  ptr5=start;
  ptr2=start;    
  for(k=0;k<n;k++)
  {
   track=0;
   while(1)
   {   
     if(!(scanf("%d%c",&m,&ch)==2 && ch==' '))
         break;
    
     if(track!=0)
      read_nxt(m); 
     track++;
   }
   if(track!=0)
    read_nxt(m);
    ptr2=ptr2->next;
    ptr5=ptr2;

  } 
  start = flatten(start);
  while(start != NULL)
  {
        cout<<start->val<<" ";
        start = start->down;
  }
  return 0;
}



   







    
