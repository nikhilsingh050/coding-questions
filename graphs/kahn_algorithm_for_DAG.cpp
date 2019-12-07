/*
Steps involved in finding the topological ordering of a DAG:

Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in
the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.
-Increment count of visited nodes by 1.
-Decrease in-degree by 1 for all its neighboring nodes.
-If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.

Step 4: Repeat Step 3 until the queue is empty.

Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the
topological sort is not possible for the given graph.
*/

//Topological order for a cyclic graph is not possible.


#include<bits/stdc++.h>
using namespace std;

void kahn(vector<vector<int>> &adj,int n)
{
    vector<int> indegree(n,0);

    //1. Compute in-degree for each  vertex
    for(int u=0; u<n;u++)
    {
        for(int v: adj[u])
            indegree[v]++;
    }

    //2. Enqueue vertex with in-degree zero.
    queue<int> q;
    for(int v=0;v<n;v++)
    {
        if(indegree[v]==0)
            q.push(v);
    }

    int visitcount=0;
    vector<int> toporder;

    //3. BFS
    while(!q.empty())
    {
        //dequeue
        int u = q.front();
        q.pop();
        toporder.push_back(u);
        visitcount++;

        //Decrease in-degree by 1 for all its neighboring nodes
        for(int v : adj[u])
        {
            --indegree[v];
            //If in-degree of a neighboring nodes is reduced to zero, then add it to the queue
            if(indegree[v]==0)
                q.push(v);
        }
    }

    //If count of visited nodes is not equal to the number of nodes in the graph
    //then the topological sort is not possible for the given graph.
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
