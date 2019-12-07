//Problem: There are a total of n courses you have to take, labeled from 0 to n-1.
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

/*IDEA: The basic idea is to check for cycles in the given directed graph.
        If the graph is cyclic the courses can not be completed.
*/



///////////////////////////////////////////////////////////////////////////////////////////////////

//1. Using DFS:

class Solution {
public:
    //if a visited node is encountered again, then there is a cycle.
    bool isCyclic(int u, vector<int> &visited, vector<vector<int>> &graph)
    {
        if(!visited[u])
        {
            visited[u]=true;
            for(int v: graph[u])
            {
                if(!visited[v] && isCyclic(v,visited,graph))
                    return true;
                else if(visited[v])
                    return true;
            }
            visited[u]=false;
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre)
    {
        vector<vector<int>> graph(numCourses);
        for(vector<int> edge: pre)
            graph[edge[0]].push_back(edge[1]);

        vector<int> visited(numCourses,false);

        //check for cycles in all the possible trees starting from all the vertices
        for(int i=0;i<numCourses;i++)
        {
            if(isCyclic(i,visited,graph))
                return false;
        }
        return true;
    }
};


///////////////////////////////////////////////////////////////////////////////////////////

//2. Using BFS(Kahn's Algorithm):

class Solution {
public:    
    bool isCyclic(int n, vector<vector<int>> &graph)
    {
        vector<int> indegree(n,0);       
        for(int u=0;u<n;u++)
        {
            for(int v: graph[u])
                indegree[v]++;
        }
        
        queue<int> q;        
        for(int v=0;v<n;v++)
        {
            if(indegree[v]==0)
                q.push(v);
        }
        
        int visitcount=0;
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            visitcount++;
            
            for(int v: graph[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        
        if(visitcount!=n)
            return true;
        else
            return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        vector<vector<int>> graph(numCourses);
        for(vector<int> edge: pre)
            graph[edge[0]].push_back(edge[1]);
        
        if(isCyclic(numCourses,graph))
            return false;
        else
            return true;
    }
};


///////////////////////////////////////////////////////////////////////////////////////////

//3. Using colors:
