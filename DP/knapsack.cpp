#include<bits/stdc++.h>
using namespace std;

#define sz 1100

int n, w[sz] , v[sz] , K ; //-knapsack size
int dp[sz][sz];

int f(int in,int rem)   /// index , remaining
{
    if( in == n || rem <= 0 ) return 0;

    if( dp[in][rem ] != -1 ) return dp[in][rem];

    int ans = max ( v[in] + f(in+1,rem-w[in]) ,
                   f(in+1,rem));
    return dp[in][rem] = ans;
}

int main()
{
    memset(dp,-1,sizeof dp);

    /// input

    f(0,K);

    return 0;
}
