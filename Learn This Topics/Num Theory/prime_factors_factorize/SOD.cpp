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

ll n,m,x,y,i,j,k,c,t,status[MX]={0};

void siv()
{
    ll LIM=sqrt(MX);

    for(i=3; i<=LIM; i+=2){
        if(status[i]==0){
            for(j=i*i; j<=MX; j+=2*i)
                status[j]=1;
        }
    }

    prime.pb(2);
    for(i=3;i<=MX;i+=2){
        if(!status[i]) prime.pb(i);
    }
}

void factorize(int x)
{
    for(i=0; (prime[i]*prime[i]) <= x && i <prime.size() ; i++){
        if(x%prime[i]==0){
            while(x%prime[i]==0){
                x/=prime[i];
                mp[prime[i]]++;
            }
        }
    }
    if(x!=1) mp[x]++;
}

ll power(ll b,ll p)
{
    ll rs=1;
    for(ll k=1;k<=p;k++)
        rs*=b;
    return rs;
}

int main()
{
    siv();

    cin>>n;

    factorize(n);

    ll ans = 1;

    for(auto i:mp){
        ll p = i.ff;
        ll a = i.ss;

        ans *= ( (power(p,a+1) - 1) / (p-1) ) ;
    }

    cout<<ans<<endl;

    mp.clear();


    return 0;

}
