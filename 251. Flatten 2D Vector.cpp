class Vector2D {
private:
    vector<vector<int>> :: iterator it, itend;
    int j;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin(), itend = vec2d.end();
        j = 0;
    }

    int next() {
        return (*it)[j++];
    }

    bool hasNext() {
        while(it != itend && j == (*it).size()) {
            it++;
            j = 0;
        }
        return it != itend;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */