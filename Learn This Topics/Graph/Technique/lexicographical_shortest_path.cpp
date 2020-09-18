
/*
   Lecture : 10
   Lexicographical small shortest path find
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


typedef pair<int,int> pii;
vector< pii >G[10001] , rG[10001];
int PS[sz],PD[sz],dis[sz],dis2[sz];
int parent[sz];

int min_cost;

void dijkstra(int s)
{
    priority_queue< pii, vector< pii >, greater< pii > > PQ;
    for(int i=0; i<sz; i++) dis[i] = INF;
    dis[s] = 0;
    PQ.push({0,s});

    while(!PQ.empty()){

        int u = PQ.top().S;
        PQ.pop();

        for(int i = 0; i<G[u].size() ; i++){
            int v = G[u][i].F;
            int w = G[u][i].S;
            if( dis[u] != INF ){
                if( dis[v] == INF || dis[v] > dis[u]+w ){
                    dis[v] = dis[u]+w;
                    ///PS[v] = u;  lagbe na
                    PQ.push({dis[v],v});
                }
            }
        }
    }
}


/// shortest path cost form n to other nodes

void dijkstra2(int n)
{
    priority_queue< pii, vector< pii >, greater< pii > > PQ;
    for(int i=0; i<sz; i++) dis2[i] = INF;
    dis2[n] = 0;
    PQ.push({0,n});

    while(!PQ.empty()){

        int u = PQ.top().S;
        PQ.pop();

        for(int i = 0; i<rG[u].size() ; i++){
            int v = rG[u][i].F;
            int w = rG[u][i].S;
            if( dis2[u] != INF ){
                if( dis2[v] == INF || dis2[v] > dis2[u]+w ){
                    dis2[v] = dis2[u]+w;
                    /// PD[v] = u; lagbe na
                    PQ.push({dis2[v],v});
                }
            }
        }
    }
}


/// lexicographical path find

void fun(int s)
{
    queue<int>Q;
    Q.push(s);

    while( !Q.empty() ){
        int u = Q.front();
        Q.pop();

        int LSnode = -1;  /// lexicographically smallest node among all for parent u
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i].F;  /// only node no is needed

            if( dis[v]+dis2[v] == min_cost ){
                if( LSnode == -1 || LSnode > v)
                    LSnode = v;
            }
        }

        if(LSnode != -1 ){
            Q.push(LSnode);
            parent[LSnode] = u;
        }
    }
}


void path(int d)
{
    if(d==1)
        return;
    else{
        path(parent[d]);
        cout<<parent[d]<<' ';
    }
}


int main()
{

    int n,m,u,v,w,i,j;
    scanf("%d %d",&n,&m);

    /// directed graph
    /// G[] actual graph
    /// rG[] reverse graph

    for(i=0; i<n; i++){
        scanf("%d %d %d",&u,&v,&w);
        G[u].push_back({v,w});
        rG[v].push_back({u,w});
    }

    dijkstra(1);
    /// minimum cost to reach n'th node
    min_cost = dis[n];

    /// ulta dijkstra
    dijkstra2(n);

    fun(1);

    path(n);


    return 0;
}
