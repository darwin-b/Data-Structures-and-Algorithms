#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int key;
	node *nxt;
	node *prev;
}*end=NULL,*start=NULL;

void ctr_list()
{
	//cout<<"hi";
	node *temp = new (node);
	if(temp==NULL)
	{
		cout<<"Memory not alloted"<<endl;
		exit(1);
	}
	cin >> temp->key;
	if(end == NULL)
	{
		start=temp;
        temp->nxt=NULL;
	    temp->prev=NULL;  
	    end=temp;  
	}	
	else
    {
	  temp->nxt=end;
	  end->prev=temp;
	  end=temp;
	  end->prev=NULL;
    }
}

int main()
{
   int n,i,j;
   node *head, *del,*temp2,*trv;
   del=end;
  
   

   cin>>n;
   if(n<=0)
   {
   	cout<<"Invalid Entry";
   	exit(1);
   }
   for(i=1;i<=n;i++)
   {
   	ctr_list();
   }
   
   trv=end;  
   head=end;
   temp2=end;
    /*for(;trv!=NULL;)
    {    	
    	//cout<<"hi ";
        cout<<trv->key<<" ";
        trv=trv->nxt;
    } */    
   

   for(;(head->nxt!=NULL)&&(head!=NULL);)
   {
      if(head->nxt==NULL)
      {
      	cout<<head->key<<endl;
      	return 0;
      }
      else
      {
      	 del=head->nxt;
         head->nxt=head->nxt->nxt;
          
         del->nxt=NULL;
         del->prev=NULL;
         delete(del); 

         temp2=head;
         head=head->nxt;
         if(head==NULL)
         	break;
         head->prev=temp2;
         
      }
   }   

   trv=end;

   for(;trv!=NULL;) 
    {    	
        cout<<trv->key<<" ";
        trv=trv->nxt;
    } 

return 0;
}