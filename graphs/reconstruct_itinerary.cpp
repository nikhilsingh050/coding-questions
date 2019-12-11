//Problem: https://leetcode.com/problems/reconstruct-itinerary/

#include<bits/stdc++.h>
using namespace std;

bool found=false;

void dfs(string s,unordered_map<string,vector<string>> &adj, vector<string> &result,int n)
{
    //when all the airports are visited
    if(result.size()==n+1)
    {
        found=true;
        return;
    }

    sort(adj[s].begin(),adj[s].end());

    for(string des : adj[s])
    {
        //add the destination to the result and remove it from the graph
        result.push_back(des);
        auto i = find(adj[s].begin(),adj[s].end(),des);
        adj[s].erase(i);
        dfs(des,adj,result,n);
        if(found)
            return;
        //backtrack
        //add the destination back to the graph and remove it from result
        adj[s].insert(adj[s].begin(),des);
        result.pop_back();
    }
}

vector<string> findItinerary(vector<vector<string>>& tickets) {

    unordered_map<string,vector<string>> adj;

    //create adjacency list
    for(vector<string> e: tickets)
    {
        if(adj.find(e[0])==adj.end())
        {
            vector<string> v;
            v.push_back(e[1]);
            adj[e[0]] = v;
        }
        else
            adj[e[0]].push_back(e[1]);
    }

    vector<string> result;
    result.push_back("JFK");
    int n=tickets.size();
    dfs("JFK",adj,result,n);

    return result;
}

int main()
{
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};

    vector<string> res = findItinerary(tickets);

    cout<<"Reconstructed Itinerary: "<<endl;
    for(string s: res)
        cout<<s<<" -> ";
}
