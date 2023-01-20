// There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time.
// Count the number of ways, the person can reach the top (order does not matter).


class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    if(n<=1){
		        return 1;
		    }
		    
		  int a = (n>=2)?nthStair(n-2):0;
		  return a+1;
		}
};
