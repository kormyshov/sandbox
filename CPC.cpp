#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <iomanip>
#include <pthread.h>
#include <semaphore.h>

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
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

double x[240][320], y[240][320], z[240][320];
int n, m;
vector<int> mm[240];

inline double sqr(double a){
	return a*a;
}

int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	int i, j, k;
	double t, a, b, c, r, tmp;
	tmp = (n+1)*0.5;
	for(i=0;i<n;++i){
		t = (tmp-i)/576;
		mm[i].reserve(m);
		for(j=0;j<m;++j){
			scanf("%lf", &z[i][j]);
			y[i][j] = t*z[i][j];
			if(z[i][j])
				mm[i].push_back(j);
		}
	}
	tmp = (m+1)*0.5;
	for(j=0;j<m;++j){
		t = (j-tmp)/576;
		for(i=0;i<n;++i)
			x[i][j] = t*z[i][j];
	}
	int K, ri, rj, ik;
	scanf("%d", &K);
	for(i=0;i<K;++i){
		scanf("%lf%lf%lf", &a, &b, &c);
		ri = rj = -1;
		r = 1e12;
		for(j=0;j<n;++j)
			for(ik=0;ik<mm[j].size();++ik){
				k = mm[j][ik];
				t = sqr(x[j][k]-a)+sqr(y[j][k]-b)+sqr(z[j][k]-c);
				if(t < r){
					ri = j;
					rj = k;
					r = t;
				}
			}
		printf("%d %d\n", ri+1, rj+1);
	}
	return 0;
}
