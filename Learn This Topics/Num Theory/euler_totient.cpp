/* LightOj 10007 */

#include<bits/stdc++.h>
using namespace std;

#define M 50000006
typedef long long ll;


ll phi[M];

/// Euler’s Totient for all numbers upto M ///

void Totient()
{
    for(ll i=2; i<M; i++){

        if(phi[i]==0){
            phi[i]=i-1;

            for(ll j=i*2; j<M; j=j+i){
                if(phi[j]==0)
                    phi[j]=j;

                phi[j]=phi[j]-(phi[j]/i);
            }
        }
    }
}

/// Euler’s Totient for a single integer n ///

int totient(int n)
{
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    Totient();

    //for(int i=2; i<=20; i++)
        cout<<phi[12]<<endl;
        cout<<phi[10056]<<endl;

    return 0;
}


