/*

    Input  : 3
    Output :
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1

*/


#include<bits/stdc++.h>
using namespace std;

int n, taken[1001];
vector<int>res;

void permutation()
{
    if( (int)res.size() == n ){
        for(auto j:res) cout<<j<<' ';
        cout<<endl;
    }

    for(int i=1; i<=n ; i++){  /// all possible option
        if( !taken[i] ){   /// i'th index is used or not
            taken[i] = 1;
            res.push_back(i); /// push the i'th value into res
            permutation();
            res.pop_back();
            taken[i] = 0;
        }
    }
}

int main()
{
    cin>>n;
    permutation();

    return 0;
}
