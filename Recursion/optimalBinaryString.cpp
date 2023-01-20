// Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 10^9 + 7.


class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    
	    int dp1[n+1];
	    int dp2[n+1];
	    
	    dp1[1]=1;
	    dp2[1]=1;
	    
	    for(int i=2;i<=n;i++){
	        dp1[i] = (dp1[i-1]+dp2[i-1])%1000000007;
	        dp2[i] = dp1[i-1];
	    }
	    
	    return (dp1[n]+dp2[n])%1000000007;
	}
};
