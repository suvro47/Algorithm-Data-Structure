#include<bits/stdc++.h>
using namespace std;

const int sz = 2500006;
typedef long long ll;

int trie[sz][30], id , cnt[sz] , endMark[sz] , lev[sz] , vis[sz];

void add(string s)
{
    int cur = 0;
    for(int i=0; i<s.size(); i++){
        int ch = s[i]-'A';
        if(trie[cur][ch] == 0 ) trie[cur][ch] = ++id;
        cur = trie[cur][ch];
        cnt[cur]++;
    }
    endMark[cur] = 1;
}

int query(string s)
{
    int cur = 0;
    for(int i=0; i<s.size(); i++){
        int ch = s[i]-'0';
        if( trie[cur][ch] == 0 ) return 0;
        cur = trie[cur][ch];
    }
    return 1;
}

void bfs()
{
    int ans = 0;
    queue<int>Q;
    Q.push(0);
    vis[0] = 1;
    lev[0] = 0;

    while( !Q.empty() ){
        int cur = Q.front();
        Q.pop();
        for(int i=0; i<26; i++){
            int next_id = trie[cur][i];
            if( next_id && !vis[next_id] ){
                vis[next_id] = 1;
                lev[next_id] = lev[cur]+1;
                Q.push(next_id);
            }
        }
    }
}

void init()
{
    id = 0;
    memset(trie, 0 , sizeof trie);
    memset(cnt, 0 , sizeof cnt);
    memset(endMark, 0 , sizeof endMark);
    memset(lev, 0 , sizeof lev);
    memset(vis, 0 , sizeof vis);
}

int main()
{
    int T,tc=1;
    scanf("%d",&T);
    while(T--){
        init();
        string s;
        int n, i;
        scanf("%d",&n);
        for(i=0; i<n ;i++){
            cin>>s;
            add(s);
        }

        bfs();
    }


    return 0;
}
