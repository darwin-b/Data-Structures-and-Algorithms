#include<iostream>
#include<cstdlib>
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
			 if(val==head->val)
			{
				cout<<" element already present in tree"<<endl;
				return;
			}
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


void bin_search(node *head , int val)
{
   int i,j;
   if(head==NULL)
   {
   	cout<<" NOT FOUND "<<endl;
   	return;
   }
   for(;head!=NULL;)
   {
      if(val==head->val)
      {
   	     cout<<" FOUND "<<endl;
   	     return;
      }
      else if(val>(head->val))
      	head=head->rt;
      else
      	head=head->lt;

   }
   cout<<" NOT FOUND "<<endl;
}

void max_tree(node *head)
{
	if(head==NULL)
	{
		cout<<" TREE IS EMPTY ";
		return;
	}
	for(;head->rt!=NULL;)
	{
		head=head->rt;
	}
	cout<<head->val<<endl;
}

node* min_tree(node *head)
{
    int j;
	if(head==NULL)
	{

        return head;
	}
	for(;head->lt!=NULL;)
	{
		head=head->lt;
	}
	//cout<<head->val<<endl;
	return head ;
	//return head->val;
}

void in_order(node *head)
{

  if(head==NULL)
  	return;
  in_order(head->lt);
  cout<<head->val<<" ";
  in_order(head->rt);
}

void pre_order(node *head)
{

  if(head==NULL)
  	return;

  cout<<head->val<<" ";
  pre_order(head->lt);
  pre_order(head->rt);
}

void post_order(node *head)
{

  if(head==NULL)
  	return;

  post_order(head->lt);
  post_order(head->rt);
  cout<<head->val<<" ";
}
/*
void del(node *head , int val)
*/

struct node* del(struct node* head, int val)
{
/*
    {
    int i,j;
	node *temp,*temp2;
	temp2=head;
	if(head==NULL)
   {
   	cout<<" TREE EMPTY or ELEMENT NOT PRESENT "<<endl;
   	return;
   }
   for(;head!=NULL;)
   {
      if(val==head->val)
      {

        if((head->rt)!=NULL)
        {
            j=successor(head);
            head->val=j;
           // bin_search(head,j);


        }

      }

      else if(val>(head->val))
      	{
      	    temp2=head;
      	    head=head->rt;
      	}
      else
      	{
      	    temp2=head;
            head=head->lt;
      	}

   }

}

*/

    if (head == NULL)
        return head;
    if (head->val > val)
    head->lt = del(head->lt, val);

    else if (head->val < val)
    head->rt = del(head->rt, val);

    else
    {
        if (head->lt == NULL)
        {
            struct node *temp = head->rt;
            free(head);
            return temp;
        }
        else if (head->rt == NULL)
        {
            struct node *temp = head->lt;
            free(head);
            return temp;
        }

        struct node* temp = min_tree(head->rt);
        head->val = temp->val;
        head->rt = del(head->rt, temp->val);
    }
    return head;
}



int successor(node *head, int val)
{

   int i,j,k,flag=0;
   if(head==NULL)
   {
   	cout<<" NOT FOUND "<<endl;
   	return -1;
   }
   for(;head!=NULL;)
   {
      if(val==head->val)
      {
         {                                        // after search element found
             if(head->rt!=NULL)
             {
                cout<<min_tree(head->rt)->val<<endl;
             }
             else
             {
                 if(flag==1)
                    {
                        cout<<k<<" hello "<<endl;
                        return k;
                    }
                else
                    cout<<" NO SUCCESSOR "<<endl;
             }
         }

   	     return -1 ;
      }
      else if(val>(head->val))
      	head=head->rt;
      else
      	{

               flag=1;
               k=head->val;
      	       head=head->lt;

      	}

   }                                                //cout<<" NOT FOUND "<<endl;
}



void predecessor(node *head, int val)
{

   int i,j,k,flag=0;;
   if(head==NULL)
   {
   	cout<<" NOT FOUND "<<endl;
   	return;
   }
   for(;head!=NULL;)
   {
      if(val==head->val)
      {

         {                                        // after search element found
             if(head->lt!=NULL)
             {
                 max_tree(head->lt);
             }
             else
             {
                 if(flag ==1)
                    cout<<k<<" hello "<<endl;
                 else
                    cout<<"NO PREDECESSOR"<<endl;
             }
         }

   	     return;
      }
      else if(val>(head->val))
      	{
                 k=head->val;
                 flag=1;
      	         head=head->rt;
      	}
      else
      	head=head->lt;

   }                                                         //cout<<" NOT FOUND "<<endl;

}





int main()
{
   int c,n,i,f,val;
   node *l=NULL,*r=NULL;
   while(1)
   {
   	cin>>c;
   	if(cin.fail())
    {
        cout<<" INVALID CHOICE "<<endl;
    }
    switch(c)
   	{
   		case 0:
   		return 0;

   		case 1:
        cin>>val;
        if((cin.fail())||(val<0))
        {
            cout<<"INVALID ENTRY" <<endl;
            return 0;
        }

   		insert(h,val);
   		//cout<<h->val;
   		break;

   		case 2:
        cin>>val;
        if((cin.fail())||(val<0))
        {
            cout<<"INVALID ENTRY" <<endl;
            return 0;
        }
        bin_search(h,val);
   		/*
   		l=h;
   		for(;l!=NULL;)
   		{
   			cout<<l->val<<" hi ";
   			l=l->lt;
   		}
   		*/
        break;

   		case 3:
   		if(min_tree(h)==NULL)
   		{
   		    cout<<" TREE EMPTY "<<endl;
   		}
   		else
            cout<<min_tree(h)->val<<endl;
   		break;

   		case 4:
   		max_tree(h);
   		break;

   		case 5:
        cin>>val;
        if((cin.fail())||(val<0))
        {
            cout<<"INVALID ENTRY" <<endl;
            return 0;
        }
   		predecessor(h,val);
   		break;

   		case 6:
        cin>>val;
        if((cin.fail())||(val<0))
        {
            cout<<"INVALID ENTRY" <<endl;
            return 0;
        }
        f=successor(h,val);
   		break;

   		case 7:
   		cin>>val;
   		if((cin.fail())||(val<0))
        {
            cout<<"INVALID ENTRY" <<endl;
            return 0;
        }

        if(h==NULL)
        {
            cout<<" empty "<<endl;
            break;
        }
   		h=del(h,val);
   		break;

   		case 8:
   		    if(h==NULL)
            {
                cout<<" TREE EMPTY"<<endl;
            }
   		in_order(h);
   		break;

   		case 9:
   		     if(h==NULL)
            {
                cout<<" TREE EMPTY"<<endl;
            }
   		pre_order(h);
   		break;

   		case 10:
   		     if(h==NULL)
            {
                cout<<" TREE EMPTY"<<endl;
            }
   		post_order(h);
   		break;

   		default:
            cout<<"INVALID CHOICE"<<endl;
   	}
   }
   return 0;
}




