class Solution {
  public:
    long long mod = 1000000007;
    long long int solve(long long int n,long long dp[]){
        if(n<=2){
            return 1;
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        long long ans  = (solve(n-1,dp) + solve(n-2,dp))%mod;
        dp[n] = ans;
        return ans;
    }
    
    long long int nthFibonacci(long long int n){
        // code here
        long long dp[1001] = {0};
        return solve(n,dp);
    }
};
