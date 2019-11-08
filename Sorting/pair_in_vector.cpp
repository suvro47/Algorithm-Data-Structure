#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;
typedef pair<ll,ll> pii;

vector<pii>v;

ll n,m,x,y,i,j,k,sum;

bool comp(pii a, pii b )
{
    return a.S < b.S;
}

int main()
{
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x>>y;
        v.pb(mk(x,y));
    }

    sort(all(v),comp);

    for(auto i:v)
        cout<<i.F<<' '<<i.S<<endl;
}

/*

/// ascending order by first sort(all(v)) / descending order by first sort(all(v),greater<pii>())

input
6
2 5
2 3
1 2
3 4
1 3
1 1

*/
