
/* root find out */

#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

double mysqrt(double x)
{
    double lb = 0;
    double ub = x;
    double mid;

    while( ub-lb >= EPS ){
        mid = (lb+ub)/2;
        if(mid*mid >= x) ub = mid;
        else lb = mid;
    }
    return mid;
}

int main()
{
    double n;
    cin>>n;
    cout<<mysqrt(n)<<endl;
}
