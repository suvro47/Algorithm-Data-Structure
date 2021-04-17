#include<bits/stdc++.h>
using namespace std;

#define B 21
#define M 100000007

int n,m;

int Hash_val(string &s)
{
    int hv = 0 , power = 1;

    for(int i=m-1 ; i>=0 ;i--){
        hv = hv + (s[i]*power) % M;
        hv = hv % M;
        power = (power * B) % M;
    }

    return hv;
}

int match(string &text,string &pattern)
{
    n = text.size();
    m = pattern.size();

    if(n<m) return -1;
    if(n==0 || m==0) return -1;

    //Find hash value of first m characters of text
    //Find hash value of pattern

    int hash_pattern = Hash_val(pattern);
    int hash_text = Hash_val(text);

    if(hash_pattern == hash_text)
        return 0; // 0 index

    // calculate power = B^(m-1)

    int power = 1;

    for(int i=1; i<=m-1;i++)
        power = (power * B) % M;


    for(int i=1; i<n-m+1 ; i++){

        hash_text = hash_text - (text[i-1] * power) % M;
        hash_text = (hash_text * B) % M;
        hash_text = hash_text + text[i+m-1];

        if(hash_text == hash_pattern)
            return i;

    }

    return -1;
}


int main()
{
    string s1,s2;

    cin>>s1>>s2;

    cout<<match(s1,s2)<<endl;

}
