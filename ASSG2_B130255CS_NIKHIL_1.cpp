#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<time.h>
using namespace std;

int lsr(int a[] , int i,int k, int n)
{
    if(i<n)
    if(a[i]==k)
        return i;
    else
       {
         i++;
         return lsr(a,i,k,n);
       }
    else
        return -1;
}

int main()
{
    int a[100000],i,n,k,index;
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


    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(cin.fail())
        {
            cout<<"Invalid Entry"<<endl;
            exit(1);
        }

    }
    cin>>k;
    
    index=lsr(a,0,k,n);
    if(index!=-1)
    cout<<endl<<index<<endl;
    else
    cout<<"not found"<<endl;
    

    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Running time of program is: " <<time<<endl;

    return 0;
}
