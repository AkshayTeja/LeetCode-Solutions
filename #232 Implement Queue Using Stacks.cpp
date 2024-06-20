class MyQueue {
public:
    stack <int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int temp=s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//Another approach with O(1) amortized TC

class MyQueue {
public:
    stack <int> ip,op;
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
        if(!op.empty())
        {
            int temp=op.top();
            op.pop();
            return temp;
        }
        else
        {
            while(!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
            int temp=op.top();
            op.pop();
            return temp;
        }
    }
    
    int peek() {
        if(!op.empty())
        {
            return op.top();
        }
        else
        {
            while(!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
            return op.top();
        }
    }
    
    bool empty() {
        if(op.empty() && ip.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */