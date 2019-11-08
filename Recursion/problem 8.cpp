
/*

Write a recursive program to compute nth fibonacci number. 1st and 2nd fibonacci numbers are 1, 1.

Input:
6
Output:
8

*/

#include<bits/stdc++.h>
using namespace std;

int Fib(int n)
{
    if( n == 0 ) return 0;
    if( n == 1 ) return 1;
    return Fib(n-1)+Fib(n-2);
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    cout<<Fib(n)<<endl;
}

/* Explanation

Fib(5) = Fib(4) + Fib(3)
Fib(4) = Fib(3) + Fib(2)
Fib(3) = Fib(2) + Fib(1)
Fib(2) = Fib(1) + Fib(0)


Fib(1) = 1  // base
Fib(0) = 0  // case

Fib(n) = Fib(n-1) + Fib(n-2)

*/
