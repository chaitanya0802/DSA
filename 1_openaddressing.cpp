#include<iostream>
#include<string.h>
#define size 10
using namespace std;

class Hashtable
{
    public:
    int key=-1;
    string record="--";
}Hashtable[size];

void insert()
{   int val;
    cout<<"How many Values do you want to enter: ";
    cin>>val;
    for(int i=0;i<val;i++)
    {
        int keyval,pos;
        string recordval;
        cout<<"Enter the key: \n";
        cin>>keyval;
        cout<<"Enter the its Record: \n";
        cin>>recordval;

        pos=keyval % size;

        if(Hashtable[pos].key==-1)
        {
            Hashtable[pos].key=keyval;
            Hashtable[pos].record=recordval;
        }
        else
        {
            int i, flag=0;
            for(i=pos+1;i<size;i++)
            {
                if(Hashtable[i].key==-1)
                {
                    Hashtable[i].key=keyval;
                    Hashtable[i].record=recordval;
                    flag=1;
                    break;
                }
            }

            for(i=0;i<pos && flag==0;i++)
            {
                if(Hashtable[i].key==-1)
                {
                    Hashtable[i].key=keyval;
                    Hashtable[i].record=recordval;
                    flag=1;
                    break;
                }
            }
        }
    }
}

void display()
{
    cout<<"\n The hashtable is:"<<endl;
    cout<<"Index"<<"\t"<<"Key"<<"\t"<<"Record";
    for(int i=0;i<size;i++)
    {
       cout<<"\n"<<i<<"\t"<<Hashtable[i].key<<"\t"<<Hashtable[i].record;
    }
}

void deletekey()
{   
    int key2,pos;
    cout<<"Enter the key to delete: \n";
    cin>>key2;
    pos=key2 % size;
    if(Hashtable[pos].key==key2)
    {
        Hashtable[pos].key=-1;
        Hashtable[pos].record="--";
        cout<<"Key and Record deleted successfully.\n";
    }
    else
    {
        int i, flag=0;
        for(i=pos+1;i<size;i++)
        {
        if(Hashtable[i].key==key2)
            {
                Hashtable[i].key=-1;
                Hashtable[i].record="--";
                cout<<"Key and Record deleted successfully.\n";                
                flag=1;
                break;
            }
        }

        for(i=0;i<pos && flag==0;i++)
        {
            if(Hashtable[i].key==-key2)
            {
                Hashtable[i].key=-1;
                Hashtable[i].record="--";
                cout<<"Key and Record deleted successfully.\n";
                flag=1;
                break;
            }
        }
    }
}

int main()
{
    char ans;
    do
    {
        int ch;
        cout<<"\n Enter your choice: \n 1)insert \n 2)Display \n 3)Delete \n"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
            insert();
            cout<<"Insertion of key and record is successful.";
            break;

            case 2:
            display();
            break;
            
            case 3:
            deletekey();
            break;

            default:
            cout<<"Invalid choice!";
        }
    }while(ans='y');
}