class MedianFinder {
public:
    multiset<int> data;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.insert(num);
    }
    
    double findMedian() {
        int n = data.size();
        auto it = next(data.begin(), n / 2);
        if (n % 2 == 1) return *it;
        return (*it + *prev(it)) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */