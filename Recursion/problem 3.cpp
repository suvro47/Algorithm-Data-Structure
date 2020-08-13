

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

void fun( int i, int j, int n, int *arr )
{
    if( i >= n ) return;
    if( arr[i]&1 ) fun(i+1,j,n,arr);
    arr[j] = arr[i];
    fun(i+1,j+1,n,arr);

}

int main()
{
      int a[5] = {22, 45, 66, 32, 69};
      fun(0,0,5,a);

      for(int i=0; i<5; i++) cout<<a[i]<<endl;
}
