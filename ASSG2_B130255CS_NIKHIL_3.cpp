
#include <iostream>
#include<time.h>
#include<cstdlib>


using namespace std;
int a[100000000] ;
int main(void) {
 int x,i,j,n,count=0;
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
      
    for(j=1;j<n;j++)
    {   x=a[j];
        i=j-1;
    for(;;i--)
        {        
        if((a[i]>x)&&(i>=0))
            {
            count++;
            a[i+1]=a[i];
        }
        else
            {
            a[i+1]=x;        
            break;
        }
    }
     
    }
    cout<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;  
    cout<<"inversions: "<<count<<endl;

    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Running time of program is: " <<time<<endl; 
    return 0;
}
