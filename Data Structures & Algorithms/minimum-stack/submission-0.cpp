class MinStack {
public:
    
    stack<pair<int,int>> st; 
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(make_pair(val, val));
        }
        else{
            st.push(make_pair(val, min(val,st.top().second)));
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top().first;
        }
    }
    
    int getMin() {
        return st.top().second;
    }
};
