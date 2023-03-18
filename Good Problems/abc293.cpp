// https://atcoder.jp/contests/abc293/tasks/abc293_c

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


// vector<int>dp(1000001);

ll solve(vector<vector<ll>>&grid,ll r,ll c,unordered_set<ll>ust,ll cnt){
    if(r>=grid.size() || c>=grid[0].size()){
        return 0;
    }

    ust.insert(grid[r][c]);

    if(ust.size() != (r+c+1)){
        return 0;
    }

    if(r ==grid.size()-1 && c==grid[0].size()-1){
        return 1;
    }

    ll f1 = solve(grid,r+1,c,ust,cnt+1);
    ll f2 = solve(grid,r,c+1,ust,cnt+1);
    // ust.pop();

    return f1+f2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    ll h,w;
    cin>>h>>w;

    vector<vector<ll>>grid(h,vector<ll>(w));
    rep(i,0,h){
        rep(j,0,w){
            cin>>grid[i][j];
        }
    }

    unordered_set<ll>ust;
    ll ans=solve(grid,0,0,ust,0);
    cout<<ans<<endl;

    return 0;
}
