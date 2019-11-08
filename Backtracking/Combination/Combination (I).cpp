#include<bits/stdc++.h>
using namespace std;

int n , k , taken[1001];
vector<int>res;

void Combination(int last)
{
    if( (int)res.size() == k ){
        for(auto j:res) cout<<j<<' ';
        cout<<endl;
    }

    for(int i=last ; i<=n ; i++){
        if( !taken[i] ){
            taken[i] = 1;
            res.push_back(i);
            Combination(i+1);
            res.pop_back();
            taken[i] = 0;
        }
    }
}


int main()
{
    cin>>n>>k;
    Combination(0);


    return 0;
}
