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
 
class Edge{
    public:
    ll src,nbr;
 
    Edge(ll src,ll nbr){
        this->src=src;
        this->nbr=nbr;
    }
};
 
void dfs(vector<Edge>g[],ll s,vector<bool>&vis,vector<ll>&comp){
    vis[s]=true;
    comp.push_back(s);
 
    for(auto x:g[s]){
        if(vis[x.nbr]==false){
            dfs(g,x.nbr,vis,comp);
        }
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,m;
    cin>>n>>m;
 
    vector<Edge>g[n+1];
 
    rep(i,1,m+1){
        ll s,d;
        cin>>s>>d;
 
        g[s].push_back(Edge(s,d));
        g[d].push_back(Edge(d,s));
    }
 
    vector<vector<ll>>comps;
 
    vector<bool>vis(n+1,false);
 
    rep(i,1,n+1){
        if(vis[i]==false){
            vector<ll>comp;
            dfs(g,i,vis,comp);
            comps.push_back(comp);
        }
    }
 
    ll ans = comps.size()-1;
    cout<<ans<<endl;
 
    ll a = comps[0][0];
    rep(i,1,comps.size()){
        ll b = comps[i][0];
        cout<<a<<" "<<b<<endl;
    }
 
    return 0;
}
