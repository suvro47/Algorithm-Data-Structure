/* UVa 10061

We know,
log(a*b) = log(a) + log(b)

Therefore
log( n! ) = log(1*2*3....... * n)
    = log(1) + log(2) + ........ +log(n)

Now, observe that the floor value of log base
10 increased by 1, of any number, gives the
number of digits present in that number.

Hence, output would be : floor(log(n!)) + 1.


Number of trailing zero in Different base

as we know in decimal system base is 10
and 10 = 2 x 5 that produce one 0 at the end
so base should be factorize
and according to this factorization to produce one 0
should have at least on pair of base factor elements

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI acos(-1.0)
#define MX 1000006
#define MOD 1000000007

vector<int>prime;
#define pb push_back

map<int,int>mp;
#define ff first
#define ss second

ll status[MX];

void siv()
{
    ll LIM=sqrt(MX);

    for(int i=3; i<=LIM; i++){
        if(status[i]==0){
            for(int j=i*i; j<=MX; j+=2*i)
                status[j]=1;
        }
    }

    prime.pb(2);
    for(int i=3;i<=MX;i+=2){
        if(!status[i]) prime.pb(i);
    }
}

void factorize(int x)
{
    for(int i=0; i<prime.size(); i++){
        if(x%prime[i]==0){
            while(x%prime[i]==0){
                x/=prime[i];
                mp[prime[i]]++;
            }
        }
    }
    if(x!=1) mp[x]++;
}

int counter(int n, int p)
{
    int c=0;

    while(n){
        c += n/p;
        n /= p;
    }
    return c;
}

int main()
{
    siv();

    ll b,n;

    while(cin>>n>>b){

        factorize(b);

        int zeros = INT_MAX;

        for(auto i:mp){
            int cnt = counter(n,i.ff);
            zeros = min(zeros, cnt/i.ss);
        }

        mp.clear();

        double digitos = 0.0;

        for (int i=1; i<=n; i++)
            digitos += log10(i) / log10(b);

        printf("%d\n",zeros);
    }


    return 0;
}
