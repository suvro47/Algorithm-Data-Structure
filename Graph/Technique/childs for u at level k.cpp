
/*
    Lecture : 09
    How many child at level k from parent node u
    Soln : dfs time concept + binary search
    Complexity : O( (V+E) + Q*log(n) )  Per Query logn
*/

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 10000007
#define INF 0x3f3f3f3f

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;

vector<int>G[sz],L[sz];
int n,m,u,v,i,j,k,Time,vis[sz],d[sz],f[sz],lev[sz];

void dfs(int u)
{
    Time = Time+1;
    d[u] = Time;
    vis[u] = 1;

    for(int v:G[u]){
        if( !vis[v] ){
            lev[v] = lev[u]+1;
            dfs(v);
        }
    }
    Time = Time+1;
    f[u] = Time;
}

int main()
{

    scanf("%d",&n);
    for(i=0; i<n-1 ;i++){
        scanf("%d %d",&u,&v);
        G[u].pb(v);
    }

    dfs(1);

    for(u=1; u<=n; u++)
        L[lev[u]].pb(d[u]);

    int Q;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&u,&k);
        int id = lev[u]+k;
        int low = lower_bound(L[id].begin(),L[id].end(), d[u] ) - L[id].begin();
        int high = upper_bound(L[id].begin(),L[id].end(), f[u]) - L[id].begin();

        printf("%d\n",high-low);
    }


    return 0;
}
