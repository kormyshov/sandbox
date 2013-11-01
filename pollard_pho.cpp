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
#include <bitset>
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
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> &t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> &t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

inline LL mulmod(LL a, LL b, LL m)
{
	if(a>m) a%=m;
	if(b>m) b%=m;
	LL k = (LL)((long double)a * b / m);
	LL r = a * b - m * k;
	while(r<0) r+=m;
	while(r>m) r-=m;
	return r;
}
inline LL gcd(LL _a, LL _b)
{
	if(_a<0) _a=-_a;
	if(_b<0) _b=-_b;
	while(_a!=0 && _b!=0) if(_a > _b) _a%=_b; else _b%=_a;
	return _a+_b;
}
int pollard_pho1(LL n){
	LL x = rand()%(n-1);
	LL y = 1, t;
	int i = 0;
	int count = 10000;
	while(i<count && (t=gcd(n, ABS(x-y)))==1){
		if(!(i&(i-1))) y=x;
		x = mulmod(x, x, n);
		if(++x == n) x = 0;
		++i;
	}
	return t>1 && t<n && n%t==0;
}

LL pollard_pho2(LL n){
	LL b0 = rand()%n, b1 = b0, g;
	mulmod(b1, b1, n);
	if(++b1 == n) b1 = 0;
	g = gcd(ABS(b1-b0), n);
	int count = 10000;
	for(int i=0;i<count && (g==1 || g==n);++i){
		mulmod(b0, b0, n);
		if(++b0 == n) b0 = 0;
		mulmod(b1, b1, n);
		++b1;
		mulmod(b1, b1, n);
		if(++b1 == n) b1 = 0;
		g = gcd(ABS(b1-b0), n);
	}
	return g>1 && g<n && n%g==0;
}

#define N 3000
int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	srand(time(0));
	vector<LL> v;
	for(int i=0;i<N;++i)
		v.push_back((rand()*1LL<<31)|rand());

	clock_t t;
	LL sum;

	t=clock();
	sum=0;
	for(int i=0; i<(int)v.size(); ++i){
		sum += pollard_pho1(v[i]);
	}
	printf("pollard_pho1 : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	t=clock();
	sum=0;
	for(int i=0; i<(int)v.size(); ++i){
		int t, j=0;
		while(j<1 && (t=pollard_pho2(v[i]))==0) ++j;
		sum += t;
	}
	printf("pollard_pho2 : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	//t=clock();
	//sum=0;
	//for(int i=0; i<(int)v.size(); ++i){
		//sum += pollard_pho1(v[i])|pollard_pho2(v[i]);
	//}
	//printf("pollard_pho  : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	return 0;
}

int cpp4cf_main()
{
	freopen("pollard_pho.cpp","r",stdin);

	char s[99];
	bool f;

	while(true) {
		cin>>s;
		if(cin.eof()) break;
		if(strstr(s,"/*")) {
			cin>>s;
			if(strstr(s,"Test")) {
				cin>>s;
				if(strstr(s,"on")) {
					cout<<"Output: ";
					cpp4cf_main();
					cout<<"\nAnswer: ";
					f = false;
					while(true) {
						cin>>s;
						if(strstr(s,"*/")) break;
						if(strstr(s,"//")) {
							if(f) cout<<endl;
							else f = true;
						}else cout<<s<<" ";
					}
					cout<<"\n\n";
				}
			}
		}
	}

	return 0;
}

