class Solution{

	public:
	
	int minSteps_(int N,int dp[]){
	    if(N==1){
	        return 0;
	    }
	    
	    if(dp[N]!=0){
	        return dp[N];
	    }
	    
	    int op1,op2,op3;
	    op1= op2 = op3 = INT_MAX;
	    
	    if(N%3 == 0){
	        op1 = minSteps_(N/3,dp)+1;
	    }
	    
	    if(N%2 == 0){
	        op2 = minSteps_(N/2,dp)+1;
	    }
	    
	    op3 = minSteps_(N-1,dp) + 1;
	    
	    int ans = min(op1,min(op2,op3));
	    return dp[N] =ans;
	}
	
	int minSteps(int N) 
	{ 
	    // Your code goes here
	    int dp[10001] = {0};
	    return minSteps_(N,dp);
	} 
};
