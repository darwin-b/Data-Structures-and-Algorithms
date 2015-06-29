#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include<string.h>
#include<limits.h>
#include<time.h>

int a[100000000],L[100000000],R[100000000];

void merge(int a[100000000],int p,int q,int r)
{
   int i,j,k,ls,rs;
   ls = q-p+1;
   rs = r-q;
   for(i=1;i <= ls ;i++)
   L[i] = a[p+i-1];
   for(j=1;j <= rs ;j++)
   R[j] = a[q+j];
   
   L[ls+1] = 10000;   
   R[rs+1] = 10000;
   
   i = 1;
   j = 1;
   
   for(k=p;k<=r;k++)
   {
     if(L[i] <= R[j])
     {
       a[k] = L[i];
       i++;
     }
     else
     {
       a[k] = R[j];
       j++;
     }
   }
}

void mer_sor(int a[100000000],int p,int r)
{
    if (p < r)
    {
       int q = (p+r)/2;
       mer_sor(a,p,q);
       mer_sor(a,q+1,r);
       merge(a,p,q,r);
    }
}


int srtfile(char s[],long int size)
{
    FILE *fp;    
    int n,i,l;    
    int array[1048580];
    fp=fopen(s, "r");   
   
    for(i=0;i<size;i++)
    fscanf(fp,"%d ",&array[i]);
    n=i;
   
    fclose(fp);
    fp=fopen(s,"w");
 
    mer_sor(array, 0, n-1) ;
 

    for(i=0; i< n; i++)
     fprintf(fp,"%d\n",array[i]);
    
    fclose(fp);
    return 0;
}



int main(int argc, char *argv[])
{
 
   // clock_t start,stop;
    //double time;
    //start=clock();
    

FILE *fp ;

fp = fopen (argv[1], "w" ) ;
srand(time(0));
int c=0,n,count=0,max,size=0;
long long int num;

 while(c<=pow(2,26))
 {
   num = random()%1000;  
   fprintf(fp,"%lld\n",num);    
     c++;
 }
 fclose(fp);   
   
//divide(argv[1]);  

 return 0;


  
   
    //stop=clock();
    //time=(double)(stop-start)/CLOCKS_PER_SEC;
    //cout<<"Running time of program is: " <<time<<endl;
    //return 0;
}

