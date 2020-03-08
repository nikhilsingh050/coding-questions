//ALL PAIR SHORTEST PATH
//need to convert adjacency list to adjacency matrix

//Complexity: O(V^3)


#include <bits/stdc++.h>
using namespace std;

#define INF 9999999
typedef vector<vector<int>> vvi;


void printSolution(vvi dist, int V)
{
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"     ";
            else
                cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
}

void floydWarshall(vvi &graph, int V)
{
    vvi dist = graph;

    for (int k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);
}


int main()
{
    vvi graph = { {0, 5, INF, 10},
                {INF, 0, 3, INF},
                {INF, INF, 0, 1},
                {INF, INF, INF, 0}
                };
    int V=4;

    floydWarshall(graph, V);
}
