class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[1000001] = {0};
	    
	    dp[0]=0;
	    for(int i=1;i<=V;i++){
	        dp[i] = INT_MAX;
	        for(int j=0;j<M;j++){
	            if(coins[j]<=i){
	                int subP = dp[i-coins[j]];
	                if(subP!=INT_MAX){
	                    dp[i] = min(dp[i],subP+1);
	                }
	            }
	        }
	    }
	    
	    if(dp[V]==INT_MAX){
	        return -1;
	    }
	    
	    return dp[V];
	} 
	  
};
