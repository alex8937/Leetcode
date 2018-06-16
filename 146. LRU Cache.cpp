class LRUCache {
private:
    int len;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>> :: iterator> dict;
public:
    LRUCache(int capacity) : len(capacity) {}
    
    int get(int key) {    
        if(!dict.count(key)) return -1;
        int val = dict[key] -> second;
        put(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if(dict.count(key)) {
            auto it = dict[key];
            it -> second = value;
            cache.splice(cache.begin(), cache, it);
        }
        else {
            if(dict.size() == len) {
                auto key_del = cache.back().first;
                dict.erase(key_del);
                cache.pop_back();
            }
            cache.emplace_front(key, value);
            dict[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */