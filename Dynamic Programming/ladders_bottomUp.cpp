#include <iostream>
using namespace std;

int ladders_topdown(int n,int k,int dp[]){
	if(n==0){
		return 1;
	}
	
	if(dp[n] != 0){
		return dp[n];
	}
	
	int ans=0;
	for(int i=1;i<=k;i++){
		if(n-i>=0){
			ans += ladders_topdown(n-i,k,dp);
		}
	}

	dp[n] = ans;	
	return ans;
}


int ladders_bottomUp(int n,int k){
	if(n==0){
		return 1;
	}
	
	int dp[101] = {0};
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i] = 0;
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				dp[i] += dp[i-j];
			}
		}
	}
	return dp[n];
}


int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;

	cout<<ladders_bottomUp(n,k)<<endl;
	
	return 0;
}
