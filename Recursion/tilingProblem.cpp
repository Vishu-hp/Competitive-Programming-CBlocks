// Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled.
// A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. Print the answer modulo 109+7.

 
vector<long long>dp(100001,-1);
long long mod=1000000007;
class Solution {
  public:
    long long numberOfWays(long long N) {
        //code here
        if(N==1 || N==0){
            return 1;
        }
        
        if(dp[N]!=-1){
            return dp[N];
        }
        
        long long a1 = numberOfWays(N-1);
        long long a2 = (N>=2)?numberOfWays(N-2):0;
        return dp[N]=(a1+a2)%mod;
    }
};
