
/*

Write a recursive program to determine whether a given integer is prime or not.

Input:
49
999983
1
Output:
not prime
prime
not prime

*/

#include<bits/stdc++.h>
using namespace std;

bool IsPrime( int i,int n )
{
    if( n == 2 || n == 3 ) return true;
    if( n < 2 || i > sqrt(n) ) return false;
    if( n%i ) return true;
    return IsPrime( i+1,n );
}

int main()
{
    int n;
    cin>>n;
    if( IsPrime(2,n) ) cout<<"Prime"<<endl;
    else cout<<"Not Prime"<<endl;
}

