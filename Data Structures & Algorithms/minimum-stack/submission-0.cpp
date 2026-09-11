#include <iostream>
#include <stack>

using namespace std; 

class MinStack {
private:
    stack<int> values;
    stack<int> mini;

public:
    MinStack() {
    }
    
    void push(int val) {
        values.push(val);
        
        if (mini.empty() || val<=mini.top()){
            mini.push(val);
        }
    }
    
    void pop() {
        if (values.top() == mini.top()) {
            mini.pop();
        }
       values.pop(); 
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
