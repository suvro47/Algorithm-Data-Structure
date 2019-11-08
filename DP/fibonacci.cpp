#include<bits/stdc++.h>
using namespace std;

int dp[10001];

int F(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = F(n-1)+F(n-2);
    return dp[n];
}

int main()
{
    memset(dp,-1,sizeof dp);
    int n;
    cin>>n;
    cout<<F(n);

    main();

    return 0;
}
