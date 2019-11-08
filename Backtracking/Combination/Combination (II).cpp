#include<bits/stdc++.h>
using namespace std;

int n , k , a[1005], taken[1005];
vector<int>res;

void Combination(int idx)
{
    if(res.size()==k){
        for(auto j:res) cout<<j<<' ';
        cout<<endl;
        return;
    }

    for(int i=idx; i<n ; i++){
        if( !taken[i] ){
            taken[i] = 1;
            res.push_back(a[i]);
            Combination(i+1);
            taken[i] = 0;
            res.pop_back();
            while(a[i]==a[i+1]) i++;
        }
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
