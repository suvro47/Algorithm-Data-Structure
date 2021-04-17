#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()

bool isSmaller(string a,string b)
{
    if( a.size()<b.size() ) return true;
    if( a.size()>b.size() ) return false;
    int i = 0 ;
    while(a[i] == b[i] ) i++;

    return a[i] < b[i];
}

string BigIntSub(string a,string b)
{
    string sign ="";
    if(isSmaller(a,b)){
        swap(a,b);
        sign += '-';
    }

    reverse(all(a));
    reverse(all(b));

    while(b.size() < a.size()) b += '0';

    int i = 0 , c = 0 , sub ;
    string res;

    while(i < b.size()){

        if( a[i] < b[i]+c ){
            sub = ( a[i]-'0' + 10 ) - ( ( b[i]-'0' ) + c );
            res += (sub+'0');
            c = 1;
        }
        else{
            sub = (a[i]-'0') - ( (b[i]-'0') + c );
            res += (sub+'0');
            c = 0;
        }
        i++;
    }

    reverse(all(res));

    int k = 0;
    while( res[k] == '0' ) k++;

    string value;
    value += sign ;

    while(k<res.size())
        value += res[k++];

    if( value.size() == 0 ) value += '0';

    return value;
}

int main()
{

    string x , y ;
    cin>>x>>y;

    cout<<BigIntSub(x,y)<<endl;

    main();

    return 0;
}
