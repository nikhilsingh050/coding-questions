//Single Source Shortest Path
//Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs.
//Complexity(with priority queue): O(VE)


#include <bits/stdc++.h>
using namespace std;

void bellman(vector<vector<int>> &edges, vector<int> &wt, int src , int V)
{
    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;


    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = wt[j];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }


    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = wt[i];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout<<"Graph contains negative weight cycle";
            return;
        }
    }

    cout<<"Vertex Distance from Source:\n";
    for (int i = 0; i < V; ++i)
        cout<<i<<"\t"<<dist[i]<<endl;
}


int main()
{
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{1,3},{1,4},{3,2},{3,1},{4,3}};
    vector<int> wt = {-1,4,3,2,2,5,1,-3};
    int V=5;

    bellman(edges,wt, 0, V);
}
