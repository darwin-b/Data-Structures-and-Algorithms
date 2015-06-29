#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int key;
	node *nxt;
}*end=NULL;

void crt_list()
{
	//cout<<"hi";
	node *temp = new (node);
	cin>>temp->key;
	temp->nxt=end;
	end=temp;	
}

int main()
{
	int n,i,j,k,l,count=0;
	cin>>n;
	if(n<=0)
	{
		cout<<"Invalid Entry"<<endl;
		exit(1);
	}
	//cout<<endl;
    for(i=1;i<=n;i++)
    {
      crt_list();
      //cout<<"hi"<<i<<" ";
    }
    node *trv;
    trv=end;
    for(;trv!=NULL;)
    {
    	if(trv->key>10)
           count++;
        trv=trv->nxt;
    }
    
    cout<<endl<<count<<endl;
}