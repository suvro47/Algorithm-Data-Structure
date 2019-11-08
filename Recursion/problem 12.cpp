
/*

Write a recursive solution to find the second maximum number from a given set of integers.

Input:
5
5 8 7 9 3
Output:
8

*/

#include<bits/stdc++.h>
using namespace std;

int SecMaxValue(int *a, int i, int n , int MX , int SecMX )
{
    if( i == n ) return SecMX;

    if( MX == - 1 ) MX = max( MX , a[i] );
    else if( MX < a[i] ) SecMX = MX , MX = a[i];
    else SecMX = max( SecMX , a[i] );

    return SecMaxValue(a,i+1,n,MX,SecMX);
}

int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<SecMaxValue(arr,0,n,-1,-1)<<endl;
}
