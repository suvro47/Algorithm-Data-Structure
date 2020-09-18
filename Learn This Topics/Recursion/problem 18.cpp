
/*

Implement strcat() strlen() recursively.

Input:
test on your own
Output:
test on your own

*/

#include<bits/stdc++.h>
using namespace std;


string STRCAT( string s1, string s2, string s3, int i, int n , int j, int m )
{
    if( i== n && j == m ) return s3;
    if( i < n ){
        s3 += s1[i];
        return STRCAT(s1,s2,s3,i+1,n,j,m);
    }
    if( j < m ){
        s3 += s2[j];
        return STRCAT(s1,s2,s3,i,n,j+1,m);
    }
}

int main()
{
    string s,ss;
    cin>>s>>ss;
    cout<<STRCAT(s,ss,"",0,s.size(),0,ss.size())<<endl;

}

