#include<bits/stdc++.h>
using namespace std;

void kahn(vector<vector<int>> &adj,int n)
{
    vector<int> indegree(n,0);

    //1. find indegree of all the vertices
    for(int u=0; u<n;u++)
    {
        for(int v: adj[u])
            indegree[v]++;
    }

    //2. add all the vertices with indegree 0 in a queue
    queue<int> q;
    for(int v=0;v<n;v++)
    {
        if(indegree[v]==0)
            q.push(v);
    }

    int visitcount=0;
    vector<int> toporder;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        toporder.push_back(u);
        visitcount++;

        for(int v : adj[u])
        {
            --indegree[v];
            if(indegree[v]==0)
                q.push(v);
        }
    }

    if(visitcount!=n)
        cout<<"The graph contains a cycle! \nTopological order not possible!"<<endl;
    else
    {
        cout<<"The graph is Acyclic."<<endl;
        cout<<"Topological order: "<<endl;

        for(int i=0; i<n;i++)
            cout<<toporder[i]<<" ";
    }
}

int main()
{
    vector<vector<int>> graph={{0,1},{1,2},{2,0},{3,4},{4,5}};
    int n=6;
    vector<vector<int>> adj(n);

    //directed graph from edges
    for(vector<int> e : graph)
        adj[e[0]].push_back(e[1]);

    kahn(adj,n);
}
