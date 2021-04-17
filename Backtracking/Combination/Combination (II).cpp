#include<bits/stdc++.h>
using namespace std;

int n , k , a[1005];
vector<int>res;

void Combination(int last)
{
    if(res.size()==k){
        for(auto j:res) cout<<j<<' ';
        cout<<endl;
        return;
    }

    for(int i=last; i<n ; i++){
        res.push_back(a[i]);
        Combination(i+1);
        res.pop_back();
        while( i+1 < n && a[i+1] == a[i] ) i++;
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    Combination(0);

    return 0;
}
