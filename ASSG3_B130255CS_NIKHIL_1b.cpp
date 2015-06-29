#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int val;
	node *nxt;
}*top=NULL;


void push(int key)
{
	node *temp =new (node);
    temp->val=key;
    temp->nxt=top;
    top=temp;    
}

int pop()
{
	if(top==NULL)
	 return -1;
	int temp;
	temp = top->val;
	top=top->nxt;
	return temp;
}

int peek()
{
	if(top==NULL)
	 return -1;
	int temp=top->val;
	return temp;
}

void show_stack()
{
	if(top==NULL)
	{
		cout<<"Stack Empty"<<endl;
	}

	node *temp;
	temp=top;
   
    for(;temp!=NULL;)
    {
    	cout<<temp->val<<" ";
    	temp=temp->nxt;
    }
    cout<<endl;	
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
    	  push(val);
    	  //cout<<s[top];
    	  break ;

    	  case 2:
    	  temp=pop();
    	  if(temp==-1)
    	  	cout<<"Stack Empty "<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  break;

    	  case 3:
    	  temp=peek();
    	  if(temp==-1)
    	  	cout<<"stack empty"<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  
    	  break;

    	  case 4:
    	  show_stack();
    	  break;
    	  default: 
    	  cout<<"Invalid Choice"<<endl;

        }    	
    }
   
     return 0;

}

