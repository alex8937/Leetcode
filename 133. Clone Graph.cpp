/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
// BFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;
        queue<UndirectedGraphNode*> qu;
        if(!node) return nullptr;
        qu.push(node);
        dict[node] = new UndirectedGraphNode(node -> label);
        while(!qu.empty()) {
            auto cur = qu.front();
            for(auto it : cur -> neighbors) {
                if(!dict.count(it)) {
                    dict[it] = new UndirectedGraphNode(it -> label);
                    qu.push(it);
                }
                dict[cur] -> neighbors.push_back(dict[it]);
            }
            qu.pop();
        }
        return dict[node];
    }
};

class Solution {
public:
// DFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> dict;
        return clone(node, dict);
    }
    UndirectedGraphNode * clone(UndirectedGraphNode * node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& dict) {
        if(!node) return nullptr;
        if(!dict.count(node)) {
            dict[node] = new UndirectedGraphNode(node -> label);
            for(auto it : node -> neighbors) {
                dict[node] -> neighbors.push_back(clone(it, dict));
            }
        }
        return dict[node];
    }
};

class Solution {
public:
//DFS v2
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;
        help(dict, node);
        return dict[node];
    }
    void help(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& dict, UndirectedGraphNode *node) {
        if(!node) return;
        dict[node] = new UndirectedGraphNode(node -> label);
        for(auto it : node -> neighbors) {
            if(!dict.count(it)) help(dict, it);
            dict[node] -> neighbors.push_back(dict[it]);
        }
    }
};