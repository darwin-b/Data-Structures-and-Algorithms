#include<stdio.h>
#include<string.h>
#include<time.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std ;

int l,r,heapsize,greatest;

char a[10000][10000];
char temp[10000];

void swap(char a[10000][10000], int i, int j)
{	
	strcpy(temp,a[i]);
  strcpy(a[i],a[j]);
  strcpy(a[j],temp);
}


void maxheapify(int i)
{
   l=2*i;
   r=2*i+1;
   if(l<=heapsize && (strcmp(a[l],a[i])>0))
     greatest=l;
   else
     greatest=i;
   
  if(r<=heapsize && (strcmp(a[r],a[greatest])>0))
     greatest=r;
  if(greatest!=i)
  {
      swap(a,i,greatest);
      maxheapify(i);
  }     
      
}

 void buildmax(int n)
{
    int i;
    heapsize=n;
    for(i=n/2;i>=1;i--)
     maxheapify(i);    
}     

void heapsort(int n)
{
    int i;
    buildmax(n);
    for(i=n;i>=2;i--)
    {
       swap(a,i,1);
   
       heapsize=heapsize-1;
       maxheapify(1);
    }  
}
 
int main()
{
   int i,n;
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
      cin >>  a[i] ;
      if(cin.fail())
        {
            cout<<"Invalid Entry"<<endl;
            exit(1);
        }
    } 
     
   heapsort(n);
   for(i=1;i<=n;i++)
   cout<<endl<<a[i] ;
   cout<<endl;
    
   stop=clock();
   time=(double)(stop-start)/CLOCKS_PER_SEC;
   cout<<"Running time of program is: " <<time<<endl;
   
   return 0;
}
   
   
 
  
  
  
  
  
 
  
   
   
   
