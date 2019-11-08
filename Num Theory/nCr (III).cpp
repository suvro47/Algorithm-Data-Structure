#include<bits/stdc++.h>
using namespace std;

int table[1001][1001];

int C(int n,int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(table[n][r] != -1) return table[n][r];
    table[n][r] =  C(n-1,r)+ C(n-1,r-1);
    return table[n][r];
}

int main()
{
    memset(table,-1,sizeof table);
    int n,r;
    cin>>n>>r;
    cout<<C(n,r)<<endl;

    return 0;
}
