class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int>adj[],int V,vector<int>&ans,vector<bool>&vis,int s){
	    vis[s]=true;
	    
	    for(auto x:adj[s]){
	        if(vis[x]==false){
	            dfs(adj,V,ans,vis,x);
	        }
	    }
	    
	    ans.push_back(s);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<bool>vis(V,false);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==false){
	            dfs(adj,V,ans,vis,i);        
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};
