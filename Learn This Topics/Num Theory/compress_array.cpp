#include<bits/stdc++.h>
using namespace std;

#define sz 100005
int a[sz],com[sz];

map<int,bool>vis;
map<int,int>mp;

int main()
{
    int n,i,newval=0,x;
    cin>>n;

    for(i=0; i<n; i++) cin>>a[i];

    for(i=0; i<n; i++){

        x = a[i];

        if(vis[x]==false){
            mp[x]=newval;
            newval++;
            vis[x]=true;
        }
        com[i] = mp[x];

    }

    for(i=0; i<n; i++)
        cout<<com[i]<<endl;



    return 0;
}
