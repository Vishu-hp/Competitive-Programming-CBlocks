#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
	ll t, w, h, n, x, y ;
	cin >> t;

	ll xc[40010];
	ll yc[40010];
	while (t--)
	{
		cin >> w >> h >> n;

		for (ll i = 0; i < n; i++) {
			cin >> xc[i] >> yc[i];
		}


		sort(xc, xc + n);
		sort(yc, yc + n);

		ll dx = xc[0] - 0 - 1;
		ll dy = yc[0] - 0 - 1;
		for (ll i = 1; i < n; i++) {
			dx = max(dx, xc[i] - xc[i - 1] - 1);
			dy = max(dy, yc[i] - yc[i - 1] - 1);
		}

		dx = max(dx, w + 1 - xc[n - 1] - 1);
		dy = max(dy, h + 1 - yc[n - 1] - 1);
		cout << dx*dy << endl;

	}


}
