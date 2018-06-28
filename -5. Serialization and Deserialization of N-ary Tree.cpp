#include <sstream>
#include <vector>
#include <stack>

class NaryNode {
public:
	int val;
	vector<NaryNode*> child;
	NaryNode(int v) : val(v) {}
	void add_child(NaryNode * node) {
		child.push_back(node);
	}
};


string seralize(NaryNode* node) {
	if (!node) return "";
	string str_root = to_string(node->val);
	if (node->child.empty()) return str_root + " #";
	string str_child;
	for (auto c : node->child) {
		if (!str_child.empty()) str_child.push_back(' ');
		str_child.append(seralize(c));
	}
	return str_root + " " + str_child + " #";
}

NaryNode* deseralize(string str) {
	stringstream ss(str);
	string node_str;
	stack<NaryNode* > st;
	NaryNode* root = nullptr;
	while (ss >> node_str) {
		if (node_str == "#") {
			st.pop();
		}
		else {
			auto node = new NaryNode(stoi(node_str));
			if (st.empty()) {
				root = node;
			}
			else {
				st.top()->add_child(node);
			}
			st.push(node);
		}
	}
	return root;
}