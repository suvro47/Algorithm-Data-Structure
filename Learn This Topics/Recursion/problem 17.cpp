
/*

Write a recursive program that determines whether a given sentence is palindromic or not
just considering the alpha-numeric characters ('a'-'z'), ('A'-'Z'), ('0'-'9').

Input:
madam, i'm adam
hulala
Output:
palindromic
not palindromic

*/


#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str,int i,int j)
{
    if( i > j  ) return true;
    if( str[i] != str[j] ) return false;
    return checkPalindrome(str,i+1,j-1);
}

int main()
{
    string s;
    cin>>s;
    if( checkPalindrome(s,0,s.size()-1)) cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;

}
