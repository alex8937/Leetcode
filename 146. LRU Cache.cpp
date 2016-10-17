class LRUCache{
private:
  int len;
  list<pair<int, int>> mylist;  // key , val
  unordered_map<int, list<pair<int, int>>::iterator> dict; // key, iter
public:
  LRUCache(int capacity) {
      len = capacity;
  }
  
  int get(int key) {
    if(!dict.count(key)) return -1;
    int val = dict[key] -> second;
    set(key, val);
    return val;
  }
  
  void set(int key, int value) {
    if(dict.count(key)) {
      mylist.splice(mylist.begin(), mylist, dict[key]);
      mylist.front().second = value;
    }
    else {
      if(dict.size() == len) {
        int del_key = mylist.back().first;
        mylist.pop_back();
        dict.erase(del_key);
      }
      mylist.emplace_front(key, value);
      dict[key] = mylist.begin();
    }
  }
};