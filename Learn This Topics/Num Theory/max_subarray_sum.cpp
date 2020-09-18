/// Kadane's Algo --- need at least one positive element //

#include<bits/stdc++.h>
#define sf scanf
#define pf printf
#define sz 10000001
typedef long long LL;
using namespace std;

LL n,m,k,i,j,a[sz],c=0,t=INT_MIN,sum=0,MX=INT_MIN;
string s1,s2,s3;

LL subArraySum(LL *a,LL n)       /// complexity O(n) ///
{
    for(i=0;i<n;i++){
        sum += a[i];
        if(sum>0)
            MX=max(sum,MX);
        else sum=0;
    }
    return MX;
}

int main()
{
    sf("%lld",&n);
    for(i=0;i<n;i++){
        sf("%lld",&a[i]);
        if(a[i]<0) c++;
        t=max(a[i],t);
    }
    if(c==n){
        cout<<t<<endl;
        return 0;
    }
    cout<<subArraySum(a,n)<<endl;
}
