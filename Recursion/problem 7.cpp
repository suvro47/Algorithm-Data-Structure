
/*

Write a recursive solution to evaluate the previous polynomial for any given x and n.
Like, when x=2 and n=5, we have 1 + x + x2 + ................. + xn-1 = 31

Input:
2 5
Output:
31

*/


#include<bits/stdc++.h>
using namespace std;

int Fun( int n, int x )
{
    if( n == 0 ) return 1;
    return pow(x,n-1) + Fun(x,n-1);
}

int main()
{
    ios::sync_with_stdio(0);
    int n,x;
    cin>>x>>n;

    cout<<Fun(x,n)<<endl;
}

/* Explanation

Fun(5) = 1 + x^1 + x^2 + x^3 + x^4
Fun(4) = 1 + x^1 + x^2 + x^3
Fun(3) = 1 + x^1 + x^2
Fun(2) = 1 + x^1

Fun(1) = 1  // base
Fun(0) = 1  // case

Fun(5) = Fun(4) + x^4
Fun(4) = Fun(3) + x^3
Fun(3) = Fun(2) + x^2
Fun(2) = Fun(1) + X^1

so finally we get Fun(n) = pow(x,n-1)+Fun(n-1)

*/
