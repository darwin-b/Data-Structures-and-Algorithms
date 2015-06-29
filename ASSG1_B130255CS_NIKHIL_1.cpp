#include<iostream>
#include<stdio.h>
using namespace std;

long long int s;
long long int rev (long long int n)
{
    int r;

    r=n%10;
    s=s*10 + r;
    if((n/10)==0)
        return s;
    else
        return rev(n/10);

}

int main()
{
    long long int n;
    char c;
    if((scanf("%lld%c",&n,&c)!=2) || c !='\n')
    {
        cout<<"Invalid entry";
        return 1;
    }
    /*cin>>n;
    if(cin.fail())
    {
        cout<<"Invalid entry ";
        return 0;
    }*/

    if(n<=0)
    {
        cout<<"Input cannot be a Non-Positive number ";
        return 1;
    }
    if(n>2147483648)
    {
        cout<<"input limit exceeded" ;
        return 1;
    }
    else
    cout<<rev(n);
    return 0;
}
