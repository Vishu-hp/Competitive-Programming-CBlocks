#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
	ll n, d;
	cin >> n >> d;

	ll arr[100001];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	ll ans = 0;
	for (ll i = 0; i < n - 1;) {
		if (arr[i + 1] - arr[i] <= d) {
			ans++;
			i += 2;
		}
		else {
			i++;
		}
	}
	cout << ans << endl;

}
