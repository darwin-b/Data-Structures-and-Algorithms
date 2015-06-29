#include<iostream>
#include<stdio.h>
using namespace std;

float area(float *l, float *b)
{
    return *l * *b;
}

float perimeter(float *l, float *b)
{
    return 2*(*l + *b);
}


int main()
{
    float l,b;
    char c,x;
    float (*ar)(float*,float*) = area ;
    float (*peri)(float*,float*) = perimeter;
    cout<<"Enter Length: \n";
    if((scanf("%f%c",&l,&x)!=2) || x !='\n')
    {
           cout<<"Invalid entry";
           return 1;
    }

    cout<<"Enter Breadth: \n";
    if((scanf("%f%c",&b,&x)!=2) || x !='\n')
    {
           cout<<"Invalid entry";
           return 1;
    }

    if((l<=0)||(b<=0))
    {
        cout<<"Entry cannot be non-positive:";
        return 1;
    }

       do{
        cout<<"   Menu \n    1. Area \n    2. Perimeter \n    3. Exit \n\nEnter the choice: \n";
        cin>>c;
        switch(c)
        {
        case '1':
            cout<<"Area: \n"<<(*ar)(&l,&b)<<"\n";
            break;
        case '2':
            cout<<"Perimeter: \n"<<(*peri)(&l,&b)<<"\n";
            break;
        case '3':
            break;
        default:
            cout<<"Enter valid choice: \n";
        }
    }while(c!='3');
    return 0;
}
