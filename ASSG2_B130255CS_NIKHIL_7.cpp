#include <iostream>
#include <cstdlib>
//#include <cstdio>
//#include <cmath>
#include<time.h>

int a[100000000],L[100000000],R[100000000];


using namespace std;
void merge(int a[100000000],int p,int q,int r)
{
   int i,j,k,ls,rs;
   ls = q-p+1;
   rs = r-q;
   for(i=1;i <= ls ;i++)
   L[i] = a[p+i-1];
   for(j=1;j <= rs ;j++)
   R[j] = a[q+j];
   
   L[ls+1] = 10000;   
   R[rs+1] = 10000;
   
   i = 1;
   j = 1;
   
   for(k=p;k<=r;k++)
   {
     if(L[i] <= R[j])
     {
       a[k] = L[i];
       i++;
     }
     else
     {
       a[k] = R[j];
       j++;
     }
   }
}

void mer_sor(int a[100000000],int p,int r)
{
    if (p < r)
    {
       int q = (p+r)/2;
       mer_sor(a,p,q);
       mer_sor(a,q+1,r);
       merge(a,p,q,r);
    }
}

int main()
{
    int i,j,n;
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

    a[0]=0;
    for (int i = 1; i <= n; ++i)
    {
      cin >>  a[i] ;
      if(cin.fail())
        {
            cout<<"Invalid Entry"<<endl;
            exit(1);
        }
    }          
     
     mer_sor(a,1,n);
    for (int i = 1; i <= n; ++i)
     cout << a[i] << " ";
  
     cout << '\n';

     stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Running time of program is: " <<time<<endl;
    return 0;
}
