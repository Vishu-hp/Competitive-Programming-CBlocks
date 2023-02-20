class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[1001]={0};
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            dp[i] = INT_MIN;
            for(int j=1;j<=i;j++){
                dp[i] = max(dp[i],dp[i-j]+price[j-1]);
            }
        }
        
        return dp[n];
    }
};
