# include<iostream>
# include<vector>
# include<unordered_set>
# include<unordered_map>
# include<utility>
# include <cassert>
# include <boost/functional/hash.hpp>

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

int getArea(Robot*);
void help(unordered_set<int>&, Robot*&, int, int);

int myhash(int a, int b) {
  //Cantor pairing function 
	a += 1 << 16;
	b += 1 << 16;
	return (a + b) * (a + b + 1) / 2 + b;
}
int x[4] = { 1, 0, -1, 0 };
int y[4] = { 0, 1, 0, -1 };

int getArea(Robot* rob) {
	unordered_set<int> dict;
	help(dict, rob, 0, 0);
	return dict.size();
}

void help(unordered_set<int>& dict, Robot*& rob, int i, int j) {
  dict.insert(myhash(i, j));
	for (int k = 0; k < 4; ++k) {
    int new_i = i + x[k], new_j = j + y[k];
		if (dict.count(myhash(new_i, new_j)) || !rob->move(k)) continue;
		help(dict, rob, new_i, new_j);
		rob -> move((k + 2) % 4);
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