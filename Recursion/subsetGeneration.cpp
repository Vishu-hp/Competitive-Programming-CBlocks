// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.


class Solution{
	public:
	    
	    vector<string> solve(string s){
	        if(s.length()==0){
		        vector<string>t;
		        t.push_back("");
		        return t;
		    }
		    
		    char tmp = s[0];
		    string ros = s.substr(1);
            vector<string>f = solve(ros);
            
            vector<string>ans;
            for(auto x:f){
                ans.push_back(tmp+x);
            }
            
            for(auto x:f){
                ans.push_back(x);
            }
           
            
            return ans;
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans = solve(s);

            sort(ans.begin(),ans.end());
            ans.erase(ans.begin());
    
		    return ans;
		}
};
