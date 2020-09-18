#include<bits/stdc++.h>
using namespace std;

#define sf scanf
#define pf printf
#define sz 100005
#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1e9 + 7

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;
typedef pair<ll,ll> pii;
typedef pair<char,ll> pci;
typedef pair<string,ll> psi;


vector< vector<ll> >  matMulti(vector< vector<ll> > mat1, vector< vector<ll> > mat2, ll M)
{
    ll r1 = mat1.size(), c1 = mat1[0].size(), c2 = mat2[0].size();
    vector< vector<ll> > res(r1,vector<ll>(c2,0));

    for(ll i=0; i<r1; i++){
        for(ll j=0; j<c2; j++){
            for(ll k=0; k<c1; k++)
                res[i][j] = ( (res[i][j]%M) + ( (mat1[i][k]%M)*(mat2[k][j]%M) ) %M ) % M;
        }
    }
    return res;
}


vector< vector<ll> >  bigMod(vector< vector<ll> > x, ll p, ll M)
{
    if(p==1) return x;

    if(p%2==0){
        vector< vector<ll> > y = bigMod(x, p/2, M);
        return matMulti(y, y, M);
    }
    else return matMulti( x, bigMod(x,p-1, M) , M);
}


int main()
{

    vector< vector<ll> > M(2,vector<ll>(2,0)), A(2,vector<ll>(1,0)), B(2,vector<ll>(1,0));

    /* Matrix for Fibonache sequence */

    M[0] = {1,1};
    M[1] = {1,0};

    /* Matrix A for Fibonache Sequence */

    A[0] = {1};
    A[1] = {0};


    ll n;

    cin>>n;

    B = matMulti( bigMod( M, n-1, MOD), A, MOD);

    cout<<B[0][0];


    return 0;
}
