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

vector<int>G[sz];
int n,e,i,j,u,v,color[sz],vis[sz],s,d;

bool BFS(int s)
{
    queue<int>Q;
    memset(color,-1,sizeof color);
    color[s]=1;
    vis[s]=1;
    Q.push(s);

    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(i=0;i<G[u].size();i++){
            v=G[u][i];
            if( vis[v] ){
                if( color[v] == color[u] ) return false;
            }

            if( !vis[v] ){
                vis[v]=1;
                if( color[u] == 0 ) color[v] = 1;
                else color[v] = 0;
                Q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    cin>>n>>e;
    for(i=1;i<=e;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if( BFS(1) ) cout<<"BICOLORABLE."<<endl;
    else cout<<"NOT BICOLORABLE."<<endl;

    return 0;
}
