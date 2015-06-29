#include<iostream>
using namespace std;

 struct node
 {
 	int key;
 	int f;

 	node *next;
 	
 } a[10000];


 int hash_fun(int key,int c)
 {
     return (key % c);
 }

 int main()
 {
 	int i,j,k,s,l,m,n,key,val,flag,c;
    cin>>c;
    node *t;
    while(1)
    {
    	cin>>s;
    	switch(s)
    	{
    		case 0: 
    		return 0;

    		case 1:
    		// chaining...........................................
            cin>>key;
            i=hash_fun(key,c);
            cout<<i<<endl;
            t=&a[i];
            if(t->next==NULL)
            {
            	t->key=key;  
            	t->next=t;             	
            }
            else
            {
            	node *temp= new (node);
            	temp->key= key;
            	temp->next=temp; 
                for(;t->next!=t;t=t->next);
                    t->next=temp;               	               

            }
            break;

            case 2:
            cin>>key;
            i=hash_fun(key,c);
            t=&a[i];
            
            
            if(t->next==NULL)
            {
            	cout<<i<<" "<<" NOT FOUND "<<endl;
            }
           
            else
            {
            	flag=0;
            	for(;t->next!=t;t=t->next)
                {   
                   if(t->key==key)
                    {
                	
                	  flag=1;
                	  break;
                    }
                }
                if(t->key==key)
                {
                  flag=1;
                }
                if(flag==0)
                {
                	cout<<i<<" "<<" NOT FOUND "<<endl;
                }
                else
                {
                	cout<<i<<" "<<" FOUND "<<endl;
                }
    	    } 
        }
    }
 }