
/*

Write a recursive solution to get the reverse of a given integer. Function must return an int

Input:
123405
Output:
504321

*/

#include<bits/stdc++.h>
using namespace std;

int RevNumber( int n,int revn )
{
    if( n < 1 ) return revn;
    revn = revn*10 + (n%10);
    return RevNumber(n/10 , revn );
}

int main()
{
    int n;
    cin>>n;
    cout<<RevNumber(n,0)<<endl;

}
