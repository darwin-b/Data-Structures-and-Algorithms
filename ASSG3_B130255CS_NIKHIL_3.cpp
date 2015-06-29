#include<iostream>
using namespace std;

#include<stdlib.h>
int i,c=1;
int l,r,smallest,b[10000],a[10000],k,d=0,hpsize;
  
void min_heapify(int b[],int i)
{
  int temp;
  l=2*i;
  r=2*i+1;
  if(l<=hpsize && b[l]<b[i])
    smallest=l;
   
  else
    smallest=i;
   
  if(r<=hpsize && b[r]<b[smallest])
  smallest=r;
  if(smallest!=i)
  {
      temp=b[smallest];
      b[smallest]=b[i];
      b[i]=temp;
      temp=a[smallest];
      a[smallest]=a[i];
      a[i]=temp;
     min_heapify(b,smallest);
   }     
      
}



void build_min(int b[])
{
   int i;
   hpsize=d;
   for(i=d/2;i>=1;i--)
     min_heapify(b,i);
    
}     


void insert(int a[],int x,int y) 
{
     
     if(d==0)
     {
        c=2;     
        a[1]=x;
        b[1]=y;
        d=1;
     }
     else
     {      
       d=d+1;
       a[d]=x;
       b[d]=y;
      }
 
build_min(b);
   
}       
       
void pop(int a[])
{
    int l;
    if(d>1)
    {
       cout<<a[1]<<" priority: "<<b[1]<<endl;       
       for(l=2;l<=d;l++)
       {
       	    b[l-1]=b[l];
            a[l-1]=a[l];
       } 
       d--;
       build_min(b);

    }
    else if(d==1)
         {
            d--;
            cout<<a[1]<<" priority: "<<b[1]<<endl;
         }
         else
            cout<<"stack empty"<<endl;

}       

      
void peek(int a[])
{
 
  if(d!=0)
  cout<<a[1]<<" priority: "<<b[1]<<endl;
  else
  cout<<"stack empty" <<endl;
}
 
 
 
void inc_priority(int a[],int x,int y)
{
   int l;
   for(l=1;l<=d;l++)
   {
      if(a[l]==x)
      {
          b[l]=y;
          break;
      }
   }
   build_min(b); 
}




int main()
{
     int choice,x,y;

     while(1)
     {
         cin>>choice;
          if((choice<0)&&(choice>4))
        {
        	cout<<"Invalid Choice";
        	exit(1);
        }
         switch(choice)
         {
            case 0:
            return 0;
     
            case 1:
            cin>>x>>y;  
              insert (a,x,y);  
            break;

            case 2:
              pop(a);  
              break;

            case 3:
              peek(a);
              break;

            case 4:
              cin>>x>>y;
              inc_priority(a,x,y);
              break;
              
           default:
              cout<<"Invalid Choice" <<endl;
         }

       }
       return 0;
}

 


      
  
   
 
  






