#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<iostream>
using namespace std;

int top,c1=0,c2=0;


struct opp
{
   char x;

   struct opp *rt;
   struct opp *lt;

}*a[100];

int opperator(char c)
{
	if( (c=='^')||(c=='+')||(c=='-')||(c=='/')||(c=='*') )
		return 1;
	else if((c>='a')&&(c<='z'))
		return 0;
		else{
            cout<< " INVALID ENTRY "<<endl;
            exit(1);
		}
}

void inorder(struct opp* head)
{
    if (head == NULL)
    return;

     if(head->rt==NULL&& head->lt==NULL)
        cout<<head->x;
     else
    {
            cout<<"(" ;
            inorder(head->lt);
            cout<<" "<<head->x<<" ";
            inorder(head->rt);
            cout<<")";
    }
}

void preorder(struct opp *head)
{
    if (head == NULL)
    return;

     if(head->rt==NULL&& head->lt==NULL)
        cout<<head->x;
     else
    {
            cout<<"(" ;
            cout<<" "<<head->x<<" ";
            inorder(head->lt);
            inorder(head->rt);
            cout<<")";
    }

}

void postorder(struct opp *head)
{

    if (head == NULL)
    return;

     if(head->rt==NULL&& head->lt==NULL)
        cout<<head->x;
     else
    {
            cout<<"(" ;
            inorder(head->lt);
            inorder(head->rt);
            cout<<" "<<head->x<<" ";
            cout<<")";
    }

}


struct opp* pop()
{
  int temp=top;
  if(top==-1)
  {
    cout<<" ERROR2 "<<endl;
    exit(1);
  }
  else
  {
    top--;
    return(a[temp]);
  }
}

 int push(struct opp *node,int flag)
{
  if(flag==1)
  {
      flag=0;
      a[0]=node;
      top=0;
  }
  else
  {
    top=top+1;
    a[top]=node;
  }
  return flag;
 }


struct opp* allocate(char c)
{
  opp *temp = new (opp);
  temp->x = c;
  temp->lt = NULL;
  temp->rt = NULL;
  return(temp);
}


void creat_EXPTREE(char s[])
{

    int i,k=1;
    opp *node;
    for(i=0;s[i]!='\0';i++)
    {

       if(opperator(s[i]) ==0)
       {
         c1++;
         opp *node=allocate(s[i]);
         k= push(node,k);
       }
       else
       {
          c2++;
          node=allocate(s[i]);
          node->lt=pop();
          node->rt=pop();
          k = push(node,k);
       }
    }
}



int main()
{

char a[1000];
struct opp *head;
cin>>a;

creat_EXPTREE(a);

head=pop();
//cout<<c1<<c2;
if(c1!=(c2+1))
    {
        cout<<" ERROR1 ( operator and operands length didnt match)"<<endl;
        return 0;

    }
if(head==NULL)
{
    cout<<" ERROR "<<endl;
    exit(1);
}
else
{
    cout<<" INORDER    : ";
    inorder(head);
    cout<<endl<<" PREORDER   : ";
    preorder(head);
    cout<<endl<<" POSTORDER  : ";
    postorder(head);
}
 return 0;
}











