/*The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively 
and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. 
It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. 
Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. 
Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.
*/



#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){  // n is number of nodes and m is number of edges
	
	// Write your code here

	unordered_map<int , list<int> >  adj;  // adjacency list of graph 

	for(int i = 0; i < edges.size(); i++){  // creating adjacency list
        int u = edges[i].first; // first node of edge 
		int v = edges[i].second; // second node of edge 


		adj[u].push_back(v);  // adding edge to adjacency list
		adj[v].push_back(u);  // adding edge to adjacency list


	}

	unordered_map<int, bool> visited;   // visited array to keep track of visited nodes 
	unordered_map< int, int> parent;    // parent array to keep track of parent of each node in bfs tree
	queue<int> q;                    // queue for bfs traversal

	q.push(s);

	visited[s]= true;

	while(!q.empty()){    // bfs traversal of graph 
		int front= q.front();
		q.pop();

		for(auto i: adj[front]){   // traversing all the neighbours of front node
			if(!visited[i]){
				visited[i]= true;
				parent[i]= front;
				q.push(i);

			}
		}
	}
	//perpare shortest path

	vector<int> ans;    // vector to store shortest path
 
	int currnode= t;    // current node is destination node
    ans.push_back(t);  // adding destination node to ans vector
	while(currnode != s){   // traversing from destination node to source node
        currnode= parent[currnode];
		ans.push_back(currnode);   // adding current node to ans vector
	}   
    reverse(ans.begin(), ans.end());   // reversing the ans vector to get shortest path from source to destination
	return ans;
	
}


//Time Complexity: O(N + M)
//Space Complexity: O(N + M)
//where N is the number of nodes and M is the number of edges in the graph.
//Sample Input 1:
//5 5
//1 2
//1 3
//2 4
//3 4
//4 5
//1 5
//Sample Output 1:
//1 5
//Sample Input 2:
//5 5
//1 2
//1 3
//2 4
//3 4
//4 5
//1 5
//Sample Output 2:
//1 3 4 5



