#include<bits/stdc++.h>
using namespace std;

char s[1001];
int n , taken[1001];
vector<char>res;

void permutation()
{
    if( res.size() == n ){
        for(auto j:res) cout<<j;
        cout<<endl;
        return;
    }

    for(int i=0; i<n ; i++){
        if( !taken[i] ){
            taken[i] = 1;
            res.push_back(s[i]);
            permutation();
            res.pop_back();
            taken[i] = 0;
            while( s[i] == s[i+1] ) i++;
        }
    }
}

int main()
{

    scanf("%s",s);
    n = strlen(s);
    sort(s,s+n);
    permutation();

    return 0;
}
