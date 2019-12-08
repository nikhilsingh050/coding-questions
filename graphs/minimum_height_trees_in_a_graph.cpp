//Find the vertices to be selected as root to form minimum height trees.
//There can be maximum 2 such vertices. (center of the graph)

//keep removing leaves level by level to reach the remaining (two or one) vertices.
//BFS


#include<bits/stdc++.h>
using namespace std;

void mht(vector<vector<int>> &adj, int n)
{
    //compute in-degree of vertices
    vector<int> indegree(n);
    for(int u=0;u<n;u++)
    {
        for(int v: adj[u])
            indegree[v]++;
    }

    //in-degree 1 -> leaf vertex
    //add all leaves to the queue
    queue<int> q;
    for(int v=0;v<n;v++)
    {
        if(indegree[v]==1)
            q.push(v);
    }

    vector<int> root;

    while(!q.empty())
    {
        int size=q.size();
        //remove leaves level by level
        //newly added leaves will be removed in next turn (for star test case)
        for(int i=0;i<size;i++)
        {
            int u=q.front();
            q.pop();
            indegree[u]--;

            //when two or one vertex are remaining -> add to the result
            if(n<=2)
            {
                root.push_back(u);
                continue;
            }

            for(int v: adj[u])
            {
                indegree[v]--;
                if(indegree[v]==1)
                    q.push(v);
            }
        }
        n=n-size;   //update remaining vertices after removing current level of leaf nodes
    }

    for(int v : root)
        cout<<v<<endl;
}

int main()
{
    vector<vector<int>> graph={{0,3},{1,3},{2,3},{4,3}};
    int n=5;
    vector<vector<int>> adj(n);

    //undirected graph from edges
    for(vector<int> e : graph)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    mht(adj,n);
}
