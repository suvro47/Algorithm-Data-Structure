#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define pb push_back

vector<int>G[sz],R[sz],Comp[sz];
stack<int>st;
int color[sz];
int vis[sz];
int no = 0;

void dfs(int u)
{
    color[u] = 1;
    for(auto v:G[u]){
        if( !color[v] )
            dfs(v);
    }
    st.push(u);
}

void dfs2(int u)
{
    Comp[no].pb(u);
    vis[u] = 1;
    for(auto v:R[u]){
        if( !vis[v] )
            dfs2(v);
    }
}

int main()
{

    int n,m,i,j;
    cin>>n>>m;
    int u,v;
    for(i=0; i<m; i++){
        cin>>u>>v;
        G[u].pb(v);
        R[v].pb(u);
    }

    for(u=1; u<=n; u++){
        if( !color[u] )
            dfs(u);
    }

    while(!st.empty()){
        u = st.top();
        if( !vis[u] ){
            no++;
            dfs2(u);
        }
        st.pop();
    }

    for(i=1; i<=no; i++){
        for(auto j:Comp[i])
            cout<<j<<' ';
        cout<<endl;
    }



    return 0;
}
