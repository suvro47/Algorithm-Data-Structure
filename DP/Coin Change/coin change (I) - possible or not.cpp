

/*
   Is it possible to make amount-K or not
   one coin should use only one time
*/

#include<bits/stdc++.h>
using namespace std;

#define sz 10001

int n, coin[sz] , K;
/// n = 4; coin [] = {2,5,10,4} , K = 12;

int dp[sz][sz];

int f(int in,int rem)
{
    if( rem == 0 ) return 1;
    if( in == n || rem < 0 ) return 0;

    if( dp[in][rem] != -1 ) return dp[in][rem];

    int ans = f(in+1,rem-coin[in]) ||
              f(in+1,rem);

    return dp[in][rem] = ans;
}

int main()
{
    memset(dp,-1,sizeof dp);

    /// input

    if ( f(0,K) ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
