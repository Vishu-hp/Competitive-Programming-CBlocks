class Solution {
  public:
    long long mod = 1000000007;
    
    long long int nthFibonacci(long long int n){
        // code here
        if(n==1 || n==2){
            return 1;
        }
        long long a,b,c;
        a=1,b=1;
        for(long long i=3;i<=n;i++){
            c = (a+b)%mod;
            a=b;
            b=c;
        }
        return c;
    }
};
