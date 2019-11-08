#include<bits/stdc++.h>
using namespace std;

#define sz 1000001

int tree[sz];

int query(int idx)
{
    int sum =0;
    while(idx>0){
        sum+=tree[idx];
        idx =idx - (idx & -idx);
    }
    return sum;
}

void update(int idx,int x,int n)
{
    while(idx<=n){
        tree[idx] += x;
        idx = idx + (idx & -idx);
    }
}

int main()
{
    /* update index j by x & finding sum of 1 to i */

    int i,j,x;
    cin>>j>>x;
    update(j,x,16);

    cin>>i;
    cout<<query(i)<<endl;


    return 0;
}
