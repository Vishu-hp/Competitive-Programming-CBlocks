#include <iostream>
using namespace std;

int lazy[10000] = {0};

void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index){
    // before going down resolve the value if it exists
    if(lazy[index] != 0){
        tree[index] += lazy[index];

        // non leaf node
        if(ss != se){
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }
        lazy[index] = 0; // clear the lazy value at current node
    }

    // Base Case
    // no overlap
    if(ss>r || se<l){
        return;
    }

    // complete overlap
    if(ss>=l && se<=r){
        tree[index] += inc;

        // create a new lazy value of children node
        if(ss != se){
            lazy[2*index] += inc;
            lazy[2*index + 1] += inc;
        }
        return;
    }

    // recursive case - partial overlap
    int mid = (ss + se)/2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2*index);
    updateRangeLazy(tree, mid+1, se, l, r, inc, 2*index + 1);
    // update the tree[index]
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}

void buildTree(int *a,int s,int e,int *tree,int index){
    if(s==e){
        tree[index] = a[s];
        return;
    }

    // Recursve Case
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int main() {
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);

    int *tree = new int[4*n+1];
    buildTree(a,0,n-1,tree,1);

    // update node


    return 0;
}
