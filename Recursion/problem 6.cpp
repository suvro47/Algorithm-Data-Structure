
/*

Write a recursive program to compute n!

Input:
5
Output:
120

*/

#include<bits/stdc++.h>
using namespace std;

int Fact(int n)
{
    if( n == 0 || n == 1 ) return 1;
    return n*Fact(n-1);
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    cout<<Fact(n)<<endl;
}

/* Explanation

Fact(5) = 1*2*3*4*5
Fact(4) = 1*2*3*4
Fact(3) = 1*2*3
Fact(2) = 1*2


Fact(1) = 1 // base
Fact(0) = 1 // case


Fact(5) = Fact(4)*5
Fact(4) = Fact(3)*4
Fact(3) = Fact(2)*3
Fact(2) = Fact(1)*2

Fact(n) = Fact(n-1)*n

*/








