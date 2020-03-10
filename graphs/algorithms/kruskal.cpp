//Kruskal Algorithm


#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

//weighted edges
struct Wedges
{
    int src,des,weight;

    Wedges(int src, int des, int weight)
    {
        this->src=src;
        this->des=des;
        this->weight=weight;
    }

    bool operator<(const Wedges &wedge)
    const{
        return this->weight < wedge.weight;
    }
};

//Disjoint sets with rank
struct DisjointSets
{
    int *parent,*rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        for(int i=0; i<=n;i++)
        {
            rnk[i]=0;
            parent[i]=i;
        }
    }

    int find(int u)
    {
        if(u!=parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    //union by rank
    void merge(int x, int y)
    {
        x=find(x);
        y=find(y);

        if(rnk[x] > rnk[y])
            parent[y]=x;
        else
            parent[x]=y;

        if(rnk[x] == rnk[y])
        {
            parent[y]=x;
            rnk[x]++;
        }
    }
};


int kruskal(vector<Wedges> &edges, int V)
{
    int mst_wt=0;

    sort(edges.begin(),edges.end());

    DisjointSets ds(V);

    for(auto e : edges)
    {
        int u = e.src;
        int v = e.des;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        //if they belong to the same set then there is a cycle
        //else add edge to the tree
        if(set_u != set_v)
        {
            cout<<u<<" - "<<v<<endl;
            mst_wt+=e.weight;
            ds.merge(set_u,set_v);
        }
    }
    return mst_wt;
}


int main()
{
    vvi edges = {{0,1},{0,7},{1,2},{1,7},{2,3},{2,8},{2,5},{3,4},{3,5},{4,5},{5,6},{6,7},{6,8},{7,8}};
    vector<int> wt = {4,8,8,11,7,2,4,9,14,10,2,1,6,7};
    int V=9;

    vector<Wedges> wedges;
    for(int i=0;i<edges.size();i++)
    {
        Wedges w(edges[i][0],edges[i][1],wt[i]);
        wedges.push_back(w);
    }

    cout<<"Weight of MST: "<<kruskal(wedges,V);
}
