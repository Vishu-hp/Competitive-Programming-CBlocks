// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.



class Solution
{
	public:
	    void solve(string S,string asf,set<string>&ust){
	        if(S.length()==0){
	            ust.insert(asf);
	        }
	        
	        for(int i=0;i<S.length();i++){
		        solve(S.substr(0,i)+S.substr(i+1),asf+S[i],ust);
		    }
		    return;
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    set<string>ust;
		    
		    solve(S,"",ust);
		    
		    for(auto x:ust){
		        ans.push_back(x);
		    }
		    
		    return ans;
		    
		    
		}
};
