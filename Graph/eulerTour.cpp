#include<bits/stdc++.h>
using namespace std;

const int N = 100005 , M = 22;

int tin[N], tout[N], timer;

void euler_tour_1(int cur, int par) {
    cout << cur << " ";
    tin[cur] = timer++;
    for (auto x : gr[cur]) {
        if (x != par) {
            euler_tour_1(x, cur);
            cout << cur << endl;
            tout[cur] = timer++;
        }
    }
    return;
}


void euler_tour_2(int cur, int par) {
    cout << cur << " ";
    tin[cur] = timer++;
    for (auto x : gr[cur]) {
        if (x != par) {
            euler_tour_2(x, cur);
        }
    }
    tout[cur] = timer++;
    cout << cur << endl;
    return;
}


void euler_tour_3(int cur, int par) {
    cout << cur << " ";
    tin[cur] = ++timer;
    for (auto x : gr[cur]) {
        if (x != par) {
            euler_tour_3(x, cur);
        }
    }
    tout[cur] = timer;
    return;
}


// whether x is ancestor of y or not
bool is_ancestor(int x, int y) {
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int main() {
    // timer = 1;
    // euler_tour_1(1, 0);
    // euler_tour_2(1, 0);

    timer = 0;
    euler_tour_3(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << i << " " << tin[i] << " " << tout[i] << endl;
    }
    return 0;
}
