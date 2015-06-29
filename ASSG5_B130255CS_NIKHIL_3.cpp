#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

int front=-1,tail=-1,tim=0;

struct node
{
    int data;
    int cost;
    int col;
    int d;
    int f;
    node *pred;
    node *next;
} *a[1000], *q[1000];

int n;


node *cnode(int v,int cost)
{
    node *temp= new (node);
    temp->data = v;
    temp->cost=cost;
    temp->next=NULL;
    temp->col=1;
    temp->d=0 ;
    temp->f=0;
    temp->pred=NULL;
    return temp;
}

void graph()
{
    int e,u,v,cost,i;
    cin>>n>>e;
    if((n<=0)||(e<=0))
    {
       cout<<" INVALID ENTRY "<<endl;
       exit(1);
    }
    for(i=0;i<n;i++)
    {
       a[i]=cnode(i,0);
    }

    for(i=0;i<e;i++)
    {
        cost=0;
        cin>>u>>v>>cost;
        if((u>=n)||(v>=n))
        {
            cout<<" ERROR "<<endl;
            exit(1);
        }
        if((u<0)||(v<0))
        {
            cout<<" ERROR "<<endl;
            exit(1);
        }
        
        node *temp,*temp2;
        temp=a[u];
        temp2=a[v];
        for(;temp->next!=NULL;)
        {
            temp=temp->next;
        }
        temp->next = cnode(v,cost);

        for(;temp2->next!=NULL;)
        {
            temp2=temp2->next;
        }
        temp2->next = cnode(u,cost);
    }
}




void search1(int x,node *u)
{
    node *temp;
    int i;
    for(i=0;i<n;i++)
    {
        temp= a[i];
        for(;temp!=NULL;)
        {
          if(temp->data== x)
          {            
              temp->pred=u;
          }
          temp=temp->next;
        }
        //cout<<endl;
    }
}

void search2(int x)
{
    node *temp;
    int i;
    tim++;
    for(i=0;i<n;i++)
    {
        temp= a[i];
        for(;temp!=NULL;)
        {
          if(temp->data== x)
          {
              temp->col= 2;
              temp->d= tim;
          }
          temp=temp->next;
        }
    }
}

void search3(int x)
{
    node *temp;
    int i;
    tim++;
    for(i=0;i<n;i++)
    {
        temp= a[i];
        for(;temp!=NULL;)
        {
          if(temp->data== x)
          {
              temp->col= 3;
              temp->f= tim;
          }
          temp=temp->next;
        }
    }
}


void col()
{
    node *temp;
    int i;
    for(i=0;i<n;i++)
    {
        temp= a[i];
        for(;temp!=NULL;)
        {
            cout<<temp->col<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

}


int hash(int x,int i)
{
	int j;
	j= (x+i)%n;
	return j ;
}

void dfs_visit(node *vert)
{  cout<<vert->data<<"hellooo \n" ;
   search2(vert->data);
   //col();
   node *temp;
   temp=vert->next;
   //cout<<" check3 ";
   while(temp!=NULL)
   {
   	// cout<< " check 2 ";
  	 if(temp->col==1)
   	 {
   	 	search1(temp->data,vert);
   	 	dfs_visit(temp);
   	 	  	 	
   	 }	
   	 temp=temp->next; 	
   }

   search3(vert->data);

}


void dfs()
{
	int i,x,k;
	//cout<<" hi ";
	cin>>x;
    
   for(i=0;i<n;i++)
   {
   	  // cout<<" end ";	
       k=hash(x,i) ;
       //cout<<" k "<<k<<endl;
       if(a[k]->col==1)
       { 
       	 // cout<< " check " ;
          dfs_visit(a[k]);
       }
   }

}





int main()
{
    int i,j;
    graph();

    node *temp;
    for(i=0;i<n;i++)
    {
        temp= a[i];
        for(;temp!=NULL;)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    cout<<" OUTPUT "<<endl;
    dfs();
    //col();
    cout<<endl;
    col();
    return 0;
}

