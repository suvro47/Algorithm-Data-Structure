

/*

Implement linear search recursively, i.e. given an array of integers, find a specific value from it.
Input format: first n, the number of elements. Then n integers. Then, q, number of query, then q integers. Output format: for each of the q integers, print its index (within 0 to n-1) in the array or print 'not found', whichever is appropriate.

Input:
5
2 9 4 7 6
2
5 9
Output:
not found
1


*/


#include<bits/stdc++.h>
using namespace std;

int Fun(int *a,int i,int n,int key)
{
    if( i == n ) return -1;
    if( a[i] == key  ) return i;
    return Fun(a,i+1,n,key);
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
        if( Fun(arr,0,n,key) == -1 ) cout<<"not found"<<endl;
        else cout<<Fun(arr,0,n,key)<<endl;
    }
}
