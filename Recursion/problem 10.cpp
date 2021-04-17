

/*
Write a recursive function that finds the gcd of two non-negative integers.

Input:
25 8895
Output:
5

*/

#include<bits/stdc++.h>
using namespace std;

int GCD(int x,int y)
{
    if( y == 0 ) return 0;
    if( x%y == 0 ) return y;
    return GCD(y,x%y);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b)<<endl;
    return

}

/*
   Explanation : Using Euclid Algorithm
   Let's take an example for 12 and 8

   using Euclid algo we can demonstrate gcd(12,8) == gcd(8,12%4) == gcd(8,4)
   so ans will 4.

*/
