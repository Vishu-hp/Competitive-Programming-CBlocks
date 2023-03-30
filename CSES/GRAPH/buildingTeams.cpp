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

ll n, m, a, b;
vector<ll>g[100001];
vector<bool>vis;
vector<ll>color;

bool dfs(ll v, ll ccol, ll p) {
    vis[v] = true;
    color[v] = ccol;

    for (auto x : g[v]) {
        if (x == p) {
            continue;
        }

        if (color[x] == -1) {
            if (dfs(x, ccol ^ 3, v) == false) {
                return false;
            }
        }

        if (color[x] == color[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vis.resize(n + 1);
    color.resize(n + 1);

    rep(i, 1, n + 1) {
        vis[i] = false;
        color[i] = -1;
    }

    rep(i, 0, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool flag = true;
    rep(i, 1, n + 1) {
        if (vis[i] == false) {
            if (dfs(i, 1, -1) == false) {
                flag = false;
                break;
            }
        }
    }

    if (flag == false) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        rep(i, 1, n + 1) {
            cout << color[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
