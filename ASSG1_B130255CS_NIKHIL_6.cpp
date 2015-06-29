#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

struct stud
{
    float mark[5];
    char name[20],br[20],rnum[10];
};

int main(int argc,char *argv[])
{
    if (argc < 2){
        cout << "error\n";
        return 1;
    }
    FILE *fp;
    struct stud s;

    int i,j,k=0,l,m,n;
    float sum;
    char a,b,c,filename[30];
    strcpy(filename,argv[1]);
       fp=fopen(filename,"ab+") ;
       if(fp==NULL)
       {
           cout<<"Cannot open file";
           return 1;
       }											
    do{

        cout<<"Menu: \na) Append record \nb)Display all the records \nc) Count the records and calculate the average total-marks \nd) Exit \n" ;
        cout<<"Enter your choice: ";
        cin>>c;
       
       switch (c)
       {
        case 'a':
            fseek(fp,0,SEEK_END);
            cout<<"Enter Name, Roll number, Branch, Marks of 5 subjects: \n" ;
            cin>>(s.name);
            cin>>(s.rnum);
            cin>>(s.br);
            for(i=0;i<5;i++)
            {
                if((scanf("%f%c",&s.mark[i],&c)!=2) || c !='\n')
                {
                   cout<<"Invalid entry";
                   return 1;
                }
            }
            //cout<<endl<<s.name<<s.rnum<<s.br<<endl<<endl<<endl;
            fwrite(&s,sizeof(stud),1,fp);
            break;

        case 'b':
            rewind(fp) ;
            j=0;
            
            while(fread(&s,sizeof(s),1,fp)==1)
            {   
                j++;
                cout<<s.name<<endl<<s.rnum<<endl<<s.br<<endl;
                for(i=0;i<5;i++)
                {
                  cout<<s.mark[i]<<endl;
                }
            }
            if(j==0)
            cout<<"\n No Entries to display \n\n";
            break;

        case 'c':
            sum=0;
            j=0;
            rewind(fp) ;
            while(fread(&s,sizeof(s),1,fp)==1)
            {
                j=j+1;
                for(i=0;i<5;i++)
                sum=sum+s.mark[i];
            }

                cout<<"\nTotal number of records: "<<j<<endl ;
                if(j==0)
                cout<<"\n Average total marks: 0 \n\n";
                else
                cout<<"\n Average total marks: "<<sum/j<<endl<<endl ;

            break;
        case 'd':
            return 0;

        default:
            cout<<"\n\n Choose among the displayed choices \n\n";
       }
  }while(1);

}


