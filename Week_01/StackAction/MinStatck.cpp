#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> intStack;
    stack<int> minStack;

    MinStack() {}
    
    void push(int x) {
        intStack.push(x);
        if (minStack.empty() || minStack.top() >= x)
            minStack.push(x);
    }
    
    void pop() {
        if (!intStack.empty() && !minStack.empty()) {
            if (intStack.top() == minStack.top())
                minStack.pop();
            intStack.pop();
        }
    }
    
    int top() {
        return intStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */