class Solution{
public:
    vector<vector<int>>ans;

    bool isSafe(vector<vector<int>>&g,int r,int c){
        
        for(int i=r-1;i>=0;i--){
            if(g[i][c]==1){
                return false;
            }
        }
        
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(g[i][j]==1){
                return false;
            }
        }
        
        for(int i=r-1,j=c+1;i>=0 && j<g.size();i--,j++){
            if(g[i][j]==1){
                return false;
            }
        }
        return true;
    }

    void solve(vector<vector<int>>&g,int r,vector<int>&tmp){
        if(r==g.size()){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=0;i<g.size();i++){
            if(r==0 || isSafe(g,r,i)){
                g[r][i] = 1;
                tmp.push_back(i+1);
                solve(g,r+1,tmp);
                g[r][i]=0;
                tmp.pop_back();
            }
        }
        return ;
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<int>>g(n,vector<int>(n,0));
        vector<int>tmp;
        
        solve(g,0,tmp);
        
        return ans;
    }
};
