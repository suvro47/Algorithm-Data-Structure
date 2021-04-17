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
typedef pair<ll,ll> pii;
typedef pair<char,ll> pci;
typedef pair<string,ll> psi;

vector<pii>G[sz];

ll n,e,u,v,w,i,j,k,s,d;
ll dis[sz],p[sz];

void dijkstra(ll s)
{
    priority_queue< pii, vector< pii >, greater< pii > > PQ;
    dis[s] = 0;
    PQ.push({0,s});

    while(!PQ.empty()){

        u = PQ.top().S;
        PQ.pop();

        for(i = 0; i<G[u].size() ; i++){
            v = G[u][i].F;
            w = G[u][i].S;
            if( dis[u] != INF ){
                if( dis[v] == INF || dis[v] > dis[u]+w ){
                    dis[v] = dis[u]+w;
                    p[v] = u;
                    PQ.push({dis[v],v});
                }
            }
        }
    }
}

void path(int d)
{
    if(d==s)
        return;
    else{
        path(p[d]);
        cout<<p[d]<<' ';
    }
}


int main()
{

    cin>>n>>e;

    for(i=0; i<e; i++){
        cin>>u>>v>>w;
        G[u].pb(mk(v,w));
        G[v].pb(mk(u,w));
    }

    for(i=1; i<=n; i++) dis[i] = INF;

    dijkstra(1);

    for(i=1 ;i<=n; i++)
        cout<<dis[i]<<endl;


    return 0;
}
