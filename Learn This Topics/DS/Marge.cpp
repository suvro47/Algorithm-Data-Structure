#include<bits/stdc++.h>
using namespace std;

#define sz 10000007
typedef long long ll;

ll a[sz],n;
ll L[sz],R[sz];  /// Left array and Right array
ll inv = 0;

void conquer(ll nL ,ll nR ,ll k)
{
    ll i = 1 , j = 1;

    while( i <= nL  && j <= nR ){
        if( L[i] <= R[j] ){
            a[k] = L[i];
            k++, i++;
        }
        else{
            a[k] = R[j];
            k++,j++;
            inv += (nL-i)+1;
        }
    }

    while( i <= nL ) { a[k]=L[i] , k++, i++; }
    while( j <= nR ) { a[k]=R[j] , k++, j++; }
}

void divide(ll b, ll e)
{
    if( b >= e ) return;  /// single element er jonno return korbe

    ll mid = (b+e)/2;

    divide(b,mid);
    divide(mid+1,e);

    for(ll i=b; i<=mid ; i++) L[i-b+1] = a[i];
    for(ll i=mid+1; i<=e; i++) R[i-(mid+1)+1] = a[i];

    conquer(mid-b+1, e-mid , b);  /// sending the length of Left array and Right array also beginning index of original array a
}

int main()
{
    while( scanf("%lld",&n) && n ){
        inv = 0;
        for(ll i=1; i<=n; i++) scanf("%lld",&a[i]);
        divide(1,n);
        cout<<inv<<endl;
    }


    return 0;
}
