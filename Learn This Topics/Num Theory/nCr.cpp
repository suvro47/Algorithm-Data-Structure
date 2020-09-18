#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long  ll;

ll nCk(ll n,ll k)
{
    vector<ll>v1,v2;
    ll i , j , d;
    for(i=k+1; i<=n; i++) v1.pb(i);
    for(i=2; i<=n-k; i++) v2.pb(i);

    for(i=0; i<v2.size(); i++){
        for(j=0; j<v1.size() && v2[i] > 1 ; j++){
            d = __gcd(v2[i],v1[j]);
            v2[i] /= d;
            v1[j] /= d;
        }
    }

    ll ans = 1;

    for(i=0; i<v1.size(); i++) ans *= v1[i];

    return ans;
}

int main()
{

    ll n,k,res;
    scanf("%lld %lld",&n,&k);
    /// k > n handle korte hbe..
    res = nCk(n,k);
    printf("%lld",res);


    return 0;
}

