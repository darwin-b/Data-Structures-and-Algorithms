#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <iostream>
using namespace std;

struct node{
   int x;
   node *next;

} *list[100]={NULL};

int s=0;

struct Queue{
	struct q_node *head;
	struct q_node *tail;
};


struct q_node{
	struct bin_node *value;
	struct q_node *next;
};


struct bin_node{
	int val;
	struct bin_node *rt;
	struct bin_node *lt;
}*h,*lists[100];


void insert(bin_node *head, int val)
{
	if(head==NULL)
	{
		//cout<<" him ";
		bin_node *temp = new (bin_node);
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
		    	 	bin_node *temp = new (bin_node);
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
		    	 	bin_node *temp = new (bin_node);
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




int check_null(struct Queue *q){
	return (q->head==NULL && q->tail==NULL);
}

struct q_node* ctr_node(struct bin_node *item){
	q_node *qn = new (q_node);
	qn->value = item;
	qn->next = NULL;
	return qn;
}

int enqueue(struct Queue *q, struct bin_node *item){
	q_node *tmp = ctr_node(item);
	if(check_null(q)){
		q->head = q->tail = tmp;
		s++;
		return 1;
	}
	q->tail->next = tmp;
	q->tail = tmp;
	s++;
	return 1;
}


struct Queue *ctr_qnode(){
    Queue *q = new(Queue);
	q->tail = q->head = NULL;
	return q;
}

struct bin_node *deQueue(struct Queue *q){
	if(check_null(q)){
		return NULL;
	}
	struct bin_node *item = q->head->value;
	q->head = q->head->next;
    s--;
	if(q->head == NULL){
		q->tail = NULL;
	}

	return item;
}

struct bin_node *ctr_bnode(int val){
	struct bin_node *bn = (struct bin_node*) malloc(sizeof(bin_node));
	bn->val = val;
	bn->lt = NULL;
	bn->rt = NULL;
	return bn;
}

void in_order(bin_node *head)
{

  if(head==NULL)
  	return;
  in_order(head->lt);
  cout<<head->val<<" ";
  in_order(head->rt);
}

int main(){
	int c,n,val,k,i,a[1000],j,x,y;
    cin>>n;
    if(n<0){
        cout<< " invalid entry "<<endl;
        exit(1);
    }

    for(j=0,k=1;j<n;j++,k++)
    {
        cin>>a[j];

        if((a[j]<=0)&&a[j]!=-1)
        {
            cout<<" invalid entry "<<endl;
            return 0;
        }

        if(a[j]==-1)
        {
            j--;
            continue;
        }
    }


   for(x=0;x<n;x++)
   {
       for(y=0;y<n;y++)
       {
           if(x!=y)
           if(a[y]==a[x])
           {
               cout<<" element entered or not unique" <<endl;
               exit(1);
           }
       }
   }



    for(i=0;i<n;i++)
    {
        insert(h,a[i]);
    }

    in_order(h);
    cout<<endl<<endl;
	                    //prnt_level_nodes(h);
    bin_node *root=h;
    if(!root){
		return 0;
	}


	                   // enqueue the root
	struct Queue *queue = ctr_qnode();
	enqueue(queue, root);
    int v=s;
    i=-1;
    while(s!=0) {
            v=s;
            i++;
	while(v>0){
        {
		bin_node *bn = deQueue(queue);
		node *temp2=new (node);
		temp2->x=bn->val;
            temp2->next=NULL;
		if(list[i]==NULL)
        {

            list[i]=temp2;
        }
        else{
           node *temp = new (node);

           temp=list[i];
           while(temp->next!=NULL) {
              temp=temp->next;
           }

            temp->next=temp2;
        }

		if(bn->lt){

			enqueue(queue, bn->lt);
        }
		if(bn->rt){
			enqueue(queue, bn->rt);
		}
        }
        v--;
	}

    }

  j=0;
    for(j=0;j<=i;j++)
   {
      node *temp=list[j];
      while(temp!=NULL) {
         if(temp->next!=NULL)
           cout<< temp->x << "->";
         else
            cout<<temp->x;

         temp=temp->next; }

         cout << endl;
   }


   //link_lists(a,n,k);

	return 0;
}

