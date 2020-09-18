
/*

Write a recursive solution to print the polynomial series for any input n:
1 + x + x2 + ................. + xn-1

Input:
5
Output:
1 + x + x^2 + x^3 + x^4


*/


#include<bits/stdc++.h>
using namespace std;

void Fun(int i, int n)
{
    if( i == n ) return;
    if( i == 0 ) printf("1");
    if( i == 1 ) printf(" + X");
    if( i > 1 ) printf(" + X^%d",i);
    Fun(i+1,n);
}


int main()
{
    int n;
    cin>>n;
    Fun(0,n);

}
