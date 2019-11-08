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

vector<int>G[sz];
int Time,vis[sz],lev[sz],d[sz],f[sz];

void dfs(int u)
{
    Time++;
    d[u] = Time;
    vis[u] = 1;

    for(int v:G[u]){
        if(!vis[v]){
            lev[v] = lev[u]+1;
            dfs(v);
        }
    }
    Time++;
    f[u] = Time;
}

int main()
{
    int n,e,u,v,i,j,k;
    cin>>n>>e;
    for(i=0;i<e;i++){
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }

    for(i=1;i<=n;i++){
        if(vis[i]==0) dfs(i);
    }

    return 0;
}
