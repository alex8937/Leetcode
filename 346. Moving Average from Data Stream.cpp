class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int _size): size(_size) {
        sum = 0;
    }
    
    double next(int val) {
        if(qu.size() == size) {
            sum -= qu.front();
            qu.pop();
        }
        qu.push(val);
        sum += val;
        return double(sum) / double(qu.size());
    }
private:
    int size;
    queue<int> qu;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */