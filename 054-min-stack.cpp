class MinStack {
private:
    stack<pair<int, int>> s1, s2;
    int size;
public:
    MinStack() {
        size = 0;
    }
    
    void push(int val) {
        if(s1.empty()) s1.push({val, 1});
        else {
            if(val < s1.top().first) {
                s1.push({val, size + 1});
                size++;
            } else {
                s2.push({val, size + 1});
                size++;
            }
        }
    }
    
    void pop() {
        if(s2.empty()) return s1.pop();
        if(s1.top().second > s2.top().second) {
            s1.pop();
        } else {
            s2.pop();
        }
    }
    
    int top() {
        if(s2.empty()) return s1.top().first;
        if(s1.top().second > s2.top().second) {
            return s1.top().first;
        } else {
            return s2.top().first;
        }
    }
    
    int getMin() {
        if(s2.empty()) return s1.top().first;
        if(s1.top().first < s2.top().first) {
            return s1.top().first;
        } else {
            return s2.top().first;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */