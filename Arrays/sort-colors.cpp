class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i,n=nums.size(),low=0,mid=0,high=n-1;
        
        for(i=0;i<n;i++) {
            while(mid<=high) {
                switch(nums[mid]) {
                    case 0:
                        swap(nums[low++], nums[mid++]);
                        break;
                    case 1:
                        mid++;
                        break;
                    case 2:
                        swap(nums[mid], nums[high--]);
                        break;
                }
            }
        }
    }
};


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int zc=0,oc=0,tc=0;
//         for(auto x:nums) {
//             if(x==0) zc+=1;
//             else if(x==1) oc+=1;
//             else tc+=1;
//         }
//         int i = 0;
//         for(int p=0;p<zc;p++) {nums[i]=0; i++;}
//         for(int p=0;p<oc;p++) {nums[i]=1; i++;}
//         for(int p=0;p<tc;p++) {nums[i]=2; i++;}
//     }
// };
