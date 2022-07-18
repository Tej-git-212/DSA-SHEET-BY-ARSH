class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if(s == t) return true;
        
        stack<char>ss, tt; int sl = s.length(), tl = t.length(), i, j;
        for(i = 0; i < sl; i++) {
            if(s[i] != '#') ss.push(s[i]);
            else if(!ss.empty() && s[i] == '#') ss.pop();
        }
        for(j = 0; j < tl; j++) {
            if(t[j] != '#') tt.push(t[j]);
            else if(!tt.empty() && t[j] == '#') tt.pop();
        }
        
        if((ss.empty()&&!tt.empty()) || (tt.empty()&&!ss.empty())) return false;
        
        while(!ss.empty() && !tt.empty()) {
            if(ss.top() != tt.top()) return false;
            else {
                ss.pop(); 
                tt.pop();
                if((ss.empty()&&!tt.empty()) || (tt.empty()&&!ss.empty())) return false;
            }
        }
        return true;
    }
};
