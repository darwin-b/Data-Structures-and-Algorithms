#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<time.h>

using namespace std;

int main()
{
    int i,j,n,m,k,index;
    char a[1000][1000],temp[10000],less[10000]	;
    clock_t start,stop;
    double time;
    start=clock();
    cout<<"enter n"<<endl;
    
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
  
    for(i=1;i<=n+1;i++)
    {
        gets(a[i]);
        for(j=0;a[i][j]!='\0';j++)
        {
            if(!((a[i][j]>=97)&&(a[i][j]<=122)))
            {
                cout<<"Invalid Entry"<<endl;
                exit(1);
            }

        }
          if((strlen(a[i])==0)&&(i!=1))
        {
          cout<<"Null String Entered"<<endl;
          return 1;
        }
        
    } 
    cout<<endl;
    
    
    for(j=1;j<=n;j++)
    {   
    	strcpy(less,a[j]);
    	index=j;
    	for(i=j;i<=n+1;i++)
        {
       
            if(strcmp(less,a[i])>=0)
        	 {
        	 	strcpy(less,a[i]);
        	 	index=i;
        	 }
        }
       
        	strcpy(temp,a[j]);
            strcpy(a[j],a[index]);
            strcpy(a[index],temp);
        
    }

     for(i=1;i<=n+1;i++)
     	cout<<a[i]<<"\n";

    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Running time of program is: " <<time<<endl;

}
