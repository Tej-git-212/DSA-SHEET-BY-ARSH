class Solution {
public:
    bool isValid(string s) {
        int i, l = s.length();
        stack<char>st;
        for(i = 0; i < l; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if(st.empty()) return false;
                else if((s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '[')) return false;
                else st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
