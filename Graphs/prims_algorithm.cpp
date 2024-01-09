#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;
class Solution
{
public:
    int prims(int V, vector<vector<int>> adj[])
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min Heap

        vector<int> visited(V, 0); // For visited vector
        pq.push({0, 0});           // Pushing {weight, node} in priority queue
        int sum = 0;               // For storing sum of weights of MST
        while (!pq.empty())
        {
            auto it = pq.top(); // Extracting node from priority queue
            pq.pop();

            int node = it.second;
            int weight = it.first;

            if (visited[node])
            { // If node is already visited
                continue;
            }

            visited[node] = 1; // Marking node as visited
              sum += weight;     // Adding weight of edge to sum

            for (auto it : adj[node])
            { // Iterating over all the edgesacent nodes
                int adjnode = it[0];
                int edge = it[1];
                if (!visited[adjnode])
                {                             // If node is not visited
                    pq.push({edge, adjnode}); // Pushing {weight, node} in priority queue
                }
            }
        }

        return sum; // Returning the sum of weights of MST
    }

    vector<int> prims_p(int V, vector<vector<int>> &edges)
    {

        vector<int> dist(V, 1e9);   // For distance vector
        vector<int> parent(V, -1);  // For parent vector
        vector<bool> vis(V, false); // For visited vector

        dist[0] = 0; // Distance of source vertex from itself is always 0

        for (int i = 0; i < V - 1; i++)
        {
            int mn = -1; // For storing minimum distance
            for (int j = 0; j < V; j++)
            {
                if (!vis[j] && (mn == -1 || dist[j] < dist[mn]))
                {           // If node is not visited and distance is smaller than previous distance
                    mn = j; // Updating minimum distance
                }
            }

            vis[mn] = true; // Marking node as visited

            for (auto it : edges)
            { // Iterating over all the adjacent nodes
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (!vis[v] && wt < dist[v])
                {                  // If node is not visited and weight is smaller than previous distance
                    dist[v] = wt;  // Updating distance of edgesacent node
                    parent[v] = u; // Updating parent of edgesacent node
                }
            }
        }

        return parent; // Returning the parent vector
    }
};
int main()
{

    cout << endl;
    return 0;
}