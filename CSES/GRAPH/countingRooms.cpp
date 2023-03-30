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
 
bool prime[1000000];
 
void seive()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=1000000;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<=1000000;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}
 
void dfs(vector<vector<char>>&grid,ll r,ll c){
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]=='#'){
        return;
    }
    
    grid[r][c]= '#';
 
    dfs(grid,r-1,c);
    dfs(grid,r,c+1);
    dfs(grid,r+1,c);
    dfs(grid,r,c-1);
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,m;
    cin>>n>>m;
 
    vector<vector<char>>grid(n,vector<char>(m));
 
    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
        }
    }
 
 
    ll ans=0;
    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j] == '.'){
                dfs(grid,i,j);
                ans++;
            }
        }
    }
 
    cout<<ans<<endl;
 
    return 0;
}
