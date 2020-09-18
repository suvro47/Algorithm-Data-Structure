#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(),x.end()

struct data{
    int h,w;
    double in;

    data(int _h,int _w,double _in){
        h=_h;
        w=_w;
        in=_in;
    }

    /*
    bool operator < (const data &d)const{
        if(in==d.in){
            if(h==d.h)
                return w<d.w;
            return h>d.h;
        }
        return in>d.in;
    }
    */
};

bool comp(data A,data B)
{
    if(A.in==B.in){
        if(A.h==B.h)
            return A.w<B.w;
        return A.h>B.h;
    }
    return A.in>B.in;
}

int main()
{
    vector<data>v;
    int h,w;
    double in;
    for(int i=0;i<3;i++){
        cin>>h>>w>>in;
        v.pb(data(h,w,in));
    }
    sort(all(v),comp);

    for(int i=0;i<sz(v);i++)
        cout<<v[i].h<<' '<<v[i].w<<' '<<v[i].in<<endl;
}
