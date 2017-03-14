class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	//version1: BFS
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        initialize(adj, indegree, prerequisites);
        queue<int> zeroin;
        int finished = 0;
        for(int i = 0; i < indegree.size(); ++i) {
            if(!indegree[i]) zeroin.push(i); 
        }
        while(!zeroin.empty()) {
            auto course = zeroin.front();
            for(int post : adj[course]) {
                indegree[post]--;
                if(!indegree[post]) zeroin.push(post);
            }
            zeroin.pop();
            finished++;
        }
        return finished == numCourses;
    }
    
    void initialize(vector<vector<int>>& adj, vector<int>& indegree, vector<pair<int, int>> prerequisites) {
        for(auto it : prerequisites) {
            adj[it.first].push_back(it.second);
            indegree[it.second]++;
        }
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	//version2: DFS
        vector<vector<int>> adj = initialize(prerequisites, numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> visiting(numCourses, false);
        for(int course = 0; course < numCourses; ++course) {
            if(!visited[course] && dfs_cycle(adj, course, visited, visiting)) {
                return false;
            }
        }
        return true;
    }
    
    vector<vector<int>> initialize(vector<pair<int, int>>& prerequisites, int numCourses) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            adj[it.first].push_back(it.second);
        }
        return adj;
    }
    
    bool dfs_cycle(const vector<vector<int>>& adj, int course, vector<bool>& visited, vector<bool>& visiting) {
        visiting[course] = true;
        for(auto post : adj[course]) {
            if(visiting[post] || !visited[post] && dfs_cycle(graph, post, visited, visiting)) return true;
        }
        visiting[course] = false;
        visited[course] = true;
        return false;
    }
    
};