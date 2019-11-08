#include<bits/stdc++.h>
using namespace std;

#define sz 100005
typedef long long ll;

ll a[sz];
ll tree[sz*4],prop[sz*4];

void init(int node,int b,int e)
{
    if( b == e ){
        tree[node] = a[b];
        return;
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = node*2+1;

    init(L,b,mid);
    init(R,mid+1,e);

    tree[node] = tree[L]+tree[R];
}

void pushdown(int node,int b,int e)
{
    if( !prop[node] || b >= e ) return;

    int mid = (b+e)/2;
    int L = node*2;
    int R = node*2+1;

    tree[L] += (mid-b+1)*prop[node];
    prop[L] += prop[node];

    tree[R] += (e-mid)*prop[node];
    prop[R] += prop[node];

    prop[node] = 0;
}

void update(int node,int b,int e,int i,int j,ll x)
{
    pushdown(node,b,e);

    if( i>e || j<b ) return;
    else if( b>=i && e<=j ){
        tree[node] += (e-b+1)*x;
        prop[node] += x;
        return;
    }

    int mid = (b+e)/2;
    int L = node*2;
    int R = node*2+1;

    update(L,b,mid,i,j,x);
    update(R,mid+1,e,i,j,x);

    tree[node] = tree[L] + tree[R];
}

ll query(int node, int b,int e,int i,int j)
{
    pushdown(node,b,e);

    if( i>e || j<b ) return 0;
    else if( b>=i && e<=j )
        return tree[node];

    int mid = (b+e)/2;
    int L = node*2;
    int R = node*2+1;

    ll q1 = query(L,b,mid,i,j);
    ll q2 = query(R,mid+1,e,i,j);

    return q1+q2;
}

int main()
{
    int t,tc=1;
    scanf("%d",&t);

    while( t-- ){
        int n,q;
        scanf("%d %d",&n,&q);
        memset(tree,0,sizeof tree);
        memset(prop,0,sizeof prop);

        printf("Case %d:\n",tc++);

        while(q--){
            int i,j,qt;
            ll x;
            scanf("%d",&qt);

            if( qt == 0 ){
                scanf("%d %d %lld",&i,&j,&x);
                update(1,1,n,i+1,j+1,x);
            }
            else{
                scanf("%d %d",&i,&j);
                ll res = query(1,1,n,i+1,j+1);
                printf("%lld\n",res);
            }

        }
    }

    return 0;

}

