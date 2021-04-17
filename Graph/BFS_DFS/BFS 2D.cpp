#include<bits/stdc++.h>
using namespace std;

#define sz 27
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


int n,m,i,j,k,vis[101][101];
char G[101][101];

int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void bfs(int a,int b)
{
    queue<pair<int,int>>Q;
    vis[a][b]=1;

    Q.push(mk(a,b));

    while(!Q.empty()){

        int x=Q.front().F;
        int y=Q.front().S;

        Q.pop();

        for(k=0 ; k<8; k++){
            int nx = x+dx[k];
            int my = y+dy[k];

            if(nx>=0 && nx<n && my>=0 && my<m && G[nx][my]=='@' && !vis[nx][my]){
                Q.push(mk(nx,my));
                vis[nx][my]=1;
            }
        }
    }
}

int main()
{
    while(1){
        int cnt=0;
        cin>>n>>m;

        memset(vis,0,sizeof(vis));

        if(m==0 && n==0) return 0;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                cin>>G[i][j];
        }

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(G[i][j]=='@' && !vis[i][j]){
                    bfs(i,j);
                    cnt++;
                }
            }
        }

        cout<<cnt<<endl;
    }


    return 0;
}

/* int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 }; 4D */
