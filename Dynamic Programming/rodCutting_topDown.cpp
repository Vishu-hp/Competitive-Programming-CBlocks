class Solution{
  public:
    int solve(int price[],int n,int dp[]){
        if(n==0){
            return 0;
        }
        
        if(n==1){
            return price[0];
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(n-i>=0){
                int subAns = solve(price,n-i,dp) + price[i-1];
                ans = max(ans,subAns);   
            }
        }
        
        dp[n]=ans;
        return ans;
    }
  
    int cutRod(int price[], int n) {
        //code here
        int dp[1001]={0};
        return solve(price,n,dp);
    }
};
