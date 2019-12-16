//Using Disjoint-Set or Union-find:

// Algorithm:
// 1. Create a set for each vertex.
// 2. For each edge, if the two vertices have different sets, union them into a single set.
// 3. If for any edge, the two vertices belong to the same set, the graph is cyclic.


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

