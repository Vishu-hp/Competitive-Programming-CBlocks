
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


ll n, m, s, d, sv, ev;
vector<ll>g[100001];
vector<bool>vis;
vector<ll>par;

bool dfs(ll v, ll p) {
    vis[v] = true;
    par[v] = p;

    for (auto x : g[v]) {
        if (x == p) {
            continue;
        }

        if (vis[x] == true) {
            sv = x;
            ev = v;
            return true;
        }

        if (vis[x] == false) {
            if (dfs(x, v)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vis.resize(n + 1);
    par.resize(n + 1);

    rep(i, 1, n + 1) {
        vis[i] = false;
        par[i] = -1;
    }


    rep(i, 1, m + 1) {
        cin >> s >> d;

        g[s].push_back(d);
        g[d].push_back(s);
    }


    bool flag = false;

    rep(i, 1, n + 1) {
        if (vis[i] == false) {
            if (dfs(i, -1)) {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        vector<ll>ans;
        ans.push_back(sv);
        while (ev != sv) {
            ans.push_back(ev);
            ev = par[ev];
        }
        ans.push_back(sv);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        rep(i, 0, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
