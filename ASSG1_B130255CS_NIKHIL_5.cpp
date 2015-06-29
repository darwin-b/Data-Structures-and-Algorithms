#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int a[20][20],n,i,j,k=0,l,s=0;
    long int m=0;
    char c;
    cout<<"Enter the order of the matrix: ";
    if((scanf("%d%c",&n,&c)!=2) || c !='\n')
    {
        cout<<"Invalid entry";
        return 1;
    }
    if(n<=0)
    {
        cout<<"Order of matrix cannot be non-positive ";
        return 1;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
          if((scanf("%d%c",&a[i][j],&c)!=2) || c !='\n')
          {
            cout<<"Invalid entry";
            return 1;
          }

          if((a[i][j]>n*n)||(a[i][j]<1))
          {
              cout<<"entries not in range of 1 and 'n' " ;
              return 1;
          }
          m = m + a[i][j];
        }


       if(m!=(n*n*(n*n+1)/2) )
        {
          cout<<"Entries are not distinct" ;
          return 0;
        }

    for(i=0;i<n;i++)
        k=k+a[i][i];
    for(i=0,j=n-1;i<n;i++,j--)
        s=s+a[i][j];

    if(k!=s)
        {cout<<"NO" ;
        cout<<endl;
        return 0;
        }

    for(i=0;i<n;i++)
    {
        s=0 ;
        for(j=0;j<n;j++)
         {
             s = s+a[i][j] ;
         }
        if(k!=s)
          {cout<<"NO" ;
           cout<<endl;
           return 0;
          }
    }

     for(i=0;i<n;i++)
    {
        s=0 ;
        for(j=0;j<n;j++)
         {
             s = s+a[j][i] ;
         }
        if(k!=s)
          {cout<<"NO" ;
          cout<<endl;
           return 0;
          }
    }

    cout<<"YES ";
    return 0;

}
