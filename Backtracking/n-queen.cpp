#include<bits/stdc++.h>
using namespace std;

int  n , queen[1000], C[1000], D1[1000], D2[1000];

void n_queen(int at)
{
    if( at == n+1 ){
        cout<<"(row,column)"<<endl;
        for(int i=1; i<=n; i++)
            cout<<i<<','<<queen[i]<<endl;
        return;
    }

    for(int i=1; i<=n ; i++ ){
        if( !C[i] && !D1[i+at] && !D2[n+i-at] ){
            C[i] = D1[i+at] = D2[n+i-at] = 1;
            queen[at] = i;
            n_queen(at+1);
            C[i] = D1[i+at] = D2[n+i-at] = 0;
        }
    }
}

int main()
{
    cin>>n;
    n_queen(1);

    return 0;
}
