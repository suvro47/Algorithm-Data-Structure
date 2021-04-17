#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define PI acos(-1.0)
#define MOD 10000007

int N,status[sz];

bool Check(int N,int pos)
{
    return (bool) (N & (1<<pos));
}

int Set(int N,int pos)
{
    return (N | (1<<pos));
}

void siv()
{
    int i,j,sqrtN;
    sqrtN = sqrt(N);
    for(int i=3; i<sqrtN; i+=2){
        if(Check(status[i/32],i%32) == 0){
            for(j=i*i; j<=N; j+=2*i)
                status[j/32] = Set(status[j/32],j%32);
        }
    }

    cout<<2<<endl;

    for(i=3; i<=N ; i+=2){
        if(Check(status[i/32],i%32) == 0){
            cout<<i<<endl;
        }
    }
}

int main()
{
    cin>>N;

    siv();

    return 0;
}

