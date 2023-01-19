#include <bits/stdc++.h>
using namespace std;
#define ll long long int


bool comp(pair<ll, ll>&p1, pair<ll, ll>&p2) {
	return p1.first > p2.first;
}

int main()
{
	ll t, d, f, l, p, n, x, prev  ;
	cin >> t;

	while (t--)
	{
		cin >> n;

		int flag = 0;
		vector<pair<ll, ll>>v;
		priority_queue<ll>pq;
		for (ll i = 0; i < n; i++) {
			cin >> d >> f;
			v.push_back(make_pair(d, f));
		}

		cin >> l >> p;

		sort(v.begin(), v.end(), comp);

		for (ll i = 0; i < n; i++) {
			v[i].first = l - v[i].first;
		}

		ll ans = 0;
		x = 0;
		prev = 0;
		while (x < n) {
			if (p >= (v[x].first - prev)) {
				p -= (v[x].first - prev);
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else {
				if (pq.empty()) {
					flag = 1;
					break;
				}

				p += pq.top();
				pq.pop();
				ans++;
				continue;
			}
			x++;
		}

		if (flag) {
			cout << "-1" << endl;
			continue;
		}

		l = l - v[n - 1].first;

		if (p >= l) {
			cout << ans << endl;
			continue;
		}

		// otherwise
		while (p < l) {
			if (pq.empty()) {
				flag = 1;
				break;
			}

			p += pq.top();
			pq.pop();
			ans++;
		}

		if (flag) {
			cout << -1 << endl;
			continue;
		}

		cout << ans << endl;

	}


}
