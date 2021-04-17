#include<bits/stdc++.h>
using namespace std;

#define sz 1000005
int a[sz];
int tree[sz*4];

void init(int node,int b,int e)
{
    if( b == e ){
        tree[node] = a[b];
        return;
    }

    int mid = (b+e)/2;

    int Left = node*2;
    int Right = node*2+1;
    init(Left,b,mid);
    init(Right,mid+1,e);

    tree[node]=tree[Left]+tree[Right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return 0;  /// range minimum er jonno return INT_MAX.
    else if( b >= i && e <= j ) return tree[node];
    int mid=(b+e)/2;
    int Left = node*2;
    int Right = node*2+1;

    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);

    return p1+p2;
}

void update(int node,int b,int e,int i,int newval)
{
    if( i>e || i<b ) return;
    else if( b >= i && e <= i ){   /// (b == e) leaf node update hbe
        tree[node]=newval;
        return;
    }

    int mid=(b+e)/2;
    int Left = node*2;
    int Right = node*2+1;

    update(Left,b,mid,i,newval);
    update(Right,mid+1,e,i,newval);

    tree[node]=tree[Left]+tree[Right];
}

int main()
{
    int n,q,i,j;
    cin>>n;

    for(i=1; i<=n; i++)
        cin>>a[i];

    init(1,1,n);

    cout<<query(1,1,n,2,6)<<endl;

    update(1,1,n,3,10);

    cout<<query(1,1,n,2,4);

}
