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

int n, m, N=0;

struct point{
	double m[3];
};

point mas[76800], pp;
int mi[76800], mj[76800];

int par;

void qs(int l, int r){
	double x = mas[l].m[par];
	int i=l, j=r;
	while(i<=j){
		while(x > mas[i].m[par]) ++i;
		while(x < mas[j].m[par]) --j;
		if(i<=j){
			swap(mas[i], mas[j]);
			swap(mi[i], mi[j]);
			swap(mj[i], mj[j]);
			++i; --j;
		}
	}
	if(l<j)qs(l, j);
	if(i<r)qs(i, r);
}

void build(int l, int r, int p){
	if(l==r) return ;
	par = p;
	qs(l, r);
	int mid = (l+r)>>1, t=(p+1)%3;
	build(l, mid, t);
	build(mid+1, r, t);
}

inline double sqr(double a){
	return a*a;
}

inline double len2(int i){
	return sqr(mas[i].m[0]-pp.m[0])+sqr(mas[i].m[1]-pp.m[1])+sqr(mas[i].m[2]-pp.m[2]);
}

int search(int l, int r, int p){

	if(l==r) return l;

	int mid = (l+r)>>1, res, tmp = (p+1)%3;
	double len;
	if(pp.m[p] <= mas[mid].m[p]){
		res = search(l, mid, tmp);
		len = len2(res);
		if(len >= sqr(mas[mid+1].m[p] - pp.m[p] + 50) - EPS){
			//cout<<"fail\n";
			int t = search(mid+1, r, tmp);
			if(len > len2(t))
				res = t;
		}
	}else{
		res = search(mid+1, r, tmp);
		len = len2(res);
		if(len >= sqr(pp.m[p] - mas[mid].m[p] + 50) - EPS){
			//cout<<"fail\n";
			int t = search(l, mid, tmp);
			if(len > len2(t))
				res = t;
		}
	}
	return res;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	int i, j, K;
	double tmp, t;
	tmp = (n+1)*0.5;
	for(i=0;i<n;++i){
		t = (tmp-i)/576;
		for(j=0;j<m;++j,++N){
			scanf("%lf", &mas[N].m[2]);
			if(mas[N].m[2] > EPS){
				mas[N].m[1] = t*mas[N].m[2];
				mas[N].m[0] = (j-(m+1)*0.5)/576 * mas[N].m[2];
				mi[N] = i+1; mj[N] = j+1;
			}else --N;
		}
	}

	//cout<<"read...ok\n";

	build(0, N-1, 0);

	//for(int i=0;i<N;++i) cout<<mas[i].m[0]<<" "<<mas[i].m[1]<<" "<<mas[i].m[2]<<endl;

	//cout<<"build...ok\n";

	scanf("%d", &K);
	for(i=0;i<K;++i){
		scanf("%lf%lf%lf", &pp.m[0], &pp.m[1], &pp.m[2]);
		j = search(0, N-1, 0);
		//if(i%10000 == 0)
			printf("%d %d\n", mi[j], mj[j]);
	}
	return 0;
}

