// You are given N number of books. Every ith book has Ai number of pages. 
// You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, 
// one of the M students will be allocated the maximum number of pages. Out of all these permutations,
// the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations
// and print this minimum value.
// Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPoss(int arr[],int m,int pa,int n){
    int s=1;
    int p=0;
    for(int i=0;i<n;i++){
        if(p+arr[i]<=pa){
            p += arr[i];
        }
        else{
            p = arr[i];
            s++;
            
            if(s>m){
                return false;
            }
        }
    }
    return true;
}
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n){
            return -1;
        }
        int s=arr[0];
    int e=arr[0];
    for(int i=1;i<n;i++){
        e += arr[i];
        s = max(s,arr[i]);
    }
    
    int ans=-1;
    while(s<=e){
        int mid = (s+e)/2;
        
        if(isPoss(arr,m,mid,n)){
            ans = mid;
            e = mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
    }
};
