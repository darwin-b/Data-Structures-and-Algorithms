#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int i=0,j=0,k,l,n,flag=0,c=0;
    char a[10000],b[10000];
    cout<<"Enter String S1: ";
    gets(a);

    for(i=0;a[i]!='\0';i++)
    {
        if(!((a[i]>='a')&&(a[i]<='z')||(a[i]>='A')&&(a[i]<='Z')))
        {
            cout<<"Invalid entry";
            return 1;
        }
    }
    cout<<"Enter String S2: ";
    gets(b);
    for(i=0;b[i]!='\0';i++)
    {
        if(!((b[i]>='a')&&(b[i]<='z')||(b[i]>='A')&&(b[i]<='Z')))
        {
            cout<<"Invalid entry";
            return 1;
        }
    }



    for(i=0;a[i]!='\0';i++)
    {
        k=i;
        for(j=0;b[j]!='\0';j++,k++)
        {
           if(b[j]==a[k])
           {   flag=1;
               if((b[j+1]=='\0')&&(c==0))
               {
                   cout<<"YES\n";
                   c++;

               }
               if(b[j+1]=='\0')
               cout<<k-strlen(b)+1<<endl;
            }
            else
            {
               if(c==0)
               { flag=0;
                 break;
                 }
                 else
                    break;
            }
        }
     }

    if(flag==0)
    cout<<"NO";
    return 0;


}
