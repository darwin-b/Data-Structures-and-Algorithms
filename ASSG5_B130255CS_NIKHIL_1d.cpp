#include<iostream>
using namespace std;
                ///With ranked union and with path compression
struct node
{
    int data;
    int rank;
    node *p;
}*a[1000],*rep;

int i=0;

node *make_set(int x)
{
    node *temp = new (node) ;
    temp->data=x;
    temp->rank=0;
    temp->p=temp;
    a[i]=temp;
    i++;
}

node *search(int x)
{
    int j,n;
    j=i-1;
    for(;j>=0;j--)
    {
        if(a[j]->data==x)
            return a[j];
            //cout<<" hi ";
    }

    cout<< "ERROR"<<endl;
    return NULL;
}

node* path_comp(node* temp)
{
    if(temp->p!=temp)
      temp->p =path_comp(temp->p);
      return temp->p;
}


node *find_set(int x)
{
    node *temp;
    temp=search(x);

   return path_comp(temp);

}


node *join(int x, int y)
{
    node *temp1,*temp2,*temp3,*temp4;
    //temp1=search(x);
    //temp2=search(y);
    temp3= find_set(x);
    temp4= find_set(y);
    if(temp3==temp4)
        return NULL;
    if((temp3->rank)>(temp4->rank))
       temp4->p=temp3;
    else if((temp3->rank)<(temp4->rank))
       temp3->p=temp4;
       else
       {
           temp4->p=temp3;
           temp3->rank = temp3->rank + 1;
       }
}



int main()
{
    int c,x,y;

    while(1)
    {
        cin>>c;
        switch(c)
        {
        case 1:
            cin>>x;
            make_set(x);
            break;
        case 2:
            cin>>x;
            cout<<find_set(x)->data<<endl;
            break;
        case 3:
            cin>>x>>y;
            join(x,y);
            break;
        case 4:
            return 0;
        default:
            cout<<" Invalid Entry " <<endl;

        }

    }

return 0;


}
