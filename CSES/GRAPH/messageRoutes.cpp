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

ll n,m,a,b;
vector<ll>g[100001];
vector<bool>vis;
vector<ll>par;

void bfs(){
    queue<ll>q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        ll rem = q.front();
        q.pop();

        for(auto x:g[rem]){
            if(vis[x]==false){
                q.push(x);
                vis[x]=true;
                par[x] = rem;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    vis.resize(n+1);
    par.resize(n+1);

    rep(i,0,n+1){
        vis[i]=false;
        par[i]=-1;
    }
    rep(i,0,m){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs();

    if(vis[n]==false){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    ll end = n;
    vector<ll>ans;
    ans.push_back(end);
    while(end!=1){
        end = par[end];
        ans.push_back(end);
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
