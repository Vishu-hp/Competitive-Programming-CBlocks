// Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


class Solution
{
    public:
    vector<string>ans;
    
    void solve(int pos,int n,int opn,int cls,string tmp){
        if(pos==2*n){
            ans.push_back(tmp);
            return;
        }
        
        if(opn<n){
            solve(pos+1,n,opn+1,cls,tmp+"(");
        }
        if(opn>cls){
            solve(pos+1,n,opn,cls+1,tmp+")");
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        solve(0,n,0,0,"");
        return ans;
    }
};
