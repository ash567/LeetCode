struct Node {
    int freq, order, id;
    Node(int f, int o, int i) {
        freq = f;
        order = o;
        id = i;
    }
    bool operator < (const Node& n) {
        if(freq < n.freq)
            return true;
        else if(freq > n.freq)
            return false;
        else if(order < n.order)
            return true;
        else if(order > n.order)
            return false;
        else
            return true;
    }
};
​
// Why can I not make it const?
bool comp (Node& n1, Node& n2) {
        return n1 < n2;
};
​
class FreqStack {
    unordered_map<int, int> count;
    int priority;
    priority_queue<Node, vector<Node>, decltype(&comp)> pq{comp};
public:
    FreqStack() {
     priority = 0;   
    }
    
    void push(int val) {
        count[val]++;
        pq.push(Node(count[val], priority, val));
        priority++;
    }
    
    int pop() {
        Node n = pq.top();
        count[n.id]--;
        pq.pop();
        return n.id;
    }
};
​
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
