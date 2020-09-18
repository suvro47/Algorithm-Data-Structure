#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI acos(-1.0)
#define MX 1000005
#define MOD 1000003

ll Fact[MX];

ll bigMod(ll x,ll n,ll M)
{
    if(n==0) return 1;
    else if(n%2==0){
       ll y=bigMod(x,n/2,M);
       return (y*y)%M;
    }
    else return ( (x%M) * bigMod(x,n-1,M) )%M;
}

ll modInverse(ll a,ll m)
{
    return bigMod(a,m-2,m);
}

void factorial()
{
    Fact[0]=1;
    for(int i=1;i<1e6 + 1;i++)
        Fact[i]=(Fact[i-1]*i)%MOD;
}

int main()
{
    int t,T;
    cin>>T;

    factorial();

    for(t=1;t<=T;t++){

        ll n,r,m=1e6+3,a,b,c,ans;

        cin>>n>>r;

        if(r==0) cout<<"Case "<<t<<": "<<1<<endl;

        else{
            a=Fact[n];  /// n!
            b=modInverse(Fact[r],m); /// modulo inverse of r!
            c=modInverse(Fact[n-r],m); /// modulo inverse of (n-r)!

            ans=(a*((b*c)%m))%m;

            cout<<"Case "<<t<<": "<<ans<<endl;
        }
    }

    return 0;
}
