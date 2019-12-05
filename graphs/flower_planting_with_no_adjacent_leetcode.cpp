//Problem: There are N gardens and 4 plants.
//Plant these plants in the N gardens such that no two adjacent gardens have the same plant.

/* Idea: Since there are only 3 paths connecting a garden there will definitely be a solution
*        So we pick a garden(G) and pick a type of flower(f), then we check all the adjacent garden(n)
*        to see if "f" is already planted if so then we can pick a different "f" and check again
*/

class Solution {
public:
    void plant(int g, vector<int> adj, vector<int> &result)
    {
        //check if the flower is present in the adjacent gardens
        //if not plant it in current garden
        for(int f=1;f<=4;f++)
        {
            bool found=false;
            for(int n: adj)
            {
                if(result[n]!=-1 && result[n]==f)
                    found=true;
            }
            if(found==false)
            {
                result[g]=f;
                return;
            }
        }
    }

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N);

        //create adjacency list
        for(vector<int> edge: paths)
        {
            graph[edge[0]-1].push_back(edge[1]-1);
            graph[edge[1]-1].push_back(edge[0]-1);
        }

        vector<int> result(N,-1);

        //put plants in gardens one by one
        for(int garden=0;garden<N;garden++)
            plant(garden,graph[garden],result);

        return result;
    }
};
