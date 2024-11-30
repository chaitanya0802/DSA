#include<iostream>
#define size 20
using namespace std;

class GBFS
{
    private:
    int g[size][size],v1,v2;
    int visited[size];
    int q[size];
    int front,rear;

    public:
    int nodes;
    GBFS()
    {
        for(v1=0;v1<size;v1++)
        {
            for(v2=0;v2<size;v2++)
            {
                g[v1][v2]=0;
            }
        }
        for(v1=0;v1<size;v1++)
        {
            visited[v1]=0;
        }
    }

    ~GBFS()
    {
        for(v1=0;v1<size;v1++)
        {
            for(v2=0;v2<size;v2++)
            {
                g[v1][v2]=0;
            }
        }
        for(v1=0;v1<size;v1++)
        {
            visited[v1]=0;
        }

    }

    void create()
    {
        int flag,nodes;
        char ch;
        flag=1;
        cout<<"\nEnter D for directed graph or U for undirected graph: ";
        cin>>ch;
        
        if(ch=='D')
        {
            flag=0;
        }

        cout<<"\nHow many nodes are there in graph: \n";
        cin>>nodes;
        for(int i=0;i<nodes;i++)
        {
            cout<<"\nEnter the edges of graph: ";
            cin>>v1>>v2;
            if(v1==99)
            {
                break;
            }
            if(v1>=size || v2>=size)
            {
                cout<<"\n Invalid vertex.";
            }
            else
            {
                g[v1][v2]=1;
            }
            if(flag)
            {
                g[v2][v1]=1;
            }
        }
    }

    void display()
    {
        cout<<"\nThe Graph is:\n";
        for(v1=0;v1<nodes;v1++)
        {
            for(v2=0;v2<nodes;v2++)
            {
                cout<<" "<<g[v1][v2];
                cout<<endl;
            }
        }
    }

    void gbfs(int v1)
    {
        int v2;
        visited[v1]=1;
        front=rear=-1;
        q[++rear]=v1;
        while(front!=rear)
        {
            v1=q[++front];
            cout<<"\n"<<v1;
            for(v2=0;v2<nodes;v2++)
            {
                if(g[v1][v2]==1 || visited[v2]==0)
                {
                    q[++rear]=v2;
                    visited[v2]=1;
                }
            }
        }

    }


};
int main()
{
    GBFS  obj;
    int ch,v1;
    do
    {
    cout<<"\n Enter your choice: \n1.Create \n2.Display matrix \n3.Display BFS"<<endl;
    cin>>ch;
    switch (ch)
    {
    case 1:
        obj.create();
        break;
    
    case 2:
        obj.display();
    
    case 3:
        cout<<"\n Enter the vertex from which you want to traverse: ";
        cin>>v1;
        obj.gbfs(v1);
    
    default:
        break;
    }
    }while(1);
}