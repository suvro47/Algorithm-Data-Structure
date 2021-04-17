#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()

string BigIntAdd(string a,string b)
{
    if(a.size() < b.size() ) swap(a,b);
    reverse(all(a));
    reverse(all(b));

    while(b.size() < a.size() ) b += '0';

    int i = 0 , c = 0 , sum ;
    string res;

    while( i < b.size() ){
        sum =  ( a[i]-'0' + b[i]-'0' + c ) ;
        res += (sum%10) + '0';
        c = sum/10;
        i++;
    }

    if( c ) res += ( c+'0' );

    reverse(all(res));

    int k = 0;
    while( res[k] == '0' ) k++;

    string value;
    while(k<res.size())
        value += res[k++];

    if( value.size() == 0 ) value += '0';
    return value;
}


string ss[100001];

void extra_zero(int x)
{
    int j = x;
    while(j--) ss[x] += '0';
}

string BigIntMul(string s1,string s2)
{
    reverse(all(s1));
    reverse(all(s2));

    for(int i=0; i<s2.size(); i++){
        extra_zero(i);
        int c = 0;
        for(int j=0; j<s1.size(); j++){
            int mul = (s2[i]-'0')*(s1[j]-'0') + c;
            int a = mul%10;
            ss[i] += (a+'0');
            c = mul/10;
        }
        if( c ) ss[i]+=(c+'0');
    }

    string res = "0";
    for(int i=0; i<s2.size(); i++){
        reverse(all(ss[i]));
        res = BigIntAdd(res,ss[i]);
    }

    return res;
}

int main()
{
    string s1,s2,res;
    s1 = "654154154151454545415415454";
    s2 = "63516561563156316545145146514654";

    cout<<BigIntMul(s1,s2)<<endl;
}
