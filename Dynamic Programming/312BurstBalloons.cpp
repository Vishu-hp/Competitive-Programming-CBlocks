class Solution {
public:
    int solve(vector<int>&nums,int x,int y,int dp[][301]){
        if(dp[x][y]!=0){
            return dp[x][y];
        }
        
        int v1 = (x-1>=0)?nums[x-1]:1;
        int v2 = (y+1<nums.size())?nums[y+1]:1;

            
        int ans=INT_MIN;
        for(int p=x;p<=y;p++){
            int v3 = (p>x)?solve(nums,x,p-1,dp):0;
            int v4 = (p<y)?solve(nums,p+1,y,dp):0;
            
            ans=max(ans,v3+v4+ nums[p]*v1*v2);
            
        }
        
        dp[x][y]=ans;
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int dp[301][301] = {0};
        return solve(nums,0,n-1,dp);
    }
};
