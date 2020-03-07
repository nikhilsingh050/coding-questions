//Single Source Shortest Path
//Complexity(with priority queue): O(V + ElogV)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int weight,value;

    Node(int value, int weight)
    {
        this->value=value;
        this->weight=weight;
    }

    bool operator>(const Node &node)
    const{
        return this->weight > node.weight;
    }
};

void dijkstra(unordered_map<int,vector<Node>> &adj, int src, int V)
{
    priority_queue<Node,vector<Node>,greater<Node>> pq;

    vector<int> dist(V, INT_MAX);

    vector<bool> visited(V,false);

    pq.push(Node(src,0));
    dist[src]=0;

    while(!pq.empty())
    {
        int u = pq.top().value;
        pq.pop();
        visited[u]=true;

        for(auto vv : adj[u])
        {
            int v = vv.value;
            int weight = vv.weight;

            if(dist[v] > dist[u] + weight && !visited[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(Node(v,dist[v]));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    vector<vector<int>> edges = {{0,1},{0,7},{1,2},{1,7},{2,3},{2,8},{2,5},{3,4},{3,5},{4,5},{5,6},{6,7},{6,8},{7,8}};
    vector<int> wt = {4,8,8,11,7,2,4,9,14,10,2,1,6,7};
    int V=9;

    unordered_map<int,vector<Node>> adj;

    for(int i=0;i<edges.size();i++)
    {
        if(adj.find(edges[i][0])==adj.end())
        {
            vector<Node> v;
            adj[edges[i][0]]=v;
        }
        if(adj.find(edges[i][1])==adj.end())
        {
            vector<Node> v;
            adj[edges[i][1]]=v;
        }
        Node node1(edges[i][1],wt[i]);
        Node node2(edges[i][0],wt[i]);
        adj[edges[i][0]].push_back(node1);
        adj[edges[i][1]].push_back(node2);
    }

    dijkstra(adj, 0, V);
}

