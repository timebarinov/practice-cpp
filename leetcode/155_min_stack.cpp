class MinStack {
    public:
    MinStack() {        
        min = INT_MAX;
    }
    void push(int x) {
        if (x <= min) {
            stack.push(min);
            min = x;
        }        
        stack.push(x);
                
    }
    void pop() {
        if (min == stack.top()) {
            stack.pop();
            min = stack.top();
            stack.pop();
        }
        else {
            stack.pop();
        }
    }
    int top() {       
        return stack.top();
    }
    int getMin() {
        return min;
    }
    private:
    stack<int> stack;
    int min;
};

// не мое решение, но интересное.
class MinStack {
public:
  stack<int> st,stmin;
  
  void push(int val){
    st.push(val);
    if(stmin.empty()) stmin.push(val);
    else stmin.push(min(val, stmin.top()));
  }
    
  void pop() {
    st.pop(), stmin.pop();      
  }
    
  int top() {
    return st.top();    
  }
    
  int getMin() {
    return stmin.top();      
  }
};