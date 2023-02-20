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

int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	
	int dp[101] = {0};
	
	cout<<ladders_topdown(n,k,dp)<<endl;
	
	
	return 0;
}
