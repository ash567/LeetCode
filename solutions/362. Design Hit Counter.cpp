class HitCounter {
    queue<int> hitQ;
    
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hitQ.push(timestamp);    
    }
    
    int getHits(int timestamp) {
        int backTime = timestamp - 300;
        while(!hitQ.empty() and hitQ.front() <= backTime)
            hitQ.pop();
        return (int) hitQ.size();
    }
};
​
/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
