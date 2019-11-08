#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime(ll x)
{
    if(x<2) return false;
    else if(x==2 || x==3)
        return true;
    if (x%2==0 || x%3==0)
        return false;
    for (ll i=5;i*i<=x;i=i+6){
        if (x%i==0 || x%(i+2)==0)
            return false;
    }
    return true;
}

int main()
{
    ll n;
    cin>>n;
    if(isPrime(n)) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    main();

    return 0;
}
