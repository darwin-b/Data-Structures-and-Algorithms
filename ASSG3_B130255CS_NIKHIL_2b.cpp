#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int val;
	node *nxt;
}*head=NULL,*tail=NULL;

void que(int key)
{
	node *temp = new (node) ;
	temp->val=key;
	if((head==NULL)&&(tail==NULL))
	{
		temp->nxt=NULL;
	    tail=temp;
	    head=temp;   
	}
    else
    {
    	tail->nxt=temp;
	    tail=temp;
	    tail->nxt=NULL;
    }   
}

int deque()
{
	if((head==NULL)&&(tail==NULL))
	{
	    return -1;
	}
    int temp = head->val; 
	if(head==tail)
	{
		tail=NULL;
		head=NULL;
		return temp;
	}
	head=head->nxt;
	return temp;
}

int peek()
{
	if(head==NULL)
		return -1;
	int temp = head->val;
	return temp;
}

void show_que()
{
	node *trvs;
	trvs=head;
	if(trvs==NULL)
	{
		cout<<"Queue Empty "<<endl;

	}
	else
	{
		while(trvs!=NULL)
	    {
		   cout<<trvs->val<<" ";
		   trvs=trvs->nxt;

	    }
	    cout<<endl;
	} 
}

int main()

{
	int choice,val,temp;
    
    while(1)
    {   //cout<< top<<"hi";
    	cin>>choice;
        if((choice<0)&&(choice>4))
        {
        	cout<<"Invalid Choice";
        	exit(1);
        }
        switch(choice)
        {
    	  case 0:
    	  return 0;
    	  
    	  case 1:
    	  cin>>val;
    	  que(val);
    	  //cout<<s[top];
    	  break ;

    	  case 2:
    	  temp=deque();
    	  if(temp==-1)
    	  	cout<<"Queue Empty "<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  break;

    	  case 3:
    	  temp=peek();
    	  if(temp==-1)
    	  	cout<<"Queue empty"<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  
    	  break;

    	  case 4:
    	  show_que();
    	  break;
    	  default: 
    	  cout<<"Invalid Choice"<<endl;

        }    	
    }
   
     return 0;

}