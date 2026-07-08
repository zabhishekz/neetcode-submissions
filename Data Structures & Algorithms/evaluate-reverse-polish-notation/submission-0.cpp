#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                if(st.size() > 1){
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int ans =0;
                    if(tokens[i] == "+"){
                        ans = x+y;
                    }
                    else if (tokens[i] == "-"){
                        ans = y-x;
                    }
                    else if(tokens[i] == "*"){
                        ans = x*y;
                    }
                    else if (tokens[i] == "/"){
                        ans = y/x;
                    }
                    st.push(ans);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
