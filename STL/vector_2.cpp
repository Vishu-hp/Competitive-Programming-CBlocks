#include <iostream>
#include<vector>
using namespace std;

int main() {
 vector<int>d{1,2,3,10,14};

    //  Push Back O(1) for most of time
    d.push_back(16);

    // Pop Back removes the last element O(1)
    d.pop_back();

    // Insert some elements in middle O(N)
    d.insert(d.begin()+3,100); //Inserts 100 at 3rd index
    d.insert(d.begin()+3,3,100);//Insert 3 100s at index 3

    // Erase some element in the middle
    d.erase(d.begin()+2); //erase element at 2nd index
    d.erase(d.begin()+2,d.begin()+5);// erase 3 elements from 2nd index


    // size
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;


    // we avoid doing shrink
    d.resize(18); // if size is increasing then memory will be allocated
    cout<<d.capacity()<<endl;

    // remove all elements of the vector , doesn't delete the memory occupied by array
    d.clear();

    // empty
    if(d.empty()){
        cout<<"This is an empty vector"<<endl;
    }

    cout<<d.size()<<endl;

    for(int x:d){
        cout<<x<<",";
    }
    cout<<endl;

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    cout<<d.front()<<endl; // Front element
    cout<<d.back()<<endl; // Back element


    // Reserve
    int n;
    cin>>n;
    vector<int>v;
    // To avoid doubling , we will use reserve function
    v.reserve(1000);

    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        v.push_back(no);
        cout<<"Changing capacity "<<v.capacity()<<endl;
    }
    cout<<"Capacity "<<v.capacity()<<endl;

    for(int x:v){
        cout<<x<<",";
    }
}
