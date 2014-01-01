#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <iomanip>
//#include <pthread.h>
//#include <semaphore.h>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <algorithm>

#define ABS(a) ((a)<0?(-(a)):(a))
#define SIGN(a) (((a)>0)-((a)<0))
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define PI (3.1415926)
#define INF (2147483647)
#define LLINF (9223372036854775807LL)
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> t) {return O<<t.first<<" "<<t.second;}
template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<"\n";return O; }

int x0, y0;

LL kosoe(int ax, int ay, int bx, int by){
    return ax*1LL*by-ay*1LL*bx;
}

bool cmp(pair<int,int> a, pair<int,int> b){
    return kosoe(a.first-x0,a.second-y0,b.first-x0,b.second-y0) > 0 ||
        (kosoe(a.first-x0,a.second-y0,b.first-x0,b.second-y0)==0 && SQR(a.first-x0)+SQR(a.second-y0) > SQR(b.first-x0)+SQR(b.second-y0));
}

int main()
{
    //ios_base::sync_with_stdio(0);

	freopen("hull.in", "r", stdin);
	freopen("hull.out", "w", stdout);

    int n;
    scanf("%d", &n);
	if(n==1){cout<<"0.000000\n0.000000"; return 0;}
    vector<pair<int,int> > v, r;
    for(int _=0,_1,_2;_<n;++_){
        scanf("%d%d", &_1, &_2);
        v.push_back(make_pair(_1, _2));
    }
    int c=0;
    for(int i=0;i<n;++i)
        if(v[i].second < v[c].second || (v[i].second == v[c].second && v[i].first > v[c].first)) c = i;
    swap(v[c], v[0]);
    x0 = v[0].first; y0 = v[0].second;

    sort(v.begin()+1, v.end(), cmp);
	v.push_back(v[0]);

	//cout<<v<<endl;

    r.push_back(v[0]);
    r.push_back(v[1]);
    c=1;

    for(int i=2;i<=n;++i){
        while(c>1 && kosoe(r[c].first-r[c-1].first,r[c].second-r[c-1].second,v[i].first-r[c].first,v[i].second-r[c].second)<=0){
            r.pop_back();
            --c;
        }
        r.push_back(v[i]);
        ++c;
    }
	r.pop_back(); --c;
    //r.push_back(r[0]);++c;

	cout<<r.size()<<endl<<r;

    //long double p = 0;
    //for(int i=1;i<=c;++i)
        //p += sqrt(SQR(r[i].first-r[i-1].first)+SQR(r[i].second-r[i-1].second)+.0);
    //printf("%.9lf\n",(double)p);

	//long double s=0;
	//for(int i=1;i<=c;++i)
			//s += (r[i].first-r[i-1].first)*(r[i].second+r[i-1].second);
    //printf("%.9lf",(double)ABS(s)*0.5);

    return 0;
}

