#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
float a[100000000];

void swap(float a[], int i, int j)
{
	float temp;
	temp = a[i];
	a[i]=a[j] ;
	a[j]=temp;
}

int partition(float a[],int p,int r)
{
	int x,i,j;
	x=a[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			swap(a,i,j);
		}
	}
	swap(a,i+1,r);
	return i+1;
}

void quicksort(float a[],int p,int r)
{
   int q;
   if(p<r)
   {
   	 q=partition(a,p,r);
   	 quicksort(a,p,q-1);
   	 quicksort(a,q+1,r);
   }
}

int main()
{
   int i,j,n,k;
   clock_t start,stop;
   double time;
   start=clock();
   cin>>n;
   if(n<=0)
    {
            cout<<"Invalid Entry"<<endl;
            exit(1);
    }
   if(cin.fail())
        {
            cout<<"Invalid Entry"<<endl;
            exit(1);
        }

   for(i=1;i<=n;i++)
   {
    	cin>>a[i];
        if(cin.fail())
        {
            cout<<"Invalid Entry"<<endl;
            exit(1);
        }

   }
   if(n==1)
   n++;
   quicksort(a,1,n);
   cout<<a[n/2]<<endl;
   stop=clock();
   time=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Running time of program is: " <<time<<endl;
   
   

}

