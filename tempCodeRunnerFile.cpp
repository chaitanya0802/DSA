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