 #include<iostream>
 #include<string.h>
 #define size 10
 using namespace std;

 class hashtable
 {  
    public:
    int key=-1;
    string record="--";
    int chain=-1;
 }hashtable[size];

void insertdata()
{
    char ans1;
    do
    {
        int keyval;
        string recordval;
        int pos;
        cout<<"\nEnter the key: ";
        cin>>keyval;
        cout<<"\nEnter the record: ";
        cin>>recordval;

        pos=keyval % size; //Hashfunction

        if(hashtable[pos].key==-1)
        {
            hashtable[pos].key=keyval;
            hashtable[pos].record=recordval;
            cout<<"\nKey and record inserted successfully. "<<endl;
        }
        else
        {   
            int flag=0;
            for(int i=pos+1;i<size;i++)
            {
                if(hashtable[i].key==-1)
                {
                    hashtable[i].key=keyval;
                    hashtable[i].record=recordval;
                    if(hashtable[pos].chain==-1)
                    {
                    hashtable[pos].chain=i;
                    }
                    else
                    {
                        int flag1=0;
                        for(int j=pos+1;j<size;j++)
                        {
                            if(hashtable[j].chain==-1)
                            {
                                hashtable[i].chain=j;
                                flag1=1;
                            }
                        }
                    }
                    cout<<"\nKey and record inserted successfully. "<<endl;
                    flag=1;
                    break;
                }
            }
            for(int i=0;i<pos && flag==0;i++)
            {
                if(hashtable[i].key==-1)
                {
                    hashtable[i].key=keyval;
                    hashtable[i].record=recordval;
                    cout<<"\nKey and record inserted successfully. "<<endl;
                    flag=1;
                    break;
                }
            }
        }
        cout<<"\nDo you want to enter more values? ";
        cin>>ans1;
        cout<<"\n----------------------------";
    }while((ans1=='y')); 
}

void displaydata()
{
    cout<<"\nThe Hashtable is:";
    cout<<"\n"<<"index"<<"\t"<<"Key"<<"\t"<<"Record"<<"\t"<<"Chain";
    for(int i=0;i<10;i++)
    {   
        cout<<"\n"<<i<<"\t"<<hashtable[i].key<<"\t"<<hashtable[i].record<<"\t"<<hashtable[i].chain;
    }
}

void search()
{   int key1,pos;
    cout<<"Enter the key to search: \n";
    cin>>key1;
    pos=key1 % size;
    if(hashtable[pos].key!=-1)
    {
        int i, flag=0;
        for(i=pos+1;i<size;i++)
        {
            if(hashtable[i].key!=-1)
            {
                cout<<"The index of key is: "<<i;
                flag=1;
                break;
            }
        }
        for(i=0;i<pos && flag==0;i++)
        {
            if(hashtable[i].key!=-1)
            {
                cout<<"\n The index of key is: "<<i;
                flag=1;
                break;
            }
        }
    }
    cout<<"\n Search was successfull.";
}
int main()
{
    do
    {
        int ch;
        cout<<"\n Enter your choice: \n 1)insert \n 2)Display \n 3)Search"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
            insertdata();
            break;

            case 2:
            displaydata();
            break;

            case 3:
            search();
            break;

            default:
            cout<<"Invalid choice!";
        }
    }while(1);
}