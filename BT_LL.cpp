/*Binary tree using Linked list to insert nodes, 
    display nodes,get inorder,postorder,preorder of binary tree.*/
#include<iostream>
#include<string.h>
using namespace std;

class binarytree
{   
    public:
    struct node
    {
        string data;;
        node *left,*right;
    }*root;
    binarytree()
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
            cout<<"\n Enter the data of node: ";
            cin>>New->data;
            New->left=NULL;
            New->right=NULL;
            if(root==NULL)
            {
                root=New;   //entering root
            }
            else
            {
                nodeinserter(root,New);       //entering child node
            }
            cout<<"\nDo yo want to enter more nodes? ";
            cin>>ans;
        
        }while((ans=='y') || (ans=='Y'));
    }

    void nodeinserter(node *root,node *New)
    {
        char ch;
        cout<<"\nWhere to insert left(l) or right(r) of: "<<root->data<<"- ";
        cin>>ch;;
        if((ch=='r') || (ch=='R'))
        {
            if(root->right==NULL)
            {
                root->right=New;
            }
            else
            {
                nodeinserter(root->right,New);
            }
        }
        else
        {
            if(root->left==NULL)
            {
                root->left=New;
            }
            else
            {
                nodeinserter(root->left,New);
            }
        }
    }

    void display()
    {   
        if(root!=NULL)
        {
            cout<<"\nValue of root is: "<<root->data;
        }
        if((root->left==NULL) && (root->right=NULL))
        {
            cout<<"\nThere is only root node present in binary tree.";
        }
        else
        {
            nodedisplay(root);
        }
    }
    void nodedisplay(node *root)
    {
        if(root->left!=NULL)
        {
        cout<<"\nLeft child of: "<<root->data<<" is: "<<root->left->data;
        nodedisplay(root->left);
        }
        if(root->right!=NULL)
        {
        cout<<"\nRight child of: "<<root->data<<" is "<<root->right->data;
        nodedisplay(root->right);
        }
    }

    void inorder()
    {   
        cout<<"\ninorder of the binary tree is: ";
        getinorder(root);
    }
    void getinorder(node *root)
    {
        if(root!=NULL)
        {
            getinorder(root->left);
            cout<<root->data;
            cout<<" , ";
            getinorder(root->right);
        }
    }

    void preorder()
    {   
        cout<<"\npreorder of the binary tree is: ";
        getpreorder(root);
    }
    void getpreorder(node *root)
    {
        if(root!=NULL)
        {
            cout<<root->data;
            cout<<" , ";
            getpreorder(root->left);
            getpreorder(root->right);
        }
    }

    void postorder()
    {   
        cout<<"\npostorder of the binary tree is: ";
        getpostorder(root);
    }
    void getpostorder(node *root)
    {
        if(root!=NULL)
        {   
            getpostorder(root->left);
            getpostorder(root->right);
            cout<<root->data;
            cout<<" , ";
        }
    }
        

};

int main()
{   
    binarytree obj;
    int ch;
    do
    {   cout<<endl;
        cout<<"\n Enter your choice: \n1.insert node \n2.display binary tree \n3.Display inorder \n4.Display preorder \n5.Display postorder"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.nodecreator();
            break;

        case 2:
        obj.display();
            break;
        
        case 3:
        obj.inorder();
        break;

        case 4:
        obj.preorder();
        break;

        case 5:
        obj.postorder();
        break;
        
        default:
        cout<<"\nInvalid choice!";
            break;
        }
    }while(1);
}