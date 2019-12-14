//Problem: https://leetcode.com/problems/evaluate-division/


//It uses dfs to search the weighted graph.
//Alternate solution: Using Union find.(faster) 

// How to optimize?
// - There are a number of queries.
// - The calculated query results can be stored. (Mmemoization)
// - This can be done by building new edges in the graph.



#include<bits/stdc++.h>
using namespace std;

//weighted graph node
struct Node
{
    string name;
    double value;
    Node(string name, double value)
    {
        this->value=value;
        this->name=name;
    }
};


//build the graph from input
unordered_map<string, vector<Node>> graph;
void createGraph(vector<vector<string>>& equations, vector<double>& values)
{
    for(auto e : equations)
    {
        vector<Node> children;
        graph[e[0]]=children;
    }

    for(int i=0; i<equations.size();i++)
    {
        Node node(equations[i][1],values[i]);
        graph[equations[i][0]].push_back(node);

        Node rev_node(equations[i][0],1/values[i]);
        graph[equations[i][1]].push_back(rev_node);
    }
}

//dfs to reach the final node
bool evaluate(string u, string v, unordered_set<string> &visited, double &result)
{
    if( u == v && graph.find(u)!=graph.end())
        return true;

    if(graph.find(u)==graph.end() || graph.find(v)==graph.end())
        return false;

    visited.insert(u);

    for(Node child : graph[u] )
    {
        if(visited.find(child.name)==visited.end())
        {
            result*=child.value;
            if(child.name==v)
                return true;

            if(evaluate(child.name,v,visited, result))
                return true;

            else        //backtrack
            {
                result/=child.value;
            }
        }
    }
    return false;
}


vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

    createGraph(equations, values);
    vector<double> results;

    for(auto q : queries)
    {
        unordered_set<string> visited;
        double result = 1.0;
        bool res = evaluate(q[0],q[1],visited,result);

        if(res)
            results.push_back(result);
        else
            results.push_back(-1.0);
    }
    return results;
}


int main()
{
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    vector<double> res = calcEquation(equations, values, queries);

    cout<<"Queries result: \n[";
    for(double r: res)
        cout<<r<<", ";
    cout<<"]";
}
