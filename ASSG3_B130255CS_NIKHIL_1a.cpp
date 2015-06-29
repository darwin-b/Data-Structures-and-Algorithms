#include<iostream>
#include<cstdlib>
using namespace std;

int top=0;

void push(int stack[], int element ,int c)
{
    top++;
    stack[top]= element;

}

int pop(int stack[])
{
	if(top==0)
    return -1 ; 
    top--;
    return stack[top+1] ;
}

int peek(int stack[] )
{
	if(top==0)
    return -1;
    else
    return stack[top] ;
}

void show_stack(int stack[])
{
	int i;
	i=top;
	if(i==0)
	{
		cout<<"Stack Empty";
	}
	else
	while(i>0)
	{
		cout<<stack[i]<<" ";
		i--;
		
	}

	cout<<endl;
}

int main()
{
	int choice,s[102],val,temp,c;
    cin>>c;   
    if((c>0) &&(c<100))
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
           if(top>=c)
           {
              cout<<"stack full";
              break;
            }
            else    
    	    push(s,val,c);
    	    //cout<<s[top];
    	    break ;

    	  case 2:
    	  temp=pop(s);
    	  if(temp==-1)
    	  	cout<<"Stack Empty "<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  break;

    	  case 3:
    	  temp=peek(s);
    	  if(temp==-1)
    	  	cout<<"stack empty"<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  
    	  break;

    	  case 4:
    	  show_stack(s);
    	  break;
    	  default: 
    	  cout<<"Invalid Choice"<<endl;

        }    	
    }
    else
    {
    	cout<<"Stack limit exceeded"<<endl;
    	exit(1);
    }
   
     return 0;

}