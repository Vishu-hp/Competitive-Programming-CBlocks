#include <iostream>
using namespace std;


int ladders_bottomUpOptimized(int n,int k){
	if(n==0){
		return 1;
	}
	
	int dp[101] = {0};
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=k;i++){
		dp[i] = 2*dp[i-1];
	}
	
	for(int i=k+1;i<=n;i++){
		dp[i] = 2*dp[i-1] - dp[i-k-1];
	}
	
	return dp[n];
}


int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	
	int dp[101] = {0};
	
	cout<<ladders_bottomUpOptimized(n,k)<<endl;
	
	return 0;
}
