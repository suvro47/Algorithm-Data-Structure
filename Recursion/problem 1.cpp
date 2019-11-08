
/*

You will be given an array of integers, write a recursive solution to print it in reverse order.

Input:
5
69 87 45 21 47
Output:
47 21 45 87 69

*/


#include<bits/stdc++.h>
using namespace std;

void Fun(int a[],int i,int n)
{
    if( i == n  ) return;
    Fun(a,i+1,n);
    printf("%d ",a[i]);
}

int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    Fun(arr,0,n);
}

/* Explanation

Forward:
for loop:

for(int i = 0; i < n; i++) {
    // do whatever needed
}

Equivalent recursion:

void FOR(int i, int n) {
    if(i==n) return; // terminates
    // do whatever needed
    FOR(i+1, n); // go to next step
}

Backward:
for loop:

for(int i = n-1; i >= 0; i -= 1) {
    // do whatever needed
}

Equivalent recursion:

void ROF(int i, int n) {
    if(i==n) return; // terminates
    ROF(i+1, n); // keep going to the last
    // do whatever needed when returning from prev steps
}

*/
