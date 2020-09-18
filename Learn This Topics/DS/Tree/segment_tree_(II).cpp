

/// minimum value with index, between i to j

#include<bits/stdc++.h>
using namespace std;

#define sz 1000006
int n,a[sz];

struct info
{
    int val;
    int idx;

    info(){
        val = 0 , idx = 0;
    }
} tree[sz*4];

void init(int node,int b,int e)
{
    if( b == e ){
        tree[node].val = a[b];
        tree[node].idx = b;
        return;
    }

    int mid = (b+e)/2;
    int Left = node*2;
    int Right = node*2+1;

    init(Left,b,mid);
    init(Right,mid+1,e);

    tree[node].val = tree[Left].val < tree[Right].val  ? tree[Left].val : tree[Right].val;
    tree[node].idx = tree[Left].val < tree[Right].val  ? tree[Left].idx : tree[Right].idx;
}


int query(int node,int b,int e,int i,int j)
{
    if( i>e || j<b ) return 0;
    else if( b >= i && e <= j )
        return tree[node].idx;

    int mid = (b+e)/2;
    int Left = node*2;
    int Right = node*2 + 1;

    int idxL = query(Left,b,mid,i,j);
    int idxR = query(Right,mid+1,e,i,j);

    int minidx = a[idxL] < a[idxR] ? idxL : idxR;

    return minidx;
}


int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);

    init(1,1,n);

    a[0] = INT_MAX;

    cout<<query(1,1,n,1,4)<<endl;

    return 0;

}
