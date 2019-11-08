/*
C++ program to find modular inverse of a under modulo m
This program works only if m is prime.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI acos(-1.0)
#define MX 1000005
#define MOD 1000000007

ll bigMod(ll x,ll n,ll M)
{
    if(n==0) return 1;
    else if(n%2==0){
       ll y=bigMod(x,n/2,M);
       return (y*y)%M;
    }
    else return ( (x%M) * bigMod(x,n-1,M) )%M;
}

ll modInverse(ll b,ll m)
{
    return bigMod(b,m-2,m); /// just to find out b inverse M
}

/* Find  (a/b) % M */

int main()
{
    ll a,b;
    cin>>a>>b;
    ll b_inv = modInverse(b,MOD);
    cout<<b_inv<<endl;
    ll ans = ( (a%MOD) *(b_inv) ) % MOD;

    cout<<ans<<endl;



    return 0;
}
