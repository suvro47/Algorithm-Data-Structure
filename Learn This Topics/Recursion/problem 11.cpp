
/*

Suppose you are given an array of integers in an arbitrary order. Write a recursive solution to find the maximum element from the array.

Input:
5
7 4 9 6 2
Output:
9


*/


#include<bits/stdc++.h>
using namespace std;

int MaxValue(int *a, int i, int n , int MX )
{
    if( i == n ) return MX;
    MX = max( MX, a[i] );
    return MaxValue(a,i+1,n,MX);
}

int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<MaxValue(arr,0,n,-1)<<endl;
}
