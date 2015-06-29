#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

struct data
{
    int age;
    char name[30];
    union id_number
    {
        long long int aadhar;
        char a[8];

    }id;
};

/*
0 < age < n
name: -any character array
aadhar number - no mention ...but strictly number...no characters allowed
voter id: exactly 7 characters of Upercase or numbers... no othercharacters allowed
 */

int main()
{
    int i;
    data person;
    char c;

    cout<<"Enter name: \n";
    cin>>person.name;
    cout<<"Enter age: \n";
    if((scanf("%d%c",&person.age,&c)!=2) || c !='\n')
    {
           cout<<"Invalid entry";
           return 1;
    }


    /*if(cin.fail())
    {
        cout<<"Invalid entry";
        return 0;
    } */

    if(person.age>0)
      if(person.age<18)
      {
          cout<<"Enter Aadhar card number: \n";
          if((scanf("%lld%c",&person.id.aadhar,&c)!=2) || c !='\n')
          {
           cout<<"Invalid entry";
           return 1;
          }
          if(person.id.aadhar<0)
          {
              cout<<"Adhaar card cannot be negative" ;
          }

          cout<<person.name<<", "<<person.age<<", "<<person.id.aadhar;

      }
      else
      {
          cout<<"Enter Voter-Id: \n" ;
          cin>>person.id.a;
          if(strlen(person.id.a)!=7)
          {
              cout<<"Invalid entry of voter id: \n";
              return 1;
          }
          for(i=0;i<7;i++)
          if(!(isdigit(person.id.a[i]) || isupper(person.id.a[i])))
          {
              cout<<"Invalid entry of voter id: \n";
              return 1;
          }
          cout<<person.name<<", "<<person.age<<", "<<person.id.a;
      }

      else
          cout<<"AGE cannot be negative \n";
      return 0;
}
