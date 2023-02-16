class Solution {
  public:
    long long mod = 1000000007;
    
    long long int nthFibonacci(long long int n){
        // code here
        long long dp[1001] = {0};
        dp[1] = 1;
        for(long long i=2;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        return dp[n];
    }
};
