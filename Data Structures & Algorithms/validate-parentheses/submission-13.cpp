class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> umap = {
            {')' , '('},
            {'}' , '{'},
            {']' , '['},
        };

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else if (st.empty() || umap[c] != st.top()){
                return false;
            } else {
                st.pop();
            }
        }
        
        if(!st.empty()) return false;

        return true;
    }
};
