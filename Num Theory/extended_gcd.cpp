#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI acos(-1.0)
#define MX 10004
#define MOD 1000000007

int egcd(int a,int b,int &x,int &y)
{
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }

    int x1,y1;
    int d = egcd(b%a,a,x1,y1);

    x = y1-(b/a) * x1;
    y = x1;

    return d;
}

int main()
{
    int a,b,x,y,g;
    while(cin>>a>>b){
        g = egcd(a, b, x, y);

        if(a==b) cout<<min(x,y)<<' '<<max(x,y)<<' '<<g<<endl;
        else cout<<x<<' '<<y<<' '<<g<<endl;
    }
    return 0;



}
