
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

class Pair {
public:
    ll v, wsf;

    Pair() {}

    Pair(ll a, ll b) {
        v = a;
        wsf = b;
    }
};

vector<vector<ll>>g[100001];
vector<ll>dis;
vector<ll>tmp;
ll s, d, w, n, m;

bool operator<(const Pair &p1, const Pair &p2) {
    return p1.wsf > p2.wsf;
}

void dijkstra() {
    priority_queue<Pair>pq;
    pq.push(Pair(1, 0));

    while (pq.size() > 0) {
        Pair rem = pq.top();
        pq.pop();

        if (dis[rem.v] != -1) {
            continue;
        }

        dis[rem.v] = rem.wsf;

        for (auto x : g[rem.v]) {
            if (dis[x[0]] == -1) {
                pq.push(Pair(x[0], rem.wsf + x[1]));
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
        dis[i] = -1;
    }


    rep(i, 1, m + 1) {
        cin >> s >> d >> w;
        tmp.push_back(d);
        tmp.push_back(w);
        g[s].push_back(tmp);
        tmp.clear();
    }


    dijkstra();

    rep(i, 1, n + 1) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}
