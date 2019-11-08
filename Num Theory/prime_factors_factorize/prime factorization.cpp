#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< pair<ll,ll> >v;

void Factorize(ll n)
{
    for(ll i=2; i*i <= n ; i++){
        if(n%i==0){
            ll cnt = 0;
            while(n%i==0){
                n = n/i;
                cnt++;
            }
            v.push_back(make_pair(i,cnt));
        }
    }
    if(n>1) v.push_back(make_pair(n,1));

}


int main()
{

    Factorize(6);

    for(auto i:v)
        cout<<i.first<<' '<<i.second<<endl;

    return 0;
}
