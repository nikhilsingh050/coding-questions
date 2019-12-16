//Finding cycles in undirected graph:
//Given the edges.




////////////////////////////////////////////////////////////////////////////////////////////////////

//1. Using DFS:

//We do a DFS traversal of the given graph. For every visited vertex ‘v’,
//if there is an adjacent ‘u’ such that u is already visited and u is not parent of v,
//then there is a cycle in graph.

//Time Complexity: O(V+E)


#include<bits/stdc++.h>
using namespace std;


bool dfs(string v, unordered_map<string,vector<string>> &adj, unordered_set<string> &visited, string u)
{
    visited.insert(v);

    for(auto neighbor : adj[v])
    {
        if(visited.find(neighbor)==visited.end())
        {
            if(dfs(neighbor,adj,visited,v))
                return true;
        }
        else if(neighbor!=u)
            return true;
    }
    return false;
}


int main()
{
    vector<vector<string>> edges = {{"A","B"},{"B","C"},{"C","D"},{"D","E"},{"E","F"},{"F","C"}};
    int n=6;
    unordered_map<string,vector<string>> adj;

    for(auto e : edges)
    {
        if(adj.find(e[0])==adj.end())
        {
            vector<string> v;
            adj[e[0]]=v;
        }
        if(adj.find(e[1])==adj.end())
        {
            vector<string> v;
            adj[e[1]]=v;
        }

        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    unordered_set<string> visited;

    string u = adj.begin()->first;

    if(dfs(u,adj,visited,"$"))
        cout<<"Cyclic!"<<endl;
    else
        cout<<"Acyclic!"<<endl;

    return 0;
}





///////////////////////////////////////////////////////////////////////////////////////////

//2. Using Disjoint-Set or Union-find:

// Algorithm:
// 1. Create a set for each vertex.
// 2. For each edge, if the two vertices have different sets, union them into a single set.
// 3. If for any edge, the two vertices belong to the same set, the graph is cyclic.

//Time complexity: O(ElogV)
//Space complexity: O(V)

//Possible Optimization: Union by rank or height: O(logn).


#include<bits/stdc++.h>
using namespace std;


//Find the parent set of the vertex:
string find(unordered_map<string,string> &parent, string s)
{
    if(parent[s]=="$")
        return s;
    else
        return find(parent, parent[s]);
}

//Union of the two sets. Union the two vertices into a single set.
void Union(unordered_map<string,string> &parent, string x, string y)
{
    string xset = find(parent, x);
    string yset = find(parent, y);
    parent[xset] = yset;
}

bool isCyclic(vector<vector<string>> &edges, int n)
{
    //map to store parent set of each vertex.
    unordered_map<string,string> parent;

    for(auto e : edges)
    {
        // "$" means the parent set of the vertex is the vertex itself.
        //initialize the vertex if it isn't initialized.

        if(parent.find(e[0])==parent.end())
            parent[e[0]]="$";
        if(parent.find(e[1])==parent.end())
            parent[e[1]]="$";

        //find parent set of the vertices
        string xset = find(parent, e[0]);
        string yset = find(parent, e[1]);

        if(xset==yset)
            return true;
        else
            Union(parent,xset,yset);
    }
    return false;
}

int main()
{
    vector<vector<string>> edges = {{"A","B"},{"B","C"},{"C","D"},{"D","E"},{"E","F"},{"F","C"}};
    int n=6;
    if(isCyclic(edges,6))
        cout<<"Cyclic";
    else
        cout<<"Acyclic";
}
