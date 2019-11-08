#include<bits/stdc++.h>
using namespace std;

#define sz 1000006
#define ERROR 1e-9
#define PI acos(-1.0)
#define INF 10000007
#define LLINF 100000000000000007

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long ll;

ll n,a[sz];
ll tree[sz],prop[sz];

void update(int node,int b,int e,int i,int j,ll x)
{
    if( i>e || j<b ) return;
    else if( b >= i && e<=j ){
        tree[node] += (e-b+1)*x;
        prop[node] += x;
        return;
    }

    int mid = (b+e)/2;

    int L = node*2;
    int R = node*2+1;

    update(L,b,mid,i,j,x);
    update(R,mid+1,e,i,j,x);

    tree[node] = tree[L]+tree[R]+(e-b+1)*prop[node];  /// etipurbe jodi update hoye thake tahole oii part tao (e-b+1)*prop[node] diye add kore dite hbe
}


ll query(int node,int b,int e,int i,int j,ll carry)
{
    if( i>e || j<b ) return 0;
    else if(  b >= i && e <= j )
        return tree[node] + carry*(e-b+1);

    int mid = (b+e)/2;

    int L = node*2;
    int R = node*2+1;

    ll q1 = query(L,b,mid,i,j, carry+prop[node] );
    ll q2 = query(R,mid+1,e,i,j, carry+prop[node]);

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
                ll res = query(1,1,n,i+1,j+1,0);
                printf("%lld\n",res);
            }

        }
    }

    return 0;

}

