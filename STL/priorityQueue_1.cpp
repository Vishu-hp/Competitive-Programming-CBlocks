#include <iostream>
#include<queue>

using namespace std;
int main() {
    int n;
    cin>>n;

    priority_queue<int>pq_max; //Max Prioity Queue
    priority_queue<int,vector<int>,greater<int>>pq_min; // Min Priority Queue

    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        pq_max.push(no);
        pq_min.push(no); // O(LogN)
    }

    // Remove the elements from the heap
    while(!pq_max.empty()){
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }
    cout<<endl;

    while(!pq_min.empty()){
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    cout<<endl;

    return 0;
}
