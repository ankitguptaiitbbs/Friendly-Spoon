// Approach 1:
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
            
        int num = s2.top();
        s2.pop();
        return num;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Approach 2:
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s2.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            stack<int> temp;
            while(!s1.empty()){
                temp.push(s1.top());
                s1.pop();
            }
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            while(!temp.empty()){
                s1.push(temp.top());
                temp.pop();
            }
        }
        int num = s1.top();
        s1.pop();
        return num;
    }
    
    int peek() {
        if(!s2.empty()){
            stack<int> temp;
            while(!s1.empty()){
                temp.push(s1.top());
                s1.pop();
            }
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            while(!temp.empty()){
                s1.push(temp.top());
                temp.pop();
            }
        }
        return s1.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// There could be other approaches possible

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
