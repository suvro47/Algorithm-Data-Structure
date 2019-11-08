#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI acos(-1.0)
#define MX 10000007
#define MOD 1000000007

ll n,i,j,k,c,t,status[MX];

void siv()
{
    status[0]=status[1]=1;

    for(i=4; i<MX; i+=2) status[i]=1;

    ll LIM=sqrt(MX);

    for(i=3; i<=LIM; i+=2){
        if(status[i]==0){
            for(j=i*i; j<MX; j+=2*i)
                status[j]=1;
        }
    }
}

int main()
{
    siv();
    cout<<status[9];


    return 0;
}
