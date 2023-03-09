// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution
{
public:
    
    long long mod=1000000007;
    
    int solve(int n,int dp[]){
        if(n<=1){
            return 1;
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        long long a1 = solve(n-1,dp)%mod;
        long long a2 = (n>=2)?((n-1)*(solve(n-2,dp)%mod))%mod:0;
        
        dp[n] = (a1+a2)%mod;
        return (a1+a2)%mod;
    }
    
    int countFriendsPairings(int n) 
    { 
        // code here
        int dp[10001]={0};
        return solve(n,dp);
    }
};    
