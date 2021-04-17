
/*

Write a recursive solution to find the Summation of 1 to n

Input :
5
Output :
15

*/

#include<bits/stdc++.h>
using namespace std;

int Sum(int n)
{
    if( n == 0 ) return 0;
    return n+Sum(n-1);
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    cout<<Sum(n)<<endl;
}

/* Explanation

Sum(5) = 1+2+3+4+5
Sum(4) = 1+2+3+4
Sum(3) = 1+2+3
Sum(2) = 1+2

Sum(1) = 1 // base
Sum(0) = 0 // case


Sum(5) = Sum(4)+5
Sum(4) = Sum(3)+4
Sum(3) = Sum(2)+3
Sum(2) = Sum(1)+2

Sum(n) = Sum(n-1)+n

*/










