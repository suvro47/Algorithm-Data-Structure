
/*
    Lecture : 17 (last part) + 18 (first part)
    LOJ : 1117
    How many numbers have up to n that are not divisible by some given numbers a1,a2...an
    n <= 2^31 and m <= 20
    set + bitmask( to generate the subset )
*/

#include<bits/stdc++.h>
using namespace std;

#define sz 50000
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define INF 10000007
#define LLINF 100000000000000007

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;

int CheckBit(int val,int pos) {return val & (1<<pos);}
ll LCM(ll a,ll b) {return a*b/__gcd(a,b);}

int main()
{
    int T,tc=1;
    scanf("%d",&T);

    while(T--){
        ll n,m;
        scanf("%lld %lld",&n,&m);

        ll a[m+5];
        for(int i=0; i<m; i++) scanf("%lld",&a[i]);

        int sset = 1 << m;
        ll ans = 0;

        for(int mask=1; mask < sset ; mask++){
            ll L = 1;
            ll cnt = 0;

            for(int i=0; i<m; i++){
                if( CheckBit(mask,i)) {
                    L = LCM(L,a[i]);
                    cnt++;
                }
            }

            if( cnt&1 ) ans += n/L;
            else ans -= n/L;
        }
        ans = n - ans;
        printf("Case %d: %lld\n",tc++,ans);
    }

    return 0;
}
