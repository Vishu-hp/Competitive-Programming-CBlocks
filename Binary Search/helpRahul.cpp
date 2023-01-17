// Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array.
// Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int key){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==key){
			return mid;
		}
		else if(arr[s]<=arr[mid]){
			if(arr[s]<=key && key<=arr[mid]){
				e=mid-1;
			}
			else{
				s=mid+1;
			}
		}
		else if(arr[mid]<=arr[e]){
			if(key>=arr[mid] && key<=arr[e]){
				s=mid+1;
			}
			else{
				e=mid-1;
			}
		}
	}
	return -1;
}

int main() {
	int n;
	cin>>n;

	int arr[10000];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int key;
	cin>>key;

	cout<<solve(arr,n,key)<<endl;
	return 0;
}
