// https://leetcode-cn.com/problems/implement-stack-using-queues/
class MyStack {
public:
    queue<int> q;
    queue<int> tmpq; // backup of q
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (q.size() != 1) {
            tmpq.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        while (!tmpq.empty()) {
            q.push(tmpq.front());
            tmpq.pop();
        }
        
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
