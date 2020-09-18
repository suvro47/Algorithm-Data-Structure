/*
   12  = 1100 = 2^3+2^2+0+0
   10  = 1010 = 2^3+0+2^1+0
*/


#include<bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos)
{
    return (N & (1<<pos)); // if pos'th bit is 1 then  a value greater than 0 is returned otherwise 0 is returned
}

int main()
{
    int i,n;
    cin>>n;
    priority_queue<int>pq;

    for(i=0; i<=32; i++){
        if(CHECK(n,i))
            pq.push((1<<i));
    }

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}
