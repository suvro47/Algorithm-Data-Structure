#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()

string BigIntAdd(string a,string b)
{
    if(a.size() < b.size() ) swap(a,b);
    reverse(all(a));
    reverse(all(b));

    while(b.size() < a.size() ) b += '0';

    int i=0 , c = 0 , sum ;
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

int main()
{

    string x,y;
    cin>>x>>y;

    cout<<BigIntAdd(x,y)<<endl;

    main();

}
