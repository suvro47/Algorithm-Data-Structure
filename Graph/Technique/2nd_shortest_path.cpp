
/*
    Lecture : 10
    2nd shortest path
*/

#include<bits/stdc++.h>
using namespace std;

#define sz 50005
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 10000007
#define INF 1000000009

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;
typedef pair<ll,ll> pii;

vector<pii>G[sz];

ll n,e,u,v,w,i,j,s,d,k,c;
ll dis[sz],dis2[sz];

void dijkstra(ll s)
{
    priority_queue< pii, vector< pii >, greater< pii > > PQ;
    dis[s] = 0;
    PQ.push({0,s});

    while( !PQ.empty() ){

        u = PQ.top().S;
        c = PQ.top().F;
        PQ.pop();

        for(i = 0; i<G[u].size() ; i++){
            v = G[u][i].F;
            w = G[u][i].S;

            if( dis[v] > c+w ){
                dis2[v] = dis[v];
                dis[v] = c+w;
                PQ.push({dis[v],v});
            }

            if( dis[v] == c+w ){
                ///
            }

            else if( dis2[v] > c+w ){
                dis2[v] = c+w;
                PQ.push({dis2[v],v});
            }
        }
    }
}

int main()
{
    ll T,tc=1;
    cin>>T;
    while(T--){
        for(i=0; i<sz; i++) G[i].clear();
        memset(dis,127,sizeof dis);
        memset(dis2,127,sizeof dis2);

        cin>>n>>e;
        for(i=0; i<e; i++){
            cin>>u>>v>>w;
            G[u].pb(mk(v,w));
            G[v].pb(mk(u,w));
        }
        dijkstra(1);
        printf("Case %lld: %lld\n",tc++,dis2[n]);
    }


    return 0;
}
