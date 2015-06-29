#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
int i=0,c;
const float a = 0.618033;
 int hash_fun1(int key)
 {
 	return (key%c);
 }

 int hash_fun2(int key)
 {
  int j;
  j= floor(c*(key*a-floor(key*a)));
  return j;
 }

 int hash_linear(int key)
 {
     int j;
     j= ( hash_fun1(key) + i*hash_fun2(key) ) %c;
     return j;
 }
 void insert (int a[],int key)
 {
 	int j;
 	i=0;
 	do
 	{
       j=hash_linear(key);
       if(a[j]==-137)
       {
       	 a[j]=key;
         cout<<j<<" ";
         return;
       }
       cout<<j<<" ";
       i++;

 	}while(i!=c);
 	cout<<"HASH TABLE FULL"<<endl;
 	return;   
}

void search(int a[], int key)
{
	i=0;
	int j;
	do
	{
		j=hash_linear(key);
		if(a[j]==key)
		{
			cout<<j<<" "<<" FOUND "<<endl;
			return ;
		}
		cout<<j<<" ";
		i=i+1;
	}while((a[j]!=-137)&&(i<c));
    cout<<" NOT FOUND "<<endl;
}

 int main()
 {
 	int n,val,key,a[10000],j,t,ch,k;
 	cin>>c;
 	for(k=0;k<c;k++)
 	{
 		a[k]=-137;
 	}
    
 	while(1)
 	{

 		cin>>ch;  
        switch(ch)
        {
           case 0:
           return 0;

           case 1:
           cin>>key;
           insert(a,key);
           cout<<endl;
           break;

           case 2:
           cin>>key;
           search(a,key);
           break ;
           
           default:
           cout<<" error "<<endl;
           break;
           
        }
        
 	}
 	
 }