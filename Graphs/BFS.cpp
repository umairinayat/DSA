#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS traversal
void BFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph representation as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 2, 3},  // Node 1 is connected to nodes 0, 2, and 3
        {0, 1, 3},  // Node 2 is connected to nodes 0, 1, and 3
        {1, 2, 4},  // Node 3 is connected to nodes 1, 2, and 4
        {3}         // Node 4 is connected to node 3
    };

    int startNode = 0;
    cout << "BFS traversal starting from node " << startNode << ": ";
    BFS(graph, startNode);

    return 0;
}
 