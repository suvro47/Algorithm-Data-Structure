#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bigMod(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2==0){
       ll y=bigMod(x,n/2,M);
       return (y*y)%M;
    }
    else return ( (x%M) * bigMod(x,n-1,M) )%M;
}

int main()
{
    ll x,n,M;
    while(scanf("%lld %lld %lld",&x,&n,&M) != EOF){
        cout<<bigMod(x,n,M)<<endl;
    }
    return 0;
}
