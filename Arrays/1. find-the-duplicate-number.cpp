// TC-O(n) AS-O(n) solution

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(),i;
        vector<int>v(n, 0);
        
        for(i=0;i<n;i++) v[nums[i]-1]+=1;
        
        for(i=0;i<v.size();i++) if(v[i]>1) return i+1;
        v.clear(); return 0;
    }
};


// TC-O(nlogn) AS-O(1) solution

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<nums.size()-1;i++) {
//             if(nums[i]==nums[i+1]) return nums[i];
//         }
//         return 0;
//     }
// };
