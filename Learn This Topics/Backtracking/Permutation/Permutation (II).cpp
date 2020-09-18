#include<bits/stdc++.h>
using namespace std;

int n , a[1001] , taken[1001];
vector<int>res;

void permutation()
{
    if( res.size() == n ){
        for(auto j:res) cout<<j<<' ';
        cout<<endl;
    }

    for(int i=0; i<n ; i++){
        if( !taken[i] ){
            taken[i] = 1;
            res.push_back(a[i]);
            permutation();
            res.pop_back();
            taken[i] = 0;
            while( i+1 < n && a[i+1] == a[i] ) i++;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);

    permutation();

    return 0;
}
