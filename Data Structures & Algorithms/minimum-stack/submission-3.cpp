class MinStack {
public:
    
    stack<long> st; 
    long min;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min = val;
        }
        else{
            st.push(val-min);
            if(val < min){
                min = val;
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            long popped = st.top();
            st.pop();
            if(popped < 0){
                min = min-popped;
            }
        }
    }
    
    int top() {
        if(!st.empty()){
            return (st.top() > 0) ? (st.top()+min) : (int)min;
        }
    }
    
    int getMin() {
        return (int)min;
    }
};
