#include <iostream>
#include<vector>
using namespace std;

int main() {
  
    // You can create and initialise a vector
    vector<int>a;
    vector<int>b(5,10) ; // five int with value 10
    vector<int>c(b.begin(),b.end()); //copying a vector to other
    vector<int>d{1,2,3,10,14};

    // Look at how we can iterate over vector
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<",";
    }
    cout<<endl;

    for(auto it=b.begin();it!=b.end();it++){
        cout<<(*it)<<",";
    }
    cout<<endl;

    // For each loop
    for(int x:d){
        cout<<x<<",";
    }
    cout<<endl;


    // Discuss more functions
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        v.push_back(no);
    }

    for(int x:v){
        cout<<x<<",";
    }
    cout<<endl;



    //Understand at memory level, what are difference bw vector d and v
    cout<<v.size()<<endl; // Size of vector
    cout<<v.capacity()<<endl;//size of underlying array
    cout<<v.max_size()<<endl;//max num of elements a vector can hold in worst case acc to system memory


    cout<<d.size()<<endl; // Size of vector
    cout<<d.capacity()<<endl;//size of underlying array
    cout<<d.max_size()<<endl;//max num of elements a vector can hold in worst case acc to system memory

   return 0;
}
