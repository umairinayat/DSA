#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> bellmon_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e9); // For distance vector

        dist[S] = 0; // Distance of source vertex from itself is always 0

        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] + wt < dist[v]) // If new distance is smaller than previous distance
                {
                    dist[v] = dist[u] + wt; // Updating distance of edgesacent node
                }
            }
        }

        // nth relaxation to check negative cycle

        for (auto it : edges) // Iterating over all the edgesacent nodes
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] + wt < dist[v]) // If new distance is smaller than previous distance
            {
                cout << "Negative Cycle Found";
                exit(0);
            }
        }

        return dist; // Returning the distance vector
    }
};
int main()
{
   // Test Case 1 

    Solution obj;   
    const int V1 = 6;
    vector<vector<int>> edges1 = {
        {0, 1, 5},
        {0, 2, 2},
        {0, 3, 3},
        {1, 0, 5},
        {1, 2, 1},
        {1, 3, 7},
        {2, 0, 2},
        {2, 1, 1},
        {2, 3, 3},
        {2, 4, 2},
        {3, 0, 3},
        {3, 1, 7},
        {3, 2, 3},
        {3, 4, 1},
        {4, 2, 2},
        {4, 3, 1}};
    int S1 = 1;
    vector<int> res1 = obj.bellmon_ford(V1, edges1, S1);

    cout << "Test Case 1: ";
    for (int i = 0; i < V1; i++)
        cout << res1[i] << " ";
    cout << endl;

    cout << endl;
    return 0;
}

// time complexity O(V*E)

// Test Case 1
// const int V1 = 6;
// vector<vector<int>> edges1 = {
//     {0, 1, 5},
//     {0, 2, 2},
//     {0, 3, 3},
//     {1, 0, 5},
//     {1, 2, 1},
//     {1, 3, 7},
//     {2, 0, 2},
//     {2, 1, 1},
//     {2, 3, 3},
//     {2, 4, 2},
//     {3, 0, 3},
//     {3, 1, 7},
//     {3, 2, 3},
//     {3, 4, 1},
//     {4, 2, 2},
//     {4, 3, 1}
// };
// int S1 = 1;
// vector<int> res1 = obj.bellmon_ford(V1, edges1, S1);

// cout << "Test Case 1: ";
// for (int i = 0; i < V1; i++)
//     cout << res1[i] << " ";
// cout << endl;

// // Test Case 2
