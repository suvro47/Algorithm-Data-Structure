
/*

Write a recursive function to print an array in the following order.
[0] [n-1]
[1] [n-2]
.........
.........
[(n-1)/2] [n/2]

Input:
5
1 5 7 8 9
Output:
1 9
5 8
7 7


*/


#include<bits/stdc++.h>
using namespace std;

void Fun(int *a,int i,int j)
{
    if( i > j ) return;
    printf("%d %d\n",a[i],a[j]);
    Fun(a,i+1,j-1);
}

int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    Fun(arr,0,n-1);
}
