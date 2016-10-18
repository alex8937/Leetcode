#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

void Flatten(Node* root) {			// Preorder
	if(!root) return;
	Node* cur = root, tail = nullptr;
	while(cur) {
		if(cur -> left) {
			auto link_head = cur -> left;
			auto link_tail = link_head;
			while(link_tail -> right) link_tail = link_tail -> right;
			link_tail -> right = cur -> right;
			cur -> right = link_head;
			cur -> left = nullptr;
		}
		tail = cur;
		cur = cur -> right;
	}
	cur = root;
	while(cur && cur -> next) {
		auto nxt = cur -> next;
		nxt -> left = cur;
		cur = cur -> next;
	}
	tail -> right = root;
	root -> left = tail;
}

void wrap(Node* root) {  // Preorder
	Node* pre = nullptr, tail = nullptr;
	Tree2Dlinkedlist(root, pre, tail);
	if(tail) tail -> right = root;
	if(root) root -> left = tail;
}

void Tree2Dlinkedlist(Node* root, Node*& pre, Node*& tail){  
	if(!root) return;
	if(!tail) tail = root;
	Tree2Dlinkedlist(root -> right);
	Tree2Dlinkedlist(root -> left);
	root -> right = pre;
	root -> left = nullptr;
	if(pre) pre -> left = root;
	pre = root;
}

void Flatten(Node* root) {			// Inorder
	if(!root) return;
	Node* cur = root, tail = nullptr, pre = nullptr, new_head = nullptr;
	while(cur) {
		if(cur -> left) {
			auto link_head = cur -> left;
			auto link_tail = link_head;
			while(link_tail -> right) link_tail = link_tail -> right;
			link_tail -> right = cur;
			cur -> left = nullptr;
			cur = head;
		}
		if(!cur -> left) {
			cur -> left = pre;
			pre = cur;
			if(!new_head) new_head = cur;
			cur = cur -> right;
	}
	pre -> right = new_head;
	new_head -> left = pre;
}

void Tree2Dlinkedlist(Node* root, Node*& last){  // Inorder
	if(!root) return;
  /* Go to left most child */
	if(root -> left) Tree2Dlinkedlist(root -> left, last);
  /* If this wasn't the first node being added to list*/  
	if(last) last -> right = root;
	
  /*make left pointer point to last node, and update the 
   last node to current*/

  root -> left = last;
  last = root;

  /* If there is right child, process right child */
  if(root -> right) Tree2Dlinkedlist(root -> right, last);

}
	
