#include<iostream>
#include<algorithm>>
#define size 20
using namespace std;

class gdfs
{
    private:
    int visited[size];
    int minmatrix[size][size];
    int graphmatrix[size][size],v1,v2,weight;;

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
        int nodes;
        cout<<"\nHow many edges are there? \n";
        cin>>edges;
        cout<<"\n How many nodes are there?\n";
        cin>>nodes;

        for(int i=1;i<=edges;i++)
        {
            cout<<"\nEnter the Edges: "<<endl;
            cin>>v1>>v2;
            cout<<"\nEnter its weight/cost: ";
            cin>>weight;
            cout<<"\n------------------------------------------\n";
            if(v1>nodes || v2>nodes)
            {
                cout<<"\nInvalid nodes";
            }
            else
            {
                graphmatrix[v1][v2]=weight;
                graphmatrix[v2][v1]=weight;
            }
            
        }
    }

    void display(int dnodes)
    {
        for(int i=1;i<=dnodes;i++)
        {
            for(int j=1;j<=dnodes;j++)
            {
                cout<<" "<<graphmatrix[i][j];
            }
            cout<<endl;
        }
    }

    void mst()
    {   
        cout<<"Minimum weight is: "<<*min_element(graphmatrix,graphmatrix+nodes);
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
    cout<<"\nEnter your choice: \n1.Create \n2.display \n3.Find minimum spanning tree(prims algorithm)\n";
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

        case 3:
        cout<<"\nFinding minimum spanning tree adjecency matrix: ";
        obj.mst();
        break;

        default: 
        cout<<"Invalid choice.";
        break;
     
    }
    cout<<"\nDo you want to continue?";
    cin>>ans;
    }while(ans='Y');
}
