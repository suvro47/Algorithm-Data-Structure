
#include<bits/stdc++.h>
#define     sf       scanf
#define     pf       printf
#define     ll       long long
#define     sz       10001
#define     pi       acos(-1.0)
#define     ff       first
#define     ss       second
#define     pb       push_back
#define     mp       make_pair
#define     all(x)   x.begin(),x.end()

using namespace std;

/*----------------- Start Here ---------------------*/

/* using dfs */

vector<int>vc[sz],topS;
int vis[sz];

void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<vc[u].size();i++){
        int v=vc[u][i];
        if(vis[v]==0) dfs(v);
    }
    topS.push_back(u);
}

int main()
{
    int n,e,u,v,i,j,k;
    cin>>n>>e;
    for(i=0;i<e;i++){
        cin>>u>>v;
        vc[u].pb(v);
    }

    for(i=0;i<n;i++){
        if(vis[i]==0) dfs(i);
    }
    reverse(all(topS));

    for(auto i:topS)
        cout<<i<<endl;

    return 0;
}
