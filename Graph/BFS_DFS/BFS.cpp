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
typedef long long  ll;
typedef pair<ll,ll> pii;
typedef pair<char,ll> pci;
typedef pair<string,ll> psi;

vector<int>G[sz];
queue<int>Q;

int n,e,i,j,u,v,lev[sz],vis[sz],s,d,p[sz];

void BFS(int s)
{
    lev[s]=0;
    vis[s]=1;
    Q.push(s);

    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(int v:G[u]){
            if(!vis[v]){
                lev[v]=lev[u]+1;
                vis[v]=1;
                p[v]=u;
                Q.push(v);
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
    for(i=1;i<=e;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>s>>d;
    BFS(s);
    path(d);
    cout<<d<<endl;
    return 0;
}
