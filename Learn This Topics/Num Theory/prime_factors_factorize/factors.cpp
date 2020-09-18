#include<bits/stdc++.h>
#define sf scanf
#define pf printf
typedef long long ll;
using namespace std;

ll n,i,j,k;
set<ll>d;

void divisor(ll x)
{
    for(i=1; i*i<=x ;i++){
        if(x%i==0){
           d.insert(i);
           d.insert(x/i);
        }
    }
}

int main()
{
    cin>>n;
    divisor(n);
    cout<<d.size()<<endl;
    for(auto i:d)
        cout<<i<<endl;

    return 0;
}
