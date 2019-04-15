/* ******************PROBLEM STATEMENT*********************
There are flight paths between cities. If there is a flight between city A and city B then there
is an edge between the cities. The cost of the edge can be the time that flight take to reach
city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph. Justify the
storage representation used.*/

#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;
};

class graph
{
    int i;
    int n;
    node*head[10];
public:
    graph(int num)
    {
        n=num;
        for(i=0;i<10;i++)
            head[i]=NULL;
    }
    void make(int,int);
    void display();

};

void graph::make(int src,int des)
{
    node*start, *st;
    node *nsc, *nds;
    nsc=new node;
    nsc->data=src;
    nsc->next=NULL;

    nds=new node;
    nds->data=des;
    nds->next=NULL;

    if(head[src]==NULL)
    {
        head[src]=nds;

    }
    else
    {
        start=head[src];
        while(start->next!=NULL)
        {
            start=start->next;
        }
        start->next=nds;
    }

    if(head[des]==NULL)
    {
        head[des]=nsc;

    }
    else
    {
        st=head[des];
        while(st->next!=NULL)
        {
            st=st->next;
        }
        st->next=nsc;
    }

}


void graph::display()
{
    node*temp;
    for(i=0;i<n;i++)
    {
        temp=head[i];
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
}


int main()
{
    int v,src,des;
    int j,x,c;
    char ch;
    cout<<"\n********MENU**************\n";
    cout<<"\n1.Graph by adjacency list\n2.Graph by adjacency matrix";
    cout<<"\nEnter choice (1 or 2): ";
    cin>>c;
    if(c==1)
    {
    cout<<"\nEnter number of vertex: ";
    cin>>v;
    graph g(v);
    do
    {
    cout<<"\nMENU ";
    cout<<"\n1.Add edge\n2.Display";
    cin>>x;
    switch(x)
    {
    case 1:
    cout<<"\nEnter source and destination vertex: ";
    cin>>src>>des;
    if(src>=v || des>=v)
    {
        cout<<"\nInvalid entry";
    }
    g.make(src,des);
    break;

    case 2:
    g.display();
    break;

    default:
        cout<<"\nDon't want to add edge";
    }
    cout<<"\nDo you want to continue?";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    }

    else if(c==2)
    {
        int arr[50][50]={0};
    cout<<"\n Enter number of vertex: ";
    cin>>v;

    cout<<"\nIf there is edge between two vertex enter 1 otherwise 0 ";
    int t,i,j;
    for (i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i!=j)
            {
            cout<<"\n"<<i<<" and "<<j<<" : ";
            cin>>t;
            arr[i][j]=t;
            }
        }
    }
    cout<<"\n Adjacency Matrix: \n";
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    }
    return 0;
}


