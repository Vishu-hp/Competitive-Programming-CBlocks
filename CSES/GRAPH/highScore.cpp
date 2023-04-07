
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
const ll ninf = -1e17;


vector<vector<ll>>g;
vector<ll>dis;
vector<ll>edge;
ll s, d, w, n, m, q;


void bellmanford() {
    dis[1] = 0;

    rep(itr, 1, n) {
        for (auto x : g) {
            if (dis[x[0]] == inf) {
                continue;
            }

            dis[x[1]] = min(dis[x[1]], dis[x[0]] + x[2]);
            dis[x[1]] = max(dis[x[1]], ninf);
        }
    }

    rep(itr, 1, n) {
        for (auto x : g) {
            if (dis[x[0]] == inf) {
                continue;
            }
            dis[x[1]] = max(dis[x[1]], ninf);
            if (dis[x[1]] > dis[x[0]] + x[2]) {
                dis[x[1]] = ninf;
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dis.resize(n + 1);
    rep(i, 1, n + 1) {
        dis[i] = inf;
    }

    rep(i, 0, m) {
        cin >> s >> d >> w;
        edge.push_back(s);
        edge.push_back(d);
        edge.push_back(-w);
        g.push_back(edge);
        edge.clear();
    }


    bellmanford();

    if (dis[n] == ninf || dis[n] == inf) {
        cout << "-1" << endl;
    }
    else {
        cout << -dis[n] << endl;
    }

    return 0;
}
