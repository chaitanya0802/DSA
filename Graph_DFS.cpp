#include<iostream>
#define size 20
using namespace std;

class gdfs
{
    private:
    int visited[size];
    int graphmatrix[size][size],v1,v2;
    int stack[size];
    int top=-1;

    public:
    int edges;
    int nodes;

    gdfs()
    {
        for(int k=0;k<size;k++)
        {
            for(int l=0;l<size;l++)
            {
                graphmatrix[k][l]=0;
            }
        }
        for(int m=0;m<size;m++)
        {
            visited[m]=0;
        }
    }

    ~gdfs()
    {
        for(int k=0;k<size;k++)
        {
            for(int l=0;l<size;l++)
            {
                graphmatrix[k][l]=0;
            }
        }
        for(int m=0;m<size;m++)
        {
            visited[m]=0;
        }
    }


    void creategraph()
    {
        int undirected=1;;
        char type;
        int nodes=0;
        cout<<"\nPress D for directed graph or U for undirected graph:";
        cin>>type;
        cout<<"\nHow many edges are there? \n";
        cin>>edges;
        cout<<"\n How many nodes are there?\n";
        cin>>nodes;
        if(type=='D')
        {
            undirected=0;
        }
        for(int i=0;i<edges;i++)
        {
            cout<<"\nEnter the Edges: "<<endl;
            cin>>v1>>v2;
            if(v1>size || v2>size)
            {
                cout<<"\nInvalid nodes";
            }
            else
            {
                graphmatrix[v1][v2]=1;
            }
            if(undirected)
            {
                graphmatrix[v2][v1]=1;
            }
            
        }
    }

    void display(int dnodes)
    {
        for(int i=0;i<dnodes;i++)
        {
            for(int j=0;j<dnodes;j++)
            {
                cout<<" "<<graphmatrix[i][j];
            }
            cout<<endl;
        }
    }


};

int main()
{
    gdfs obj;
    int ch;
    int dnodes;
    char ans;
    do
    {
    cout<<"\nEnter your choice: \n1.Create \n2.display \n3.DFS traversal \n";
    cin>>ch;
    switch(ch)
    {
        case 1:
        obj.creategraph();
        break;

        case 2:
        cout<<"\nHow many nodes are there: ";
        cin>>dnodes;
        obj.display(dnodes);
        break;

        default: 
        cout<<"Invalid choice.";
        break;
     
    }
    cout<<"\nDo you want to continue?";
    cin>>ans;
    }while(ans='Y');
}
