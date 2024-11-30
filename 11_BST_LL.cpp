/*Binary search tree using linked list to insert node, display tree, search node*/
#include<iostream>
#include<string.h>
using namespace std;

class BST
{   
    public:
    struct node 
    {
        int nodedata;
        node *left,*right;
    }*root;

    BST()
    {
        root=NULL;
    }

    void nodecreator()
    {
        node *New;
        char ans='y';
        do
        {
            New=new node;
            cout<<"\nEnter the data(int) of node: ";
            cin>>New->nodedata;
            New->left=NULL;
            New->right=NULL;

            if(root==NULL)
            {
                root=New;
            }
            else
            {
                nodeinserter(root,New);
            }
            cout<<"\nDo you want to enter more nodes?(y/n)";
            cin>>ans;
        }while((ans=='y') || (ans=='Y'));
    }

    void nodeinserter(node *root,node *New)
    {
        if((New->nodedata>root->nodedata) && (root->right==NULL))
        {
            root->right=New;
        }
        if((New->nodedata>root->nodedata) && ((root->right!=NULL)) )
        {
            nodeinserter(root->right,New);
        }

        if((New->nodedata<root->nodedata) && (root->left==NULL))
        {
            root->left=New;
        }
        if((New->nodedata<root->nodedata) && ((root->left!=NULL)) )
        {
            nodeinserter(root->left,New);
        }  
    }

    void displayer()
    {
        if(root!=NULL)
        {
            cout<<"\nThe value of root is: "<<root->nodedata;
        }
        if((root->left==NULL) && (root->right==NULL))
        {
            cout<<"\nonly root node is present.";
        }
        else
        {
            nodedisplayer(root);
        }
    }

    void nodedisplayer(node *root)
    {
        if(root->left!=NULL)
        {
        cout<<"\nLeft child of: "<<root->nodedata<<" is: "<<root->left->nodedata;
        nodedisplayer(root->left);
        }
        if(root->right!=NULL)
        {
        cout<<"\nRight child of: "<<root->nodedata<<" is "<<root->right->nodedata;
        nodedisplayer(root->right);
        }
    }

    void searcher()
    {   
        int val;
        cout<<"\nenter the data(int) to search: ";
        cin>>val;
        if(val==root->nodedata)
        {
            cout<<"\nThe node you are searching is Root node.";
        }
        else
        {
            nodesearcher(val,root);
        }
    }

    void nodesearcher(int val,node *root)
    {
        if(val > root->nodedata)
        {
            nodesearcher(val,root->right);
        }
        if(val < root->nodedata)
        {
            nodesearcher(val,root->left);
        }
        if(val==root->nodedata)
        {
            cout<<"\nNode found successfully.";
        }

    }


};
int main()
{   
    BST obj;
    int ch;
    do
    {   
        cout<<endl;
        cout<<"\n Enter your choice: \n1.insert node \n2.display binary tree \n3.Search node"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.nodecreator();
            break;

        case 2:
            obj.displayer();
            break;
        
        case 3:
            obj.searcher();
            break;
        
        default:
        cout<<"\nInvalid choice!";
        break;
        }
    }while(1);
}