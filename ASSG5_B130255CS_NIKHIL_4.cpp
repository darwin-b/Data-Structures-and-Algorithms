#include<iostream>
#include<cstdlib>
using namespace std;
                ///With ranked union and with path compression
struct node
{
    int data;
    int rank;
    node *p;
}*a[1000],*rep;

int i=0;

node *make_set(int x)
{
    node *temp = new (node) ;
    temp->data=x;
    temp->rank=0;
    temp->p=temp;
    a[i]=temp;
    i++;
}

node *search(int x)
{
    int j,n;
    j=i-1;
    for(;j>=0;j--)
    {
        if(a[j]->data==x)
            return a[j];
            //cout<<" hi ";
    }

    cout<< "ERROR "<<endl;
    return NULL;
}

node* path_comp(node* temp)
{
    if(temp->p!=temp)
      temp->p =path_comp(temp->p);
      return temp->p;
}


node *find_set(int x)
{
    node *temp;
    temp=search(x);

   return path_comp(temp);

}


node *join(int x, int y)
{
    node *temp1,*temp2,*temp3,*temp4;
    //temp1=search(x);
    //temp2=search(y);
    temp3= find_set(x);
    temp4= find_set(y);
    if(temp3==temp4)
        return NULL;
    if((temp3->rank)>(temp4->rank))
       temp4->p=temp3;
    else if((temp3->rank)<(temp4->rank))
       temp3->p=temp4;
       else
       {
           temp4->p=temp3;
           temp3->rank = temp3->rank + 1;
       }
}


void swap(int i, int j, int d[1000][3])
{
	int temp1,temp2,temp3;

	temp1=d[i][1];
	temp2=d[i][2];
	temp3=d[i][3];
	d[i][1]=d[j][1];
	d[i][2]=d[j][2];
	d[i][3]=d[j][3];
     
    d[j][1]=temp1;
    d[j][2]=temp2;
    d[j][3]=temp3;
}

void sort(int c[1000][3],int e)
{
	int i,j;
	for(i=0;i<e;i++)
	{
		for(j=i;j<e;j++)
		{
			if(c[i][3]>c[j][3])
			{
				swap(i,j,c);
			}
		}
	}
}



int main()
{

    int n,e,i,j,d[1000][3],sum,b[1000][1000];
    cin>>n>>e;
    if((n<=0)||(e<=0))
    {
       cout<<" INVALID ENTRY "<<endl;
       exit(1);
    }

    for(i=0;i<n;i++)
    {
    	make_set(i);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=0;;
        }
        //cout<<endl;
    }

    for(i=0;i<e;i++)
    {
    	cin>>d[i][1]>>d[i][2]>>d[i][3];
    	if((d[i][1]>=n)||(d[i][1]>=n))
        {
            cout<<" ERROR "<<endl;
            exit(1);
        }
        if((d[i][1]<0)||(d[i][1]<0))
        {
            cout<<" ERROR "<<endl;
            exit(1);
        }
    }


     sort(d,e);
     cout<<endl<<endl;  /*
     for(i=0;i<e;i++)
    {
    	cout<<d[i][1]<<" "<<d[i][2]<<" "<<d[i][3];
    	cout<<endl;
    }

    */

    for(i=0;i<e;i++)
    {
    	if(find_set(d[i][1])->data!=find_set(d[i][2])->data)
    	{
    		join(d[i][1],d[i][2]);
    		sum=sum+d[i][3];
            b[d[i][1]][d[i][2]]=d[i][3];
            b[d[i][2]][d[i][1]]=d[i][3];
    	}
    	
    }
    
    //cout<<" parent- "<<find_set(d[0][1])->data<<endl;
    cout<< " cost- "<<sum<<endl;
    cout<<endl<<endl;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
return 0;

}
