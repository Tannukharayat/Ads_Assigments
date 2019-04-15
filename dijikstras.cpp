/****************PROBLEM STATEMENT**********************
Tour operator organizes guided bus trips across the Maharashtra. Tourists may have 
different preferences. Tour operator offers a choice from many different routes. Every
day the bus moves from starting city S to another city F as chosen by client. On this
way, the tourists can see the sights alongside the route travelled from S to F. 
Client may have preference to choose route. There is a restriction on the routes 
that the tourists may choose from, the bus has to take a short route from S to F or 
a route having one distance unit longer than the minimal distance. Two routes from 
S to F are considered different if there is at least one road from a city A to a 
city B which is part of one route, but not of the other route.*/
#include <bits/stdc++.h>
using namespace std;

int V;
int graph[1000][1000];

int minDistance(int dist[], bool visited[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (visited[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int printSolution(int dist[], int n, int src)
{
	cout<<"\nVertex distance from \n";
     for (int i = 0; i < V; i++)
     cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
}

void dijkstra( int src)
{
     int dist[V];
     bool visited[V];
     for (int i = 0; i < V; i++)
     dist[i] = INT_MAX, visited[i] = false;
     dist[src] = 0;
     for (int cnt = 0; cnt < V-1; cnt++)
     {
       int u = minDistance(dist, visited);
       visited[u] = true;
       for (int v = 0; v < V; v++)

          if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     printSolution(dist, V,src);
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
   dijkstra(0);

    return 0;
}

