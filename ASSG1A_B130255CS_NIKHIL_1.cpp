#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int i,j,k,c=0,l;
    char  a[10000];

    gets(a);
    if(a[0]=='\0')
    {
        cout<<"null string not acceptable ";
        return 1;
    }
    for(i=0;a[i]!='\0';i++)
    {
        if(!((a[i]>='a')&&(a[i]<='z')||(a[i]>='A')&&(a[i]<='Z')))
        {
            cout<<"Invalid entry";
            return 1;
        }
    }

    j=i;
    l=j/2;
    j--;

    for(i=0;i<j;i++,j--)
    {
        if(a[i]!=a[j])
        {
            if((c==0)&&((j-i)==1))
            {
                cout<<a[l-1]<<endl<<l-1<<endl;
            }
            c=c+1;
            if(c>1)
            {
                cout<<"Not Possible";
                return 0;
            }
            if(a[i]==a[j-1])
            {
                k=j;
                i--;
            }
            else
            if(a[i+1]==a[j])
            {
               k=i;
               j++;
            }
            else
             {cout<<"Not Possible" ;
              return 0;
             }
        }
    }

    i=l-1;
    j=l+1;
    if(c==0)
        {for( ; (  (a[i]==a[l]) || (a[j]==a[l])  );  i--,j++ )
        {
            if(a[l]==a[j])
            {
                cout<<a[l]<<endl<<j<<endl;
            }
            if(a[l]==a[i])
                cout<<a[l]<<endl<<i<<endl;
        }
       k=l;}
    cout<<a[k]<<endl<<k ;
    return 0;
}


