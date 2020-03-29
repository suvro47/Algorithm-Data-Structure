#include<bits/stdc++.h>
using namespace std;

int n , k ;
vector<int>res;

void Combination(int last)
{
    if( (int)res.size() == k ){
        for(auto j:res) cout<<j<<' ';
        cout<<endl;
    }

    for(int i=last; i<=n ; i++){
        res.push_back(i);
        Combination(i+1);
        res.pop_back();
    }
}


int main()
{
    cin>>n>>k;
    Combination(1);


    return 0;
}
