class Solution{

	public:
	
	int minCoins_(int coins[],int M,int V,int dp[]){
	    if(V==0){
	        return 0;
	    }
	    
	    if(dp[V]!=0){
	        return dp[V];
	    }
	    
	    int mV=INT_MAX;
	    for(int i=0;i<M;i++){
	        if(V>=coins[i]){
	            int subP = minCoins_(coins,M,V-coins[i],dp);
	        
	            if(subP != INT_MAX){
	                mV = min(mV,subP+1);
    	        }
	        }
	    }
	    
	   dp[V] = mV;
	    return mV;
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[1000001] = {0};
	  
	    int ans= minCoins_(coins,M,V,dp);
	    if(dp[V] == INT_MAX){
	       return -1;
	    }
	    return dp[V];
	} 
	  
};
