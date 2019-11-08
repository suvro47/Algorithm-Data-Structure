
/*
    Lecture : 08
    How Many Child & Level actually finding Subtree size and Hight
    soln : dfs + Q*O(1)
*/

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define INF 10000007
#define LLINF 100000000000000007

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long ll;

vector<int>G[sz],node;
int vis[sz] , subtree[sz] , depth[sz];

int dfs(int u)
{
    vis[u] = 1;

    for(int v:G[u] ){
        if( !vis[v] ){
            dfs(v);
            subtree[u] += subtree[v];
            depth[u] = max( depth[u], depth[v]+1);
        }
    }
}

void init()
{
    for(int i=0; i<sz; i++){
        G[i].clear();
        vis[i] = depth[i] = 0;
        subtree[i] = 1;
    }
}

int main()
{
    init();
    int n,e,u,v,i,j,k;
    cin>>n>>e;
    for(i=0;i<e;i++){
        cin>>u>>v;
        G[u].pb(v);
    }

    dfs(1);

    int Q;
    cin>>Q;

    while(Q--){
        cin>>u;
        cout<<subtree[u]<<' '<<depth[u]<<endl;
    }


    return 0;
}

