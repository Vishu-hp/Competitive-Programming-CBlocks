class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int W, int wt[], int val[], int n,vector<vector<int>>&dp){
       if(n==0 || W==0){
           return 0;
       }
       
       if(dp[n][W] != -1){
           return dp[n][W];
       }
       
       
       int a1 = (W>=wt[n-1])?val[n-1]+solve(W-wt[n-1],wt,val,n-1,dp):0;
       int a2 = solve(W,wt,val,n-1,dp);
       
       return dp[n][W]=max(a1,a2); 
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       
       return solve(W,wt,val,n,dp);
    }
};
