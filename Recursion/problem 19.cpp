

/*

Write a recursive solution to compute lcm of two integers. You must not use the formula lcm(a,b) = (a x b) / gcd(a,b); find lcm from scratch...

Input:
23 488
Output:
11224

*/

#include<bits/stdc++.h>
using namespace std;

int LCM( int x,int y,int i )
{
    if( i%x == 0 && i%y == 0 ) return i;
    return LCM(x,y,i+1);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<LCM(a,b,min(a,b))<<endl;
}
