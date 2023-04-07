
#include<bits/stdc++.h>

using namespace std;
#define in  long long int n; cin>>n;
#define vn  vector<long long int> v(n)
#define vi for(int i=0;i<n;i++) cin>>v[i];
#define rep(i,a,b) for(ll i = a ; i < b; i++ )
#define rrep(i,b,a) for(ll  i = b - 1 ; i >= a ; i--)
#define ll long long int
#define sor(a) sort(a.begin(),a.end())
#define pb(x) push_back(x)

const ll inf = 1e17;


vector<vector<ll>>g;
ll s, d, w, n, m, q;


void floydWarshal() {

    rep(k, 1, n + 1) {
        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                if (g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            if (g[i][j] == inf) {
                g[i][j] = -1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    g.resize(n + 1);

    rep(i, 1, n + 1) {
        g[i].resize(n + 1);
    }

    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            if (i == j) {
                g[i][j] = 0;
            }
            else {
                g[i][j] = inf;
            }
        }
    }

    rep(i, 1, m + 1) {
        cin >> s >> d >> w;
        g[s][d] = min(g[s][d], w);
        g[d][s] = min(g[d][s], w);
    }


    floydWarshal();

    rep(i, 0, q) {
        cin >> s >> d;
        cout << g[s][d] << endl;
    }
    cout << endl;

    return 0;
}
