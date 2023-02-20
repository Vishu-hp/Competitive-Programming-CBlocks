class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int sumsf;
        sumsf = nums[0];
        int ans = sumsf;
        for(int i=1;i<nums.size();i++){
            sumsf = max(sumsf+nums[i],nums[i]);
            ans = max(ans,sumsf);
        }
        return ans;
    }
};
