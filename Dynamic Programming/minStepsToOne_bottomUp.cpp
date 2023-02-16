class Solution{

	public:
	
	int minSteps(int N) 
	{ 
	    // Your code goes here
	    int dp[10001] = {0};
        dp[1] = 0;
        for(int i=2;i<=N;i++){
            int op1,op2,op3;
            op1=op2=op3=INT_MAX;
            
            if(i%3==0){
                op1 = dp[i/3]+1;
            }
            
            if(i%2==0){
                op2 = dp[i/2]+1;
            }
            
            op3 = dp[i-1]+1;
            
            dp[i] = min(op1,min(op2,op3));
        }
        return dp[N];
	} 
};
