#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define F first
#define S second

typedef long long ll;
typedef pair<int,int>pii;

vector<pii>G[sz];
int taken[sz] , ans;

int LongestPath(int u)
{
    ans = 0;
    for(int i=0; i<G[u].size() ; i++){
        int v = G[u][i].F;
        int w = G[u][i].S;

        if( !taken[v] ){
            taken[v] = 1;
            int rem = LongestPath(v);
            if( ans < w+rem ) ans = w+rem;
            taken[v] = 0;
        }
    }
    return ans;
}

int main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    cout<<LongestPath(1)<<endl;

    return 0;
}
