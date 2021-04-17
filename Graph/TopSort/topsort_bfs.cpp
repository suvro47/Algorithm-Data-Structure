#include<bits/stdc++.h>
#define     sf       scanf
#define     pf       printf
#define     ll       long long
#define     sz       100005
#define     pi       acos(-1.0)
#define     ff       first
#define     ss       second
#define     pb       push_back
#define     mp       make_pair
#define     all(x)   x.begin(),x.end()

using namespace std;

/*----------------- Start Here ---------------------*/

/*using inDegree
Graph should be one directional & have no loop*/

vector<int>vc[sz],topS;
queue<int>Q;
int indegree[sz],f;

void top_sort()
{
    while(!Q.empty()){
        int u=Q.front();
        topS.push_back(u);
        Q.pop();
        for(int i=0; i< vc[u].size(); i++){
            int v=vc[u][i];
            indegree[v]--;
            if(indegree[v]==0)
                Q.push(v);
        }
    }
}

int main()
{
    int n,e,u,v,i,j,k;
    cin>>n>>e;
    for(i=0;i<e;i++){
        cin>>u>>v;
        vc[u].pb(v);
        indegree[v]++;
    }

    for(u=0;u<n;u++){
        if(indegree[u]==0)
            Q.push(u);
    }

    top_sort();

    for(int i=0; i<topS.size(); i++)
        cout<<topS[i]<<endl;

    return 0;
}
