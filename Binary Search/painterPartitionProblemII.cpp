// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers.
// He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. // The problem is to find the minimum time to get this job
// done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4}
// or only board {1} or nothing but not boards {2,4,5}.



#include <bits/stdc++.h>
using namespace std;

bool isPoss(vector<int>&b, int k, int n, int pa) {
	int p = 1;
	int c = 0;

	for (int i = 0; i < n; i++) {
		if (c + b[i] <= pa) {
			c += b[i];
		}
		else {
			c = b[i];
			p++;

			if (p > k) {
				return false;
			}
		}
	}
	return true;
}

int solve(vector<int>&b, int k, int n) {
	int s = INT_MIN;
	int e = 0;

	for (int i = 0; i < n; i++) {
		s = max(s, b[i]);
		e += b[i];
	}


	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (isPoss(b, k, n, mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	int k;
	int n;
	cin >> k >> n;

	vector<int>b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << solve(b, k, n) << endl;

	return 0;
}
