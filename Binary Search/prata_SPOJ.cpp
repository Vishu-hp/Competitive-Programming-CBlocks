// IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
// The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. 
// The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes,
// 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in
// the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have
// enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.



#include <bits/stdc++.h>
using namespace std;

bool isPoss(vector<long long>&c, long long n, long long p, long long pa) {
	long long mp = 0;
	for (int i = 0; i < n; i++) {
		long long tmp = c[i];
		long long mp2 = 0;
		long long cnt = 1;
		while (tmp <= pa) {
			mp2++;
			cnt++;
			tmp += (cnt * c[i]);
		}
		mp += mp2;

		if (mp >= p) {
			return true;
		}
	}


	return false;
}

long long solve(vector<long long>&c, long long n, long long p) {
	long long s = 0;
	long long e = INT_MAX;


	for (int i = 0; i < n; i++) {
		e = min(e, c[i] * p * (p + 1) / 2);
	}


	long long ans = -1;
	while (s <= e) {
		long long mid = s + (e - s) / 2;

		if (isPoss(c, n, p, mid)) {
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
	long long t;
	cin >> t;

	while (t--) {
		long long p;
		cin >> p;

		long long n;
		cin >> n;
		vector<long long>c(n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}

		cout << solve(c, n, p) << endl;
	}

	return 0;
}
