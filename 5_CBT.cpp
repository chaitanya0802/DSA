#include<iostream>
#include<string.h>
#include<math.h>
#define size 30
using namespace std;

class CBT
{   
    public:
    string nodedata ="-";
}CBT[size];

void create(int t)
{
    char root;
    int inodes;
    inodes=(t-1)/2;
    cout<<"\n Enter the root node: ";
    cin>>root;
    CBT[0].nodedata=root;
    cout<<"\nEnter '-' if there is no node."<<endl;
    for(int i=0;i<inodes;i++)
    {   
        if(CBT[i].nodedata!="-")
        {
            int lc,rc;
            lc=2*i+1;
            rc=2*i+2;
            cout<<"\n Enter the left child of "<<CBT[i].nodedata<<": ";
            cin>>CBT[lc].nodedata;

            cout<<"\nEnter the right child of "<<CBT[i].nodedata<<": ";
            cin>>CBT[rc].nodedata;
        }
    }
}

void display()
{   
    cout<<"\nThe Binary tree sequential array is: \n";
    cout<<"~Index"<<"\t\t"<<"~Node";
    for(int i=0;i<size;i++)
    {
        if(CBT[i].nodedata!="-")
        {
            cout<<"\n"<<i<<"\t\t"<<CBT[i].nodedata;
        }
    }
}

void parentnode()
{   
    string node1;
    int node1index;
    int pnindex;
    cout<<"\n Enter the node whose parent node you want to know: ";
    cin>>node1;
    node1index=0;
    for(int i=0;i<size;i++)
    {
        if(CBT[i].nodedata==node1)
        {
            break;
        }
        node1index++;
    }
    pnindex=(floor(node1index-1)/2);
    cout<<"\nThe parent node of: "<<node1<<" is: "<<CBT[pnindex].nodedata;
}

void leftchild()
{   
    string node1;
    int node1index;
    int pnindex;
    cout<<"\n Enter the node whose left child you want to know: ";
    cin>>node1;
    node1index=0;
    for(int i=0;i<size;i++)
    {
        if(CBT[i].nodedata==node1)
        {
            break;
        }
        node1index++;
    }
    pnindex=2*node1index+1;
    cout<<"\nThe left child of: "<<node1<<" is: "<<CBT[pnindex].nodedata;
}

int main()
{   
    char ans;
    do{
    int ch;
    cout<<"\n--------------------------------------------------------------------------------";
    cout<<"\nEnter your choice:"<<"\n1.Create"<<"\n2.Display tree"<<"\n3.Find Parent node"
        <<"\n4.Find Left child";
    cin>>ch;
    switch(ch)
    {
    case 1:
        int h,t;
        cout<<"\n Enter the height of tree: ";
        cin>>h;
        t=pow(2,h)-1;
        create(t);
        break;
    
    case 2:
        display();
        break;

    case 3:
        parentnode();
        break;

    case 4:
        leftchild();
        break;

    
    default:
        cout<<"Invalid choice!";
    }
    }while(ans='y');
}