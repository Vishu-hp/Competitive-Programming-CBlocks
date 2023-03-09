// https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1

class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    long long mod=1000000007;
    
    long long solve(int n,long long dp[]){
        if(n==0 || n==1){
            return 1;
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long a1=solve(i-1,dp)%mod;
            long long a2 = solve(n-i,dp)%mod;
            ans += (a1*a2)%mod;
        }
        
        dp[n] = ans%mod;
        return ans%mod;
    }
    
    int numTrees(int N) 
    {
        // Your code here
        long long dp[10001]={0};
        return solve(N,dp);
    }
};
