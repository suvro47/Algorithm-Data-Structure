/* UVa 11503 */

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
typedef long long ll;

int parent[sz],cnt[sz];

void init_dsu(int n)
{
    for(int i=1; i<=n; i++){
        parent[i] = i;
        cnt[i] = 1;
    }
}

int FR(int r)  /// FR -> Find Representative
{
    if( parent[r] == r ) return r;
    parent[r] =  FR(parent[r]);
    return parent[r];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        init_dsu(sz);

        int F;
        cin>>F;

        string s1,s2;
        map< string , int > mp;
        int no = 1;

        for(int i=0; i<F; i++){
            cin>>s1>>s2;
            if( !mp[s1] ) mp[s1] = no++;
            if( !mp[s2] ) mp[s2] = no++;

            int a = mp[s1]; int b = mp[s2];

            if( FR(a) != FR(b) ){
                cnt[FR(a)] = cnt[FR(a)] + cnt[FR(b)];
                parent[FR(b)] = FR(a);
            }
            cout<<cnt[FR(a)]<<endl;

        }
    }

}

