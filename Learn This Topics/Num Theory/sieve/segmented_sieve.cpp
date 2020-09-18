#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI acos(-1.0)
#define MX 1000006
#define MOD 1000000007

vector<ll>prime;
#define pb push_back

ll A,B,k,c,t,status[MX],mark[MX];

void siv()
{
    ll LIM=sqrt(MX);

    for(ll i=3; i<=LIM; i+=2){
        if(status[i]==0){
            for(ll j=i*i; j<=MX; j+=2*i)
                status[j]=1;
        }
    }

    prime.pb(2);
    for(ll i=3;i<=MX;i+=2){
        if(!status[i]) prime.pb(i);
    }
}



int main()
{
    siv();

    cin>>A>>B;

    ll sqrtB = sqrt(B);
    if(A==1) A++;

    memset(mark,0,sizeof(mark));

    for(ll i=0; i < prime.size() && prime[i] <= sqrtB ; i++){
        ll p = prime[i];

        ll j = p*p;

        ///If j is smaller than a, then shift it inside of segment [a,b]
        if (j < A) j = (( A + p - 1) / p) * p;

        for ( ; j <= B; j += p )
            mark[j-A] = 1;    ///mark them as not prime


    }


    for (ll k = 0; k+A <= B; k++ ){
            if ( mark[k] == 0 )
                cout<<k+A<<endl;

    }

    return 0;
}
