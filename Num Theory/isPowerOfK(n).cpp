
/*
https://www.geeksforgeeks.org/check-number-power-k-using-base-changing-method/
https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/
*/

#include<bits/stdc++.h>
#define     sf        scanf
#define     pf        printf
#define     ll        long long
#define     sz        100005
#define     pi        acos(-1.0)
#define     ff        first
#define     ss        second
#define     pb        push_back
#define     mk        make_pair
#define     all(x)    x.begin(),x.end()

using namespace std;

/*----------------- Start Here ---------------------*/

ll n,i,j,k;

bool isPowerOfK(ll k)
{
    bool oneseen=false;

    while(n>0){
        ll digit=n%k;

        if(digit>1) return false;

        if(digit==1){
            if(oneseen) return false;
            else oneseen=true;
        }
        n/=k;
    }
    return true;
}

int main()
{
    cin>>n>>k;

    if(isPowerOfK(k))
        cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;
}
