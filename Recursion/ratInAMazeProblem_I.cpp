// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1).
// Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move
// are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it
// while value 1 at a cell in the matrix represents that rat can be travel through it.



class Solution{
    public:
    void solve(vector<vector<int>>&m,int x,int y,vector<vector<bool>>&vis,string psf,vector<string>&ans){
        if(x<0 || y<0 || x>=m.size() || y>=m.size() || m[x][y]==0 || vis[x][y]){
            return;
        }
        
        if(x==m.size()-1 && y==m.size()-1){
            ans.push_back(psf);
            return;
        }
        
        
        vis[x][y] = true;
        
        solve(m,x-1,y,vis,psf+"U",ans);
        solve(m,x+1,y,vis,psf+"D",ans);
        solve(m,x,y+1,vis,psf+"R",ans);
        solve(m,x,y-1,vis,psf+"L",ans);
        
        vis[x][y] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        solve(m,0,0,vis,"",ans);
        return ans;
    }
};
