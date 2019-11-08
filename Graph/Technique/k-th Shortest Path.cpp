
/*
  Lecture : 10
  K'th shortest path
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

ll n,m,k,u,v,w,i,j,p,s,d,c;
ll dis[21][sz];

void dijkstra(ll s)
{
    priority_queue< pii, vector< pii >, greater< pii > > PQ;
    dis[0][s] = 0;
    PQ.push({0,s});

    while( !PQ.empty() ){

        u = PQ.top().S;
        c = PQ.top().F;
        PQ.pop();

        for(i = 0; i<G[u].size() ; i++){
            v = G[u][i].F;
            w = G[u][i].S;

            for(j=0; j<k; j++){
                if( dis[j][v] > c+w ){
                    for(p=k-2; p>=j; p--){
                        dis[p+1][v] = dis[p][v];
                        PQ.push({dis[p][v],v});
                    }
                    dis[j][v] = c+w;
                    PQ.push({dis[j][v],v});
                }
            }
        }
    }
}

int main()
{
    ll T,tc=1;
    scanf("%lld",&T);
    while(T--){
        for(i=0; i<sz; i++) G[i].clear();
        memset(dis,127,sizeof dis);

        scanf("%lld %lld %lld",&n,&m,&k);
        for(i=0; i<m; i++){
            scanf("%lld %lld %lld",&u,&v,&w);
            G[u].pb(mk(v,w));
            G[v].pb(mk(u,w));
        }
        dijkstra(1);
        printf("Case %lld: %lld\n",tc++,dis[k][n]);
    }


    return 0;
}
