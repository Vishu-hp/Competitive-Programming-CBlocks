#include <bits/stdc++.h>
using namespace std;

int main() {
    float x=1.0;
    // x denotes all people having different birthday(complimentary of what we need)
    int people = 0;

    float num = 365;
    float denom = 365;

    float p;
    cin>>p;

    if(p == 1.0){
        cout<<"366"<<endl;
        return 0;
    }

    while(x > 1-p){
        x = x*(num)/denom;
        num--;
        people++;

        cout<<"People "<<people<<" and x "<<x<<endl;
    }

    return 0;
}
