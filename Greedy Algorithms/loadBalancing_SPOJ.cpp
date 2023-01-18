#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
	while (1) {
		ll n;
		cin >> n;

		if (n == -1) {
			break;
		}

		vector<ll>arr(n);
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		if (sum % n != 0) {
			cout << "-1" << endl;
		}
		else {
			ll b = sum / n;

			ll ans = INT_MIN, diff = 0;
			for (ll i = 0; i < n - 1; i++) {
				diff += (arr[i] - b);
				ll t = max(diff, -diff);
				ans = max(ans, t);
			}

			cout << ans << endl;
		}
	}

	return 0;
}

