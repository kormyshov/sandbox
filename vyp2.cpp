#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
 
#define FOR(a,b,c) for(int a=b;a<c;++a)
#define fill(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define sqr(a) (a)*(a)
 
int main() 
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long ax,bx,ay,by,cx,cy,n,t,fx,fy;
    bool r=0,l=0;
    cin>>n;
    cin>>bx>>by>>cx>>cy;
    fx=bx;fy=by;
    if (n==3) {cout<<"YES";return 0;}
    FOR(i,2,n+1) {
        ax=bx;ay=by;
        bx=cx;by=cy;
        if (i!=n) cin>>cx>>cy;
        else cx=fx,cy=fy; 
        t=(bx-ax)*(cy-by)-(by-ay)*(cx-bx);
        if (t>0) l=1;
        if (t<0) r=1;
        if (l&&r) {cout<<"NO";return 0;}
    }
    cout<<"YES";
    return 0;
}
