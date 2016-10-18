#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	vector<TreeNode*> child;
	TreeNode(int v) : val(v){}
	void add(TreeNode* dummy) {
		child.push_back(dummy);
	}
};

void childcount(unordered_map<TreeNode*, int>& dict, TreeNode* root) {
	if(!root) return;
	dict[root] = 1;
	for(auto it : root -> child) {
		childcount(dict, it);
		dict[root] += dict[it];
	}
}

void Evencut(vector<TreeNode*>& ans, TreeNode* root, unordered_map<TreeNode*, int>& dict) {
	if(!root) return;
	for(auto it : root -> child) {
		if(dict[it] % 2 == 0) {
			Evencut(ans, it, dict);
			dict[root] -= dict[it];
		}
	}
	ans.push_back(root);
}

int main() {
	TreeNode* n1 = new TreeNode(1);	
	TreeNode* n2 = new TreeNode(2);	
	TreeNode* n3 = new TreeNode(3);	
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);	
	TreeNode* n7 = new TreeNode(7);	
	TreeNode* n8 = new TreeNode(8);	
	TreeNode* n9 = new TreeNode(9);
	TreeNode* n10 = new TreeNode(10);
	n3 -> add(n4);
	n8 -> add(n9);
	n8 -> add(n10);
	n6 -> add(n8);
	n2 -> add(n7);
	n2 -> add(n5);
	n1 -> add(n3);
	n1 -> add(n6);
	n1 -> add(n2);
	
	unordered_map<TreeNode*, int> dict;
	childcount(dict, n1);
	vector<TreeNode*> ans;
	Evencut(ans, n1, dict);
	for(auto it : ans) cout << it -> val << " " ;
	cout << '\n';
	for(auto it : ans) cout << dict[it] << " " ;	
	
}