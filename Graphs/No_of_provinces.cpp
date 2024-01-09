/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1

Your Task:
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)


*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution
{
private:
    // dfs traversal function
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        // mark the more as visited
        vis[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int>* adjLs = new vector<int>[V];
        // to change adjacency matrix to list
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // self nodes are not considered
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
       int *vis = new int[V]();
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            // if the node is not visited
            if (!vis[i])
            {
                // counter to count the number of provinces
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

int main()
{

    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    Solution ob;
    cout << ob.numProvinces(adj, 3) << endl;

    return 0;
}