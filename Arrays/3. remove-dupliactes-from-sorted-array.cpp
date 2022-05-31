class Solution 
{
  public:
     int removeDuplicates(vector<int>& nums) 
     {
        int i, j=0, n = nums.size();
        for(i=1;i<n;) {
            if(nums[i]==nums[j]) i++;
            else {
                nums[++j]=nums[i++];
            } 
        }
         return j+1;
     }
};
