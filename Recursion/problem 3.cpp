

/*

Write a recursive program to remove all odd integers from an array.
You must not use any extra array or print anything in the function.
Just read input, call the recursive function, then print the array in main().

Input:
6
1 54 88 6 55 7
Output:
54 88 6


*/


#include<bits/stdc++.h>
using namespace std;

void OddErase(int *a,int i, int n)
{
    if( i == n ) return;
    if( a[i]%2 ) a[i] = -1;
    OddErase(a,i+1,n);
}

int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    OddErase(arr,0,n);
    for(int i=0; i<n; i++){
        if( arr[i] != -1 )
            printf("%d ",arr[i]);
    }
}
