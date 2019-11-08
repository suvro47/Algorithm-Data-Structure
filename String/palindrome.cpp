
/*
   Lecture : 09
   string length n (<= 10^5) +
   query Q*26
*/

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 10000007
#define INF 0x3f3f3f3f

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;

int main()
{
    string s;
    cin>>s;
    vector<int>v[sz];

    /* cumulative sum concept

    for(int i='a'; i<='z' ; i++){
        int cnt = 0;
        for(int j=0; j<n ; j++){
            if( s[j] == i ) cnt++;
            v[i].pb(cnt);
        }
    }

    int Q;
    cin>>Q;
    while(Q--){

        int l,r;
        cin>>l>>r; /// 0 based index

        int cnt = 0 , val;
        for(int i='a'; i<='z' ; i++){
            if( l == 0 ) val = v[i][r];
            else val = v[i][r]-v[i][l-1];
            if( val&1 ) cnt++;
        }

        if( cnt > 1 ) cout<<"Impossible"<<endl;
        else cout<<"Possible"<<endl;
    }
    */


    /* cumulative XOR concept */

    for(int i='a'; i<='z' ; i++){
        int cnt = 0;
        for(int j=0; j<n ; j++){
            if( s[j] == i ) cnt++;
            v[i].pb(cnt%2);
        }
    }

    int Q;
    cin>>Q;
    while(Q--){

        int l,r;
        cin>>l>>r; /// 0 based index

        int cnt = 0 , val;
        for(int i='a'; i<='z' ; i++){
            if( l == 0 ) val = v[i][r];
            else val = v[i][r]^v[i][l-1] ;
            if( val ) cnt++;
        }

        if( cnt > 1 ) cout<<"Impossible"<<endl;
        else cout<<"Possible"<<endl;
    }

    return 0;
}
