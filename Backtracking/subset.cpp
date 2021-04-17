

#include<bits/stdc++.h>
using namespace std;

#define sz 10001
typedef long long ll;

vector<int>res;
int n , taken[sz];

void subset(int last)
{
    for(auto j:res) cout<<j<<' ';   /// in case of given array print array[j]
    cout<<endl;

    for(int i=last; i<=n ; i++){
        res.push_back(i);
        subset(i+1);
        res.pop_back();
    }
}

int main()
{
    cin>>n;
    subset(1);

    return 0;
}
