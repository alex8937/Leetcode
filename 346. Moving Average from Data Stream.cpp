class MovingAverage {
private:
    queue<int> qu;
    int k;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        k = size;
        sum = 0;
    }
    
    double next(int val) {
        if(qu.size() == k) {
            sum -= qu.front();
            qu.pop();
        }
        qu.push(val);
        sum += val;
        return double(sum) / qu.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */