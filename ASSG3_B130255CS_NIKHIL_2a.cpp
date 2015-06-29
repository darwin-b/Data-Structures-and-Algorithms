#include<iostream>
#include<cstdlib>
using namespace std;
int head=1,tail=1;

void que(int q[], int element,int size)
{
    if(head==tail+1)
    {
    	cout<<"Queue Full"<<endl;
    }
    
    else
    {
    	q3[tail]= element;
    	
    	/*if(tail==size)
    		tail=0;
    	else */
    		tail++;
    }
}

int deque(int q[],int size)
{
	int x;
	if(head==tail)
	 x=-1;
	else
	{
        x=q[head];
        if(head==size)
        	head=1;
        else
        	head=head+1;
	}
	return x;
}


int peek(int q[] )
{
	if(head==tail)
    return -1;
    else
    return q[head] ;
}

void show_que(int q[])
{
	int i;
	i=head;
	if(head==tail)
	{
		cout<<"Queue Empty";
	}
	else
	while(i<tail)
	{
		cout<<q[i]<<" ";
		i++;		
	}

	cout<<endl;
}

int main()
{
	int choice,q[1000000],val,temp,size,c;
    cin>>size;
    if((c>0) &&(c<100))
    if(size<=0)
    {
    	cout<<"Invalid Entry";
    	exit(1);
    }
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
      	  if(size<=c)
    	  {
    	  	cout<<"Queue FULL"<<endl;
    	  	break;
    	  }
    	  c++;
    	  que(q,val,size);
    	  //cout<<s[top];
    	  break ;

    	  case 2:
    	  c=c-1;
    	  temp=deque(q,size);
    	  if(temp==-1)
    	  	cout<<"Queue Empty "<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  break;

    	  case 3:
    	  temp=peek(q);
    	  if(temp==-1)
    	  	cout<<"Queue empty"<<endl;
    	  else
    	  	cout<<temp<<endl;
    	  
    	  break;

    	  case 4:
    	  show_que(q);
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