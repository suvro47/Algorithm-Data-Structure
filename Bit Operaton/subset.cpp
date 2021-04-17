#include<bits/stdc++.h>
using namespace std;

int CheckBit(int val,int pos) { return val & (1<<pos); }

int main()
{
    int n;
    cin>>n;
    int y = 1 << n;

    for(int i=0; i<y; i++){
        cout<<i<<"th subset : ";
        for(int j=0; j<n; j++){
            if( CheckBit(i,j))
                cout<<j<<' ';
        }
        cout<<endl;
    }
    return 0;
}

