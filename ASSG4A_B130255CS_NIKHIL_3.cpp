#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
	int val;

	node *lt;
	node *rt;
}*h=NULL,*min,*max;

void insert(node *head, int val)
{
	if(head==NULL)
	{
		//cout<<" him ";
		node *temp = new (node);
		temp->val=val;
		temp->lt=NULL;
		temp->rt=NULL;
		head = temp;
		h=head;
	}
	else
	{
		for(;;)
		{
			//cout<<" hp ";
			/* if(val==head->val)
			{
				cout<<" element already present in tree"<<endl;
				return;
			} */

			if(val>(head->val))
		    {
		    	if(head->rt!=NULL)
		    	 head=head->rt;
		    	 else
		    	 {
		    	 	node *temp = new (node);
		            temp->val=val;
					temp->lt=NULL;
					temp->rt=NULL;
					head->rt = temp;
					break;
		    	 }
		    }
		    else
		    {
		    	if(head->lt!=NULL)
                head=head->lt;
                else
                 {
		    	 	node *temp = new (node);
		            temp->val=val;
					temp->lt=NULL;
					temp->rt=NULL;
					head->lt = temp;
					break;
		    	 }
		    }
		}
	}
}

void preorder(struct node *head)
{
    if (head == NULL)
    {
        cout<<" () ";
        return;
    }
     //if(head->rt==NULL && head->lt==NULL)
       // cout<<head->val;
     else
    {
            cout<<"(" ;
            cout<<" "<<head->val<<" ";
            preorder(head->lt);
            preorder(head->rt);
            cout<<")";
    }

}


int main()
{
   int c=1,n,i,f,val;
   char ch;
   node *l=NULL,*r=NULL;

   while(1)
   {
       scanf("%d%c",&val,&ch);
       if(ch!='\n')
       {
           insert(h,val);
       }
       else{

        insert(h,val);
        break;
       }

   }


   preorder(h);




}

/*

1 40
1 35
1 19
1 65
1 93
1 3
1 27
*/



