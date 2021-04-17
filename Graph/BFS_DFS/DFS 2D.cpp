#include<bits/stdc++.h>
using namespace std;

#define sz 1005
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 10000007

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;
typedef pair<ll,ll> pii;
typedef pair<char,ll> pci;
typedef pair<string,ll> psi;

ll vis[sz][sz];
char G[sz][sz];
vector<pii>v;

ll n,m,i,j,k,ans=1,cnt;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void dfs(int x,int y)
{
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<n && G[nx][ny]=='.' && !vis[nx][ny])
            dfs(nx,ny);
    }
}

int main()
{
    cin>>n>>m>>cnt;

    memset(vis,0,sizeof(vis));

    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cin>>G[i][j];
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(G[i][j]=='.' && !vis[i][j]){
                dfs(i,j);
            }
        }
    }

    for(i =0 ; i<v.size() && cnt; i++,cnt--){
        G[v[i].F][v[i].S] = 'X';
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            cout<<G[i][j];
        cout<<endl;
    }
    return 0;

}
