#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;

int front=-1,tail=-1;

struct node
{
    int data;
    int cost;
    int col;
    int d;
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
    temp->d=10000 ;
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
    for(i=1;i<=n;i++)
    {
       a[i]=cnode(i,0);
    }
    
    for(i=0;i<e;i++)
    {
        cost=0;
        cin>>u>>v;
        
        if((u>n)||(v>n))
        {
            cout<<" ERROR1 "<<endl;
            exit(1);
        }
        if((u<=0)||(v<=0))
        {
            cout<<" ERROR2 "<<endl;
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

void enque(node *head)
{
    if(front==tail)
    {
        front++;
        tail++;
        q[tail]= head;
        tail++;
    }
    else{
        q[tail]= head;
        tail++;
        }
}

node* deque()
{
    if(front==tail)
    {
        return NULL;
    }
    else{
        node *temp ;
        temp = q[front];
        front++;
        return temp;
    }
}


void search1(node *vert)
{
    node *temp;
    int i;
    for(i=1;i<=n;i++)
    {
        temp= a[i];
        for(;temp!=NULL;)
        {
          if(temp->data== vert->data)
          {
              temp->col= 2;
              vert->d=0;
              vert->pred=NULL;
          }
          temp=temp->next;
        }
        //cout<<endl;
    }
}

void search2(int x,node *u,int t)
{
    node *temp;
    int i;
    for(i=1;i<=n;i++)
    {
        temp= a[i];
        for(;temp!=NULL;)
        {
          if(temp->data== x)
          {
              temp->col= t;
              temp->d= (u->d)+1;
              temp->pred=u;
          }
          temp=temp->next;
        }
    }
}

void show()
{
    cout<<"\t";
    int i=front;
    node *temp;
    for(;i!=tail;i++)
    {   temp=q[i];
        cout<<temp->data<<" ";
    }
}

void col()
{
    node *temp;
    int i;
    for(i=1;i<=n;i++)
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


void bfs(node *a[],node *vert)
{
    //cout<<" hi ";
    int i,t;

    search1(vert);
    enque(vert);
    //cout<<" enqueing "<<vert->data;
    
    for(;front!=tail;)
    {
        //cout<<" hi2 ";
        node *temp,*u;

        u=deque();
        if(u->col==2)
          t=-1;
        else
          t=2;  
        u= a[u->data];
      //  cout<<" dequeing "<<u->data;
      //  show();
      
       // cout<<u->data<<"helooo \n";
        temp=u->next;

        for(;temp!=NULL;)
        {
            
            if(temp->col==1)
            {
                search2(temp->data,u,t);
        //        col();
                enque(temp);
            }
           // cout<<" enqueing "<<temp->data;
          //  show();
          //cout<<"\n";
            temp=temp->next;
        }

    /*        for(i=0;i<n;i++)
        {
            temp= a[i];
            for(;temp!=NULL;)
            {
                if(temp->data==u->data)
                    temp->col=3;

                temp=temp->next;
            }
        }   */
        //col();
    }

    //cout<<" check2 ";

}


int main()
{
    int i,j,ver;
    graph();

    node *temp;
    for(i=1;i<=n;i++)
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
    // cin>>ver;
    ver=1;
    /* if((ver>=n)||(ver<0))
    {
        cout<< " ERROR ";
        exit(1);
    }  */ 
    
    bfs(a,a[ver]);
    
    
    int k;
    for(i=1;i<=n;i++)
    {
        temp = a[i];
        k= temp->col;
        temp=temp->next;
        for(;temp!=NULL;)
        {
         if(k==temp->col)
         {
            cout<<"\n NO \n\n";
            col();
            return 0;
         }
         temp=temp->next;
        }
       // cout<<endl;
    }
    
    cout<<"\n YES \n\n";
    
    col();
    cout<<endl;
    
    return 0;
}

