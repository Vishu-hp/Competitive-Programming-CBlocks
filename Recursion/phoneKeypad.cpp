// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


class Solution {
public:

     void solve(string digits,int N,int pos,string tmp,unordered_map<char,vector<char>>&ump,vector<string>&ans){
        
        if(pos==N){
            ans.push_back(tmp);
            return ;
        }
        
        char num = digits[pos];
        
        for(int i=0;i<ump[num].size();i++){
            solve(digits,N,pos+1,tmp+ump[num][i],ump,ans);
        }
        return ;
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0){
            return ans;
        }
        unordered_map<char,vector<char>>ump;
        ump['2'] = {'a','b','c'};
        ump['3'] = {'d','e','f'};
        ump['4'] = {'g','h','i'};
        ump['5'] = {'j','k','l'};
        ump['6'] = {'m','n','o'};
        ump['7'] = {'p','q','r','s'};
        ump['8'] = {'t','u','v'};
        ump['9'] = {'w','x','y','z'};
        
        solve(digits,digits.length(),0,"",ump,ans);
        return ans;
    }
};
