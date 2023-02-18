#include <bits/stdc++.h>
using namespace std;

int solve(int price[], int l,int r, int y,int dp[][100]) {
	if(l>r){
		return 0;
	}

	if (dp[l][r] != 0){
		return dp[l][r];
	}

	int op1 = price[l] * y + solve(price,l+1, r, y+1,dp);
	int op2 = price[r] * y + solve(price,l,r-1, y+1,dp);

	int ans = max(op1, op2);
	dp[l][r] = ans;
	return ans;
}


int maxProfit(int price[], int n) {
	int dp[100][100] = {0};
	int y=1;
	int ans = solve(price, 0, n - 1, y,dp);

	return ans;
}

int main() {
	int price[] = { 2, 4, 6, 2, 5 };

	int n = sizeof(price) / sizeof(price[0]);

	int ans = maxProfit(price, n);

	cout << ans << endl;

	return 0;
}
