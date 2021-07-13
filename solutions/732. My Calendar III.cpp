#define LOWER 0
#define UPPER (1e9 + 1)
​
class MyCalendarThree {
    unordered_map<long, int> segTree, lazy;
    void update(long start, long end, long left = LOWER, long right = UPPER, long index = 1) {
        if(start == left and end == right) {
            segTree[index]++;
            lazy[index]++;
            return;
        }
        long mid = left + (right - left)/2;
        if(end <= mid) {
            update(start, end, left, mid, 2 * index);
        } else if(mid <= start) {
            update(start, end, mid, right, 2 * index + 1);
        } else {
            update(start, mid, left, mid, 2 * index);
            update(mid, end, mid, right, 2 * index + 1);
        }
        segTree[index] = lazy[index] + max(segTree[2 * index], segTree[2 * index + 1]);
        return;
    }
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        update(start, end);
        return segTree[1];
    }
};
​
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
