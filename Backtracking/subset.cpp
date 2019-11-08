
/*

   Input  : 3
   Output :
   1 2 3
   1 2
   1 3
   1
   2 3
   2
   3
*/

#include<bits/stdc++.h>
using namespace std;

#define sz 10001
typedef long long ll;

vector<int>res;
int n , taken[sz];

void subset(int last)
{
    for(int i=last+1; i<=n ; i++){
        if(!taken[i]){
            taken[i] = 1;
            res.push_back(i);
            subset(i);
            for(auto j:res) cout<<j<<' ';   /// in case of given array print array[j]
            cout<<endl;
            res.pop_back();
            taken[i] = 0;
        }
    }
}

int main()
{
    cin>>n;
    subset(0);

    return 0;
}
