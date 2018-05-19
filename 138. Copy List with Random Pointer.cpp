class Solution {
public:
// ver1: Using hashmap: iteration
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> dict;
        auto cur = head;
        while(cur) {
            dict[cur] = new RandomListNode(cur -> label);
            cur = cur -> next;
        }
        cur = head;
        while(cur) {
            dict[cur] -> next = dict[cur -> next];
            dict[cur] -> random = dict[cur -> random];
            cur = cur -> next;
        }
        return dict[head];
    }
};


class Solution {
public:
// ver2: Using hashmap: recursion
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> dict;
        return copy(head, dict);
    }
    RandomListNode * copy(RandomListNode* head, unordered_map<RandomListNode*, RandomListNode*>& dict) {
        if(!head) return nullptr;
        if(dict.count(head)) return dict[head];
        dict[head] = new RandomListNode(head -> label);
        dict[head] -> next = copy(head -> next, dict);
        dict[head] -> random = copy(head -> random, dict);
        return dict[head];
    }
};

class Solution {
public:
// ver3: Using pointer as dictionary
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        auto cur = head;
        while(cur) {
            auto nxt = cur -> next;
            cur -> next = new RandomListNode(cur -> label);
            cur -> next -> next = nxt;
            cur = nxt;
        }
        cur = head;
        while(cur) {
            if(cur -> random) cur -> next -> random = cur -> random -> next;
            cur = cur -> next -> next;
        }
        auto newhead = head -> next;
        cur = head;
        while(cur -> next) {
            auto nxt = cur -> next;
            cur -> next = nxt -> next;
            cur = nxt;
        }
        return newhead;
    }
};