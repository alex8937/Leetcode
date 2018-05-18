/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
// ver1: Using hashmap
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

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
// Using pointer as dictionary
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