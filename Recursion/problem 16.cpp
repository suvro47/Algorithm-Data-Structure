
/*

Read a string from keyboard and print it in reversed order. You must not use any array to store the characters.
Write a recursive solutions to solve this problem.

Input:
helloo
Output:
oolleh

*/

#include<bits/stdc++.h>
using namespace std;


void RevString(string str , int i, int n)
{
    if( i == n ) return;
    RevString(str,i+1,n);
    printf("%c",str[i]);
}


int main()
{
    string s;
    cin>>s;
    RevString(s,0,s.size());

}
