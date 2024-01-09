#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> dijksta(int V, vector<vector<int>> adj[], int S)
    // V is number of nodes and adj is adjacency list of graph
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
        vector<int> dist(V);  // For distance vector

        for (int i = 0; i < V; i++)  // Initialize all distances as infinite
        {
            dist[i] = INT_MAX;
        }

        dist[S] = 0;   // Distance of source vertex from itself is always 0
        pq.push({0, S});   // Inserting {0 , source} in the priority queue

        while (!pq.empty())  // Dijkstra Algorithm loop
        {

            int dis = pq.top().first;  // Extracting min distance node
            int node = pq.top().second; // Extracting node from priority queue
            pq.pop();  // Poping the element

            for (auto it : adj[node]) // Iterating over all the adjacent nodes
            {
                int edgeWeight = it[1];  // Extracting edge weight
                int adjNode = it[0];  // Extracting adjacent node

                if (dis + edgeWeight < dist[adjNode])   // If new distance is smaller than previous distance
                {
                    dist[adjNode] = dis + edgeWeight;  // Updating distance of adjacent node
                    pq.push({dist[adjNode], adjNode});  // Pushing {new distance , adjacent node} in priority queue
                }
            }
        }

        return dist;  // Returning the distance vector
    }
};
const int V = 100;
int main(){

Solution obj;

    // Test Case 1
    const int V1 = 6;
    vector<vector<int>> adj1[V1] = {
        {{1, 5}, {2, 2}, {3, 3}},
        {{0, 5}, {2, 1}, {3, 7}},
        {{0, 2}, {1, 1}, {3, 3}, {4, 2}},
        {{0, 3}, {2, 3}, {4, 1}},
        {{2, 2}, {3, 1}}
    };
    int S1 = 2;
    vector<int> res1 = obj.dijksta(V1, adj1, S1);

    cout << "Test Case 1: ";
    for (int i = 0; i < V1; i++)
        cout << res1[i] << " ";
    cout << endl;

    // Test Case 2
    const int V2 = 5;
    vector<vector<int>> adj2[V2] = {
        {{1, 5}, {2, 2}, {3, 3}},
        {{0, 5}, {2, 2}, {3, 3}},
        {{0, 2}, {1, 2}, {4, 3}},
        {{0, 3}, {1, 3}, {4, 1}},
        {{2, 3}, {3, 1}}
    };
    const int S2 = 0;
    vector<int> res2 = obj.dijksta(V2, adj2, S2);

    cout << "Test Case 2: ";
    for (int i = 0; i < V2; i++)
        cout << res2[i] << " ";
    cout << endl;

    return 0;

    }


// Input:
// 2
// 6 7
// 0 1 5
// 0 2 2
// 0 3 3
// 2 3 3
// 1 3 1
// 4 5 2
// 3 5 5
// 2
// 5 4
// 0 1 5
// 0 2 2
// 0 3 3
// 2 4 3
// 0
// Output:
// 0 5 2 3 7 8
// 0 5 2 3 5
// Explanation:
// Testcase 1:
// The graph would look like
// 0
// 1
// 2    
// 3
// 4
// 5
// The shortest distance from source node 2 to other nodes are as follows:
// 0->2 = 2, 1->2 = 5, 2->2 = 0, 3->2 = 3, 4->2 = 7, 5->2 = INF
// Testcase 2:
// The graph would look like
// 0
// 1
// 2
// 3
// 4
// The shortest distance from source node 0 to other nodes are as follows:
// 0->0 = 0, 1->0 = 5, 2->0 = 2, 3->0 = 3, 4->0 = INF
