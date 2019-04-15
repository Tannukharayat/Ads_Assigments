/***********PROBLEM STATEMENT*******************
You have a business with several offices; you want to lease phone lines to connect them up
with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate data structures.*/
#include <iostream>
using namespace std;

int V;
int graph[1000][1000];

int minKey(int dist[], bool visited[])
{
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
    if (visited[v] == false && dist[v] < min)
        min = dist[v], min_index = v;

return min_index;
}


int printMST(int parent[], int n)
{
    int v;
     cout<<"Edge \tWeight\n";
     for (int i = 1; i < V; i++)
     {
       v=parent[i];
      cout<<v <<" "<< i <<"\t"<<graph[i][v]<<endl;
     }
}


void primMST()
{
    int parent[V];
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V-1; count++)
    {
        int u = minKey(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        if (graph[u][v] && visited[v] == false && graph[u][v] < dist[v])
            parent[v] = u, dist[v] = graph[u][v];
    }
    printMST(parent, V);
}




int main()
{
cout<<"\n Enter number of vertex: ";
cin>>V;

cout<<"\n Enter the Adjacency matrix: ";

   for(int i=0;i<V;i++)
   {
   		for(int j=0;j<V;j++)
   		{
   		cin>>graph[i][j];
  		 }
   }

    primMST();

    return 0;
}
