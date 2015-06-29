
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

char a[10000][10000];


void csort(int n,int sub)
{
    int l,i,cnt[10000];
    char x,b[10000],temp[1000][1000];
    for(i=0;i<16;i++)
     cnt[i]=0;
     
    for(i=0;i<n;i++)
    {
       strcpy(b,a[i]);
       l=strlen(b)-sub;
       if(l>=1)
       {   
         if( a[i][l-1]>=65 && a[i][l-1]<=97)
           cnt[a[i][l-1]-55]++;
        
         else if(a[i][l-1]>=48 && a[i][l-1]<=58)
             cnt[a[i][l-1]-47]++;
             else
             {
               cout<<"Invalid Entry";
               exit(1);  
             }
        } 
        else
        {
          x ='0';
          cnt[x-47]++;
        }
        
    }
      for(i=1;i<16;i++)
      cnt[i]+=cnt[i-1];
            
    for(i=n-1;i>=0;i--)
    {
         strcpy(b,a[i]);
         l=strlen(b)-sub;
         if(l>=1)
         {
            if( a[i][l-1]>=65 && a[i][l-1]<=97)
            {
                strcpy(temp[cnt[a[i][l-1]-55]-1],a[i]);
                      cnt[a[i][l-1]-55]--;
                  }
               else
              {
                   strcpy(temp[cnt[a[i][l-1]-47]-1],a[i]);
                   cnt[a[i][l-1]-47]--;
              }
         }
         else
         {
            x='0';
            strcpy(temp[cnt[x-47]-1],a[i]);
             cnt[x-47]--;
         }     
    }
      
    for(i=0;i<n;i++)
      strcpy(a[i],temp[i]);
      

}

void rsort(int n,int large)
{
   int i;
   
   for(i=0;i<large;i++)
       csort(n,i); 
    
    for(i=0;i<n;i++)
       cout<<endl<<a[i];
     cout<<endl;
}

int main()
{
  char ch;
  int i,n,large;
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
       if(large<strlen(a[i]))
       {
         large=strlen(a[i]);
       } 
  }
    rsort(n,large);
  
  stop=clock();
   time=(double)(stop-start)/CLOCKS_PER_SEC;
   cout<<"Running time of program is: " <<time<<endl;
  return 0;
}








 



