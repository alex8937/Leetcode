/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<int, int> dict;
        int ans = 0;
        for(int i = 0; i < points.size(); ++i) {
            dict.clear();
            int dup = 1, cur_max = 0;
            for(int j = i + 1; j < points.size(); ++j) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                if(dx == 0 && dy == 0) {
                    dup++;
                }
                else {
                    int gcdxy = gcd(dx, dy);
                    dx /= gcdxy;
                    dy /= gcdxy;  
                    dict[pairing(dx, dy)]++;
                    cur_max = max(cur_max, dict[pairing(dx, dy)]);
                }                
            }
            ans = max(ans, dup + cur_max);
        }
        return ans;
    }
    int pairing(int a, int b) {
        return (a + b) * (a + b + 1) / 2 + b;
    }
    
    int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b % a, a);
    }
};