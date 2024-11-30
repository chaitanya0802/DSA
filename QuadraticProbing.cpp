/*Program in C++ to create hashtable of size 10 and function to insert, display,
 delete,search record by quadratic probing collision technique*/
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
    cout<<"\n How many Values do you want to enter: ";
    cin>>val;
    for(int i=0;i<val;i++)
    {   
        int key1,pos;
        string record1;
        cout<<"\nEnter the Key: ";
        cin>>key1;
        cout<<"\nEnter the record: ";
        cin>>record1;
        pos=key1 % size;
        if(Hashtable[pos].key==-1)
        {
            Hashtable[pos].key=key1;
            Hashtable[pos].record=record1;
        }
        else
        {
            for(i=0;i<size;i++)
            {
                pos=(key1+(i*i))%size;
                if(Hashtable[pos].key==-1)
                {
                    Hashtable[pos].key=key1;
                    Hashtable[pos].record=record1;
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
    int delkey,pos;
    cout<<"Enter the key to be deleted: ";
    cin>>delkey;
    pos=delkey % size;
    if(Hashtable[pos].key!=-1)
    {
        for(int i=0;i<size;i++)
            {
                pos=(delkey+(i*i))%size;
                if(Hashtable[pos].key!=-1)
                {
                    Hashtable[pos].key=-1;
                    Hashtable[pos].record="--";
                    break;
                }
            }
        }
    cout<<"Key and Record deleted successfully.\n";
}

void search()
{   int key1,pos;
    cout<<"Enter the key to search: \n";
    cin>>key1;
    pos=key1 % size;
    if(Hashtable[pos].key!=-1)
    {
        for(int i=0;i<size;i++)
        {
            pos=(key1+(i*i))%size;
            if(Hashtable[pos].key==key1)
            {
                cout<<"\nThe index of key: "<<key1<<" is: "<<pos;
                break;
            }
        }
    }
    cout<<"\n Search was successfull.";
}

int main()
{
    char ans;
    do
    {
        int ch;
        cout<<"\n Enter your choice: \n 1)insert \n 2)Display \n 3)Delete \n 4)Search"<<endl;
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

            case 4:
            search();
            break;

            default:
            cout<<"Invalid choice!";
        }
    }while(ans='y');
}