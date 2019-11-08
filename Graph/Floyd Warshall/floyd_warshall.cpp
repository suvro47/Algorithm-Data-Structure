#include<bits/stdc++.h>
using namespace std;

#define sz 100
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 10000007
#define INF 999999999

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;

ll n,e,u,v,w,s,d,i,j,k,Pcost[sz][sz],p[sz][sz];

void Floyd()
{
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if( Pcost[i][k] != INF && Pcost[k][j] != INF ){
                    if( Pcost[i][j] == INF || Pcost[i][j] > Pcost[i][k]+Pcost[k][j] ){
                        Pcost[i][j] = Pcost[i][k]+Pcost[k][j];
                        p[i][j] = p[k][j];
                    }
                }
            }
        }
    }
}

void pathPrint(int i,int j)
{
    if(i==j) return;
    pathPrint(i,p[i][j]);
    cout<<"-->"<<j;
}

void init_()
{
    for(i=1; i<sz; i++)
        for(j=1; j<sz; j++)
            Pcost[i][j] = p[i][j] = INF;

    for(i=1; i<sz; i++) Pcost[i][i] = 0;
}

int main()
{
    cin>>n>>e;

    init_();

    for(i=1;i<=e;i++){
        cin>>u>>v>>w;
        Pcost[u][v] = w;
        p[u][v] = u;
    }

    Floyd();

    cout<<endl<<"Minimum Distance among all Pairs ::"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(Pcost[i][j] != INF) cout<<Pcost[i][j]<<' ';
            else cout<<"X"<<' ';
        }
        cout<<endl;
    }

    cout<<endl<<"Next node to reach destination node ::"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(p[i][j] != INF) cout<<p[i][j]<<' ';
            else cout<<-1<<' ';
        }
        cout<<endl;
    }

    cin>>s>>d;
    cout<<s;
    pathPrint(s,d);

    return 0;
}


/*

sample input

4 6
0 1 3
0 2 6
0 3 15
1 2 -2
2 3 2
3 0 1

*/
