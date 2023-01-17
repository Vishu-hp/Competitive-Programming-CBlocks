// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows.
// You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.

bool isPoss(vector<int>&s,int k,int pa){
    int lc=s[0];
    int c=1;
    for(int i=1;i<s.size();i++){
        if(s[i]-lc>=pa){
            lc = s[i];
            c++;
        }
        if(c==k){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int s=0,e=stalls[n-1]-stalls[0];

        int ans=-1;
        while(s<=e){
            int mid = (s+e)/2;

            if(isPoss(stalls,k,mid)){
                ans = mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
}
