#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI acos(-1.0)
#define MX 1000006
#define MOD 1000000007

vector<ll>prime;
#define pb push_back

map<ll,ll>mp;
#define ff first
#define ss second


/* in n! how many p's are available */

ll counter(ll n, ll p)
{
    ll c=0;

    while(n){
        c += n/p;
        n /= p;
    }
    return c;
}


/* in n how many p's are available */

ll cnt(ll n, ll p)
{
    ll c = 0;
    while(n%p==0){
        c++;
        n /= p;
    }
    return c;
}

int main()
{

    ll n;

    cout<<counter(40,5)<<endl;
    cout<<cnt(40,5)<<endl;

    return 0;
}
