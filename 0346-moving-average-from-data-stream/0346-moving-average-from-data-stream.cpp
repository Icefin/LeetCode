class MovingAverage {
public:
    MovingAverage(int size) {
        _size = size;
        _sum = 0;
    }
    
    double next(int val) {
        if (_dq.size() >= _size) {
            _sum -= _dq[0];
            _dq.pop_front();
        }
        _dq.push_back(val);
        _sum += val;
        return ((double)_sum / _dq.size());
    }
    
private :
    int         _size;
    int         _sum;
    deque<int>  _dq;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */