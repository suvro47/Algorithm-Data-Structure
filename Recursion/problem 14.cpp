
/*

Implement binary search recursively, i.e. given an array of sorted integers, find a query integer from it.
Input format: first n, the number of elements. Then n integers. Then, q, number of query, then q integers. Output format: for each of the q integers, print its index (within 0 to n-1) in the array or print 'not found', whichever is appropriate.

Input:
5
1 2 3 4 5
2
3 -5
Output:
2
not found


*/


#include<bits/stdc++.h>
using namespace std;


int Fun(int *a,int lb,int ub,int key)
{
    if( lb > ub ) return -1;
    int m = (lb+ub)/2;
    if( a[m] == key  ) return m;
    if( a[m]  > key ) ub = m-1;
    else lb = m+1;
    return Fun(a,lb,ub,key);
}

int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    int t,key;
    cin>>t;
    while(t--){
        cin>>key;
        if( Fun(arr,0,n-1,key) == -1 ) cout<<"not found"<<endl;
        else cout<<Fun(arr,0,n-1,key)<<endl;
    }
}


