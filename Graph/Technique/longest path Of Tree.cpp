
/*
    Lecture : 08
    Light OJ: 1094 - Farthest Nodes in a Tree
    Longest Path of a tree / Diameter
    Soln : First find any node at maximum level ( here u can assume any node as root )
    then from the farthest node use dijkstra to find the result.
    Complexity : 2*dijkstra
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
typedef pair<ll,ll> pii;
typedef pair<char,ll> pci;
typedef pair<string,ll> psi;

vector<pii>G[sz];

ll n,e,u,v,w,i,j,k,MxD,Fnode;
ll dis[sz];

ll dijkstra(ll s)
{
    priority_queue< pii, vector< pii >, greater< pii > > PQ;
    for(i=0; i<n; i++) dis[i] = INF;
    MxD = -1;
    dis[s] = 0;
    PQ.push(mk(dis[s],s));

    while(!PQ.empty()){

        u = PQ.top().S;
        PQ.pop();

        if( MxD < dis[u] ){
            MxD = dis[u];
            Fnode = u;
        }
        for(i =0 ; i< G[u].size(); i++){
            v = G[u][i].F;
            w = G[u][i].S;
            if( dis[v] == INF ){
                dis[v] = dis[u]+w;
                PQ.push(mk(dis[v],v));
            }
        }
    }

    return Fnode; /// return farthest node
}


int main()
{
    int T,tc=1;
    cin>>T;
    while(T--){
        cin>>n;

        for(i=0; i<n-1; i++){
            cin>>u>>v>>w;
            G[u].pb(mk(v,w));
            G[v].pb(mk(u,w));
        }

        ll src = dijkstra(0);
        ll des = dijkstra(src);
        cout<<"Case "<<tc++<<": "<<MxD<<endl;

        for(i=0; i<n; i++) G[i].clear();
    }


    return 0;
}
