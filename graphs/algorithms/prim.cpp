//Prim's Algorithm


#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<pair<int,int>>> vecpair;
typedef pair<int,int> ipair;
typedef vector<vector<int>> vvi;


void prim(vecpair &adj, int V)
{
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;

    int src=0;

    vector<int> key(V, INT_MAX);
    vector<int> parent(V,-1);

    vector<bool> inMST(V, false);

    pq.push({0,src});
    key[src]=0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for(auto x:adj[u])
        {
            int v=x.first;
            int weight = x.second;

            if(!inMST[v] && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v],v});
                parent[v]=u;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        cout<<parent[i]<<" - "<<i<<endl;
}


int main()
{
    vvi edges = {{0,1},{0,7},{1,2},{1,7},{2,3},{2,8},{2,5},{3,4},{3,5},{4,5},{5,6},{6,7},{6,8},{7,8}};
    vector<int> wt = {4,8,8,11,7,2,4,9,14,10,2,1,6,7};
    int V=9;

    vecpair adj(V);

    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back({edges[i][1],wt[i]});
    }

    prim(adj,V);
}

