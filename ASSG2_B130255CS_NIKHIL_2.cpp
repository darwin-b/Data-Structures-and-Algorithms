#include<iostream>
#include<cstdlib>

using namespace std;

int bns(int a[1000],int f,int l, int key)
{
    int mid;
    mid= (f+l)/2;
    if(f<=l)
    {
    	if(a[mid]==key)
    		return mid;
    	if(key>a[mid])
    		return bns(a,mid+1,l,key);
    	else
    		return bns(a,f,mid-1,key);
    }
    else
    return -1;
}

 int bns1(int a[],int f,int l)
{
    int mid;
    mid= (f+l)/2;
    if(f<=l)
    {
    	if(a[mid] < a[mid-1])
    		return mid;
    	if(a[1] < a[mid])
    		return bns1(a,mid+1,l);
    	else
    		return bns1(a,f,mid-1);
    }
    else
    	return -1;

}



int main()
{
	int i,j,k,n,a[10000],key,x=-1,y=-1,r;
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
		cin>>a[i];
        if(cin.fail())
        {
            cout<<"Invalid Entry"<<endl;
            exit(1);
        }

	}

	cin>>key;

	r = bns1(a,1,n);
	//cout<<endl<<r<<endl;

	x=bns(a,1,r-1,key);
	y=bns(a,r,n,key);
    
     //cout<<x<<" ";
     //<<y;
     //cout<<endl ;
	
	if(x!=-1)
		cout<<"found at "<<x-1<<endl;
	
	else
	{
		if(y!=-1)
		    cout<<"found at "<<y-1<<endl;
	    else
	    	cout<<"not found "<<endl;
        
	}


    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Running time of program is: " <<time<<endl;
}
