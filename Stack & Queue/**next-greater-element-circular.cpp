class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ngec;
        stack<int>st; int s = nums.size();
        
        for(int i = (2 * s) - 1; i >= 0; i--) {
            while(!st.empty() && nums[i % s] >= st.top()) st.pop();
            
            if(i < s) {
                if(st.empty()) ngec.push_back(-1);
                else ngec.push_back(st.top());
            }
            st.push(nums[i % s]);
        }
        reverse(ngec.begin(), ngec.end());
        return ngec;
    }
};
