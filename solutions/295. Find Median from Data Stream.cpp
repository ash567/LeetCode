​
​
class MedianFinder {
private:
    int parity;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;
    
public:
    MedianFinder() {
        parity = -1;
        left.push(numeric_limits<int>::min());
        right.push(numeric_limits<int>::max());
    }
    void addNum(int num) {
        if(num < left.top()) {
            int nleft = left.top();
            left.pop();
            left.push(num);
            num = nleft;
        } else if(num > right.top()) {
            int nright = right.top();
            right.pop();
            right.push(num);
            num = nright;
        }
        parity++;
        parity %= 2;
        if(parity) {
            right.push(num);
        } else {
            left.push(num);
        }
        return;
    }
    
    double findMedian() {
        if(parity) {
            return (0.0 + left.top() + right.top())/2.0;
        } else {
            return left.top();
        }
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
