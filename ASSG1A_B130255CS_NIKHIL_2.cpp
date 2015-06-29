#include<iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

int M=0;

void swap (int c[], int i, int j)
{
	int temp;
	temp = c[i];
	c[i] = c[j];
	c[j] = temp;
}


int coprow(int a[],int b[],int n)
{
    int i,j,k,l,c=0,flag=0;
    for(i=0;i<n;i++)
    {
        if((flag==0)&&(a[b[i]]==1))
        {
            flag=1;
            c=c+1;
        }
        if(a[b[i]]==1)
            flag=1;
        if((flag==1)&&(a[b[i]]==0))
        {
            flag=0;
            c=c+1;
        }
        if(a[b[i]]==0)
            flag=0;
    }

    if(c>2)
        return 0;
    else
        return 1;
}


int cop(int a[12][12] ,int b[] ,int m , int n)
{
    int i,j,k=0;

    for(i=0;i<m;i++)
    {
        if(coprow(a[i],b,n)==1)
            k++;
        else
            return 0;
    }
    if(k==m)
        return 1;
    else
        return 0;
}

/* recursive function to generate permutations */
void perm (int a[12][12],int v[], int n, int i, int m)
{
	int j;
	if (i == n)
	{
        if(((cop(a,v,m,n))==1)&&(M==0))
         {
             M=1;
            cout<<"YES"<<endl;
            for(i=0;i<n;i++)
             cout<<v[i]+1<<" ";
            exit(0) ;
         }
	}
	else
		for (j=i; j<n; j++)
		{
			swap (v, i, j);
			perm (a,v, n, i+1,m);
			swap (v, i, j);
		}
}




int main()
{
    int a[12][12],b[12],i,j,k,l,m,n;
    char c;
    //error checking from 96 till line 119
    cout<<"Enter m an d n: \n" ;
    if((scanf("%d%c",&m,&c)!=2) || c !='\n')
    {
        cout<<"Invalid entry \n";
        return 1;
    }
    if((scanf("%d%c",&n,&c)!=2) || c !='\n')
    {
        cout<<"Invalid entry \n";
        return 1;
    }
    if((m<=0)||(n<=0))
    {
        cout<<"Order cant be negative \n" ;
        exit(1);
    }
    if((m>10)||(n>10))
    {
        cout<<"order out of specified range \n";

        exit(1);
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            if((a[i][j]!=0) && (a[i][j]!=1))
            {
                cout<<"Invalid Entry";
                exit(0);
            }
        }
    }

    for(i=0;i<n;i++)
    b[i]=i;

    perm(a,b,n,0,m);

    cout<<"NO";
    return 0;
}

