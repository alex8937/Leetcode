#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>
using namespace std;


void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
   for (int i = 1; i < parent.size(); i++)
      printf("%d -> %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

int find_min(const unordered_set<int>& nodes, const vector<int>& key) {
	int ans;
	for(auto it = nodes.begin(); it != nodes.end(); ++it) {
		if(it == nodes.begin() || key[*it] < key[ans]) ans = *it;
	}
	return ans;
}

void primMST(const vector<vector<int>>& graph) {
	const int V = graph.size();
	vector<int> key(V, INT_MAX);
	vector<int> parent (V, -1);
	vector<bool> inMST(V, false);
	key[0] = 0;
	unordered_set<int> nodes;
	for(int i = 0; i < V; ++i) {
		nodes.insert(i);
	}
	while(!nodes.empty()) {
		int node = find_min(nodes, key);
		nodes.erase(node);
		inMST[node] = true;
		for(int i = 0; i < graph[node].size(); ++i) {
			if(i == node || graph[node][i] == 0) continue;
			if(!inMST[i] && graph[node][i] < key[i]) {
				parent[i] = node;
				key[i] = graph[node][i];
			}
		}
	}
	printMST(parent, graph);
}


int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   vector<vector<int>> graph = {{0, 2, 0, 6, 0},
																{2, 0, 3, 8, 5},
																{0, 3, 0, 0, 7},
																{6, 8, 0, 0, 9},
																{0, 5, 7, 9, 0},
															 };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}