// https://hack.codingblocks.com/app/contests/1310/546/problem
// --------------------------------------------------------------
// There's a scientist named Brook who is interested in budding of cells. He has one container which initially contains only a single cell. Now Brook wants n number of cells in his container. So he can change the number of cells in container in 3 different ways -:

// 1 Double the number of cells present in the container.
// 2 Increase the number of cells in the container by 1.
// 3 Decrease the number of cells in the container by 1.

// Now, all the above operations have different costs associated with them x,y,z respectively for above operations. Help brook in finding the minimum cost to generate n cells in the container starting from one cell .

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,x,y,z;
	cin>>n>>x>>y>>z;

	int dp[n+1];
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		int ans=INT_MAX;
		if(i%2==0){
			ans = min(ans,dp[i/2]+x);
		}
		
		ans=min(ans,dp[i-1]+y);
		if(i%2!=0 && i+1<=n){
			ans=min(ans,dp[(i+1)/2]+x+z);
		}
		dp[i]=ans;
	}

	cout<<dp[n]<<endl;
	return 0;
}
