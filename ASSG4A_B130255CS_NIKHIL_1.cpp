#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<iostream>
using namespace std;

int a[100],flag2=-1;
struct bst
{
   int val;
   bst *rt;
   bst *lt;
}*root1,*head;


 bst* createnode(int x)
{
  bst *temp = new(bst);
  temp->rt = NULL;
  temp->lt = NULL;
  temp->val = x;
  return(temp);
}

    bst * insert(int j,int n)
    {
         bst *root;
        int l,r;

        l=2*j+1;
        r=2*j+2;
        if(j < n)
        {
            if(a[j]!=-1)
            {
            root= createnode(a[j]);
            root->lt = insert(l,n);
            root->rt = insert(r,n);
            }
            else
            {
              root=NULL;
            }
        }
        else
         {
           root=NULL;
           }
        return root;
    }


void in_order( bst *temp)
 {
   if (temp != NULL) {
      in_order(temp->lt);
      printf("%d ", temp->val);
      in_order(temp->rt);
   }

 }
int in_order1( bst *temp)
 {
   if (temp != NULL) {
      in_order1(temp->lt);
      if(flag2>temp->val)
        return 0;
        flag2=temp->val;
      in_order1(temp->rt);
   }
   else
    return 1;

 }


int Bstnode_count(int flag3, bst * node, int *minr, int *maxr,
                            int *msize, int *flag_bst )
{

  flag3=0;
  if (node == NULL)
  {
     *flag_bst = 1;
     return 0;
  }

  int min = 10000;
  int nulll = 0;
  int nullr = 0;
  int ls, rs;

  *maxr = -1000;
  ls = Bstnode_count(flag3,node->lt, minr, maxr, msize, flag_bst);
  if (*flag_bst == 1 && node->val > *maxr)
     nulll = 1;

  min = *minr;

  *minr =  10000;
  rs = Bstnode_count(flag3,node->rt, minr, maxr, msize, flag_bst);
  if (*flag_bst == 1 && node->val < *minr)
     nullr = 1;

  if (min < *minr)
     *minr = min;
  if (node->val < *minr)
     *minr = node->val;
  if (node->val > *maxr)
     *maxr = node->val;


  if(nulll && nullr)
  {
     if (ls + rs + 1 > *msize)
         *msize = ls + rs + 1;
     return ls + rs + 1;
  }

  else
  {
     *flag_bst = 0;
     return 0;
  }
}




int main()
{
    int i=0,var,m,flag3=0;
    char ch;
    bst *node;
    cin>>m;

    for(;;)
    {
       if(scanf("%d%c",&a[i],&ch)==2&& ch!='\n')
       {
         if((a[i]<=0)&&a[i]!=-1)
         {
            cout<<" invalid entry "<<endl;
            return 0;
         }
         i++;

       }
       else
        break;
    }

  var=in_order1(insert(0,i+1)->lt);

  int min = 10000;
  int max = -1000;
  int max_size = 0;
  int flag_bst = 0;
  Bstnode_count(flag3,insert(0,i+1), &min, &max, &max_size, &flag_bst);

cout<<"  MAX BST:  "<<max_size<<endl;

}

























