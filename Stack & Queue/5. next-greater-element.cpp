class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge;
        int n1l = nums1.size(), n2l = nums2.size(), i, j, k; bool abh = false;
        
        for(i = 0; i < n1l; i++) {
            for(j = 0; j < n2l; j++) {
                if(nums1[i] == nums2[j]) {
                    for(k = j + 1; k < n2l; k++) {
                        if(nums2[k] > nums2[j]) {
                            nge.push_back(nums2[k]);
                            abh = true;
                            break;
                        }
                    }
                    if(!abh) nge.push_back(-1);
                    abh = false;
                }
            }
        }
        return nge;
    }
};
