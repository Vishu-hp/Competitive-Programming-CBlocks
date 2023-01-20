// Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once.
// Find out the total number of ways in which friends can remain single or can be paired up. Note: Since answer can be very large, return your answer mod 10^9+7.



long long mod = 1e9+7;
vector<int>dp(10001,-1);

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n<=1){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        long long a1 = countFriendsPairings(n-1)%mod;
        long long a2 = (n>=2)?((n-1)*(countFriendsPairings(n-2)%mod))%mod:0;
        
        return dp[n]=(a1+a2)%mod;
    }
};
