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
#define $1 LL
inline $1 gcd($1 _a, $1 _b)
{
	if(_a<0) _a=-_a;
	if(_b<0) _b=-_b;
	while(_a!=0 && _b!=0) if(_a > _b) _a%=_b; else _b%=_a;
	return _a+_b;
}
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
LL powmod(LL a, LL b, LL m)
{
	if(a>m) a%=m;
	if(b>m) b%=m;
	LL r=1;
	while(b)
	{
		if(b&1) r = mulmod(r, a, m);
		a = mulmod(a, a, m);
		b >>= 1;
	}
	return r;
}
bool rabin($1 n){
	if(n==2) return true;
	if(n<2 || !(n&1)) return false;
	$1 q = n-1, a = 2+rand()%(n-2);
	if(powmod(a, n-1, n)!=1 || gcd(a, n)!=1) return false;
	while(!(q&1)) q>>=1;
	a = powmod(a, q, n);
	if(a!=1){
		while(a!=1 && a!=n-1) a = mulmod(a, a, n);
		if(a==1) return false;
	}
	return true;
}
bool rabin1($1 n){
	if(n==2) return true;
	if(n<2 || !(n&1)) return false;
	$1 q = n-1, a = 2+rand()%(n-2), t=0;
	if(powmod(a, n-1, n)!=1 || gcd(a, n)!=1) return false;
	while(!(q&1)) q>>=1, ++t;
	a = powmod(a, q, n);
	if(a==1 || a==n-1) return true;
	for(int i=1;i<t;++i){
		a = mulmod(a, a, n);
		if(a==n-1) return true;
	}
	return false;
}
inline bool isPrime($1 _n)
{
	if(_n<2 || (_n>2 && _n%2==0) || (_n>3 && _n%6%4!=1)) return false;
	for($1 _i=3; _i*_i<=_n; _i+=2)
		if(_n%_i==0) return false;
	return true;
}
#define N 1000000
int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	srand(time(0));
	int m[4];
	memset(m, 0, sizeof(m));
	for(int i=1;i<1000000;++i){
		int t1 = isPrime(i);
		int t2 = rabin1(i);
		if(t2) t2 &= rabin1(i);
		++m[t1<<1|t2];
	}
	for(int i=0;i<4;++i) cout<<m[i]<<" ";


	//vector<LL> v;
	//for(int i=0;i<N;++i)
		//v.push_back((rand()*1LL<<31)|rand());

	//clock_t t;
	//LL sum;

	//t=clock();
	//sum=0;
	//for(int i=0; i<(int)v.size(); ++i){
		//sum += rabin(v[i]);
	//}
	//printf("rabin : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	//t=clock();
	//sum=0;
	//for(int i=0; i<(int)v.size(); ++i){
		//sum += rabin1(v[i]);
	//}
	//printf("rabin1: %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	return 0;
}

int cpp4cf_main()
{
	freopen("rabin.cpp","r",stdin);

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

