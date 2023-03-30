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
#define mod 1000000007

ll n, m;
vector<vector<char>>g;
vector<vector<bool>>vis;
vector<vector<pair<ll, ll>>>path;
ll sx, sy, dx, dy;

vector<pair<ll, ll>>moves = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(ll x, ll y) {
    if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#' || vis[x][y] == true) {
        return false;
    }
    return true;
}

void bfs() {
    queue<pair<ll, ll>>q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty()) {
        pair<ll, ll>rem = q.front();
        q.pop();

        ll x = rem.first;
        ll y = rem.second;


        for (auto mv : moves) {
            ll nx = x + mv.first;
            ll ny = y + mv.second;

            if (isValid(nx, ny)) {
                q.push({nx, ny});
                vis[nx][ny] = true;
                path[nx][ny] = mv;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    path.resize(n);

    rep(i, 0, n) {
        g[i].resize(m);
        path[i].resize(m);
        vis[i].resize(m);
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            else if (g[i][j] == 'B') {
                dx = i;
                dy = j;
            }
        }
    }

    bfs();

    if (vis[dx][dy] == false) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    vector<pair<ll, ll>>ans;
    pair<ll, ll>end = {dx, dy};

    while (end.first != sx || end.second != sy) {
        ans.push_back(path[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;

    for (auto c : ans)
    {
        if (c.first == 1 and c.second == 0)
        {
            cout << 'D';
        }
        else if (c.first == -1 and c.second == 0)
        {
            cout << 'U';
        }
        else if (c.first == 0 and c.second == 1)
        {
            cout << 'R';
        }
        else if (c.first == 0 and c.second == -1)
        {
            cout << 'L';
        }
    }

    return 0;
}
