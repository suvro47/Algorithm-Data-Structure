#include<bits/stdc++.h>
using namespace std;

#define sz 10004
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
typedef pair<ll,ll> pii;
typedef pair<char,ll> pci;
typedef pair<string,ll> psi;

ll n,e,u,v,i,j,w,s,d;
ll cost[sz][sz],dis[sz],p[sz];

vector<ll>G[sz];

void dijkstra(ll s)
{
    priority_queue< pii, vector< pii >, greater< pii > > PQ;
    dis[s] = 0;
    PQ.push(make_pair(0,s));
    while(!PQ.empty()){

        u = PQ.top().S;
        PQ.pop();
        for(int v: G[u]){
            if( dis[u] != INF && cost[u][v] != INF ){
                if( dis[v] == INF || dis[v] > dis[u]+cost[u][v] ){
                    dis[v] = dis[u]+cost[u][v];
                    p[v] = u;
                    PQ.push(make_pair(cost[u][v],v));
                }
            }
        }
    }
}

void path(ll d)
{
    if(d==s) return;
    else{
        path(p[d]);
        cout<<p[d]<<' ';
    }
}

void init_()
{
    for(i=0; i<sz; i++)
        for(j=0; j<sz; j++)
            if(i != j) cost[i][j] = INF;

    for(i=0; i<sz; i++){
        cost[i][i] = 0;
        G[i].clear();
    }
}

int main()
{
    cin>>n>>e;

    for(i=0;i<e;i++){
        cin>>u>>v>>w;
        G[u].pb(v);
        G[v].pb(u);
        cost[u][v] = cost[v][u] = w;
    }

    for(i=1; i<=n; i++) dis[i] = INF;

    dijkstra(1);

    for(i=1 ;i<=n; i++)
        cout<<dis[i]<<endl;

    return 0;
}
