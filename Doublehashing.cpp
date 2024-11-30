/*Program in C++ to create hashtable of size 10 and function to insert, display,
 delete record by double hashing collision technique*/
#include <iostream>
#include <string.h>
using namespace std;
#define size 10
#define n 5

class hash_table
{
    public:
    int key = -1;
    string record = "--";
} hash_table[size];

void insert()
{   int val;
    cout<<"How many values do you want to enter: ";
    cin>>val;
    for(int i=0;i<val;i++)
    {
    int keyval, pos;
    string recordval;
    cout << "Enter the key \n";
    cin >> keyval;
    cout << "Enter the record \n";
    cin >> recordval;
    pos = keyval % size;
    if(hash_table[pos].key==-1)
    {
    hash_table[pos].key = keyval;
    hash_table[pos].record = recordval;
    }
    else
    {
    for(int i=0;i<n;i++)
    pos = ((keyval % size) + (i * (keyval % n))) % size;
    }
    }
}
void display()
{
    int i = 0;
    cout<<"Index"<<"\t\t"<<"key"<<"\t\t"<<"Value";
    while (i < size)
    {
        cout << "\n"<<i<< "\t\t"<< hash_table[i].key << "\t\t"<< hash_table[i].record;
        i++;
    }
}
void delete_element()
{
    int element;
    cout << "Enter Key\n";
    cin >> element;
    int i = 0;
    while (i != size)
    {
        if (hash_table[i].key == element)
        {
            hash_table[i].key = -1;
             hash_table[i].record = "--";
             cout << "Your data deleted sucessfully\n";
        }
        i++;
    }
}

int main()
{   cout << "This  is programe of hash table\n";
    int i = 0;
    int ch = 4;
    cout << " 1) Insert\n 2)display\n 3)delete \n 4)Exit\n";
    do
    {   
        cout << "\nEnter your choice :";
        ch = 4;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            delete_element();
            break;
        }
        case 4:
        {
            cout << "Exit\n";
            break;
        }
        default:
        {
            cout << "\nWrong Choice!!!\n";
        }
        }
    } while (ch != 4);
}