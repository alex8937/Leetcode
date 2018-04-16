# include<iostream>
# include<vector>
# include<unordered_set>
# include<utility>
# include <cassert>
using namespace std;

class Robot{
  public:
    Robot(vector<vector<int>> _map, int _i, int _j) : map(_map), i(_i), j(_j) {}
    bool move(int dir) { // 0: right, 1 : up, 2 : left, 3 : down
    if(dir == 0) {
        if(j == map[0].size() - 1 || map[i][j + 1] == 1) return false;
        j = j + 1;
      }
      if(dir == 1) {
        if(i == 0 || map[i - 1][j] == 1) return false;
        i = i - 1;
      }     
      if(dir == 2) {
        if(j == 0 || map[i][j - 1] == 1) return false;
        j = j - 1;
      }
      if(dir == 3) {
        if(i == map.size() - 1 || map[i + 1][j] == 1) return false;
        i = i + 1;        
      }
      return true;
    }
  private:   
    vector<vector<int>> map;
    int i;
    int j;
};

struct Pos{
    Pos(int _i, int _j) : i(_i) , j(_j) {}
    int i, j;
    int visit = 0;
    vector<Pos*> neighbor = vector<Pos*>(4, nullptr); // 0: right, 1 : up, 2 : left, 3 : down
};

int opposite(int);
int getArea(Robot*);
void dfs(Robot*, unordered_set<int>&, Pos*);
const vector<int> del_j({1, 0, -1, 0});
const vector<int> del_i({0, -1, 0, 1});

int opposite(int dir) {
  return dir + 4 * (dir < 2) - 2;
}

int myhash(int a, int b) {
  a += (1 << 16);
  b += (1 << 16);
  return (((a + b) * (a * b + 1)) << 1) + b;
}

int getArea(Robot* rob) {
  unordered_set<int> dict;
  auto root = new Pos(0, 0);
  dfs(rob, dict, root);
  return dict.size();
}

void dfs(Robot* rob, unordered_set<int>& dict, Pos* root) {
  if(root -> visit == 4) return;
  dict.emplace(myhash(root -> i, root -> j));
  for(int k = 0; k < 4; ++k) {
    int new_i = root -> i + del_i[k];
    int new_j = root -> j + del_j[k];
    root -> visit += 1;    
    if(dict.count(myhash(new_i, new_j)) || !rob -> move(k)) continue;
    root -> neighbor[k] = new Pos(new_i, new_j);
    dfs(rob, dict, root -> neighbor[k]);
    rob -> move(opposite(k));
  }
}



int main() {
  vector<vector<int>> map1({{1,0,0,0,0,0},{1,1,1,0,1,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{1,0,0,0,0,0},{1,1,0,0,1,0},{0,0,0,1,0,0}});
  int area_test1 = 0;
  for(int i = 0; i < map1.size(); ++i) {
    for(int j = 0; j < map1[0].size(); ++j) {
      area_test1 += (map1[i][j] == 0);
    }
  }
  auto rob1 = new Robot(map1, 0, 3);
  int area1 = getArea(rob1);
  assert(area1 == area_test1);
  cout << "1 passed" << endl;
  
  vector<vector<int>> map2({{0,1,0},{0,0,0},{0,0,0},{0,0,1}});
  int area_test2 = 0;
  for(int i = 0; i < map2.size(); ++i) {
    for(int j = 0; j < map2[0].size(); ++j) {
      area_test2 += (map2[i][j] == 0);
    }
  }
  auto rob2 = new Robot(map2, 0, 0);
  int area2 = getArea(rob2);
  assert(area2 == area_test2);
  cout << "2 passed" << endl;  
  return 0;
}