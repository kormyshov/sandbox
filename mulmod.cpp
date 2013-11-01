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

LL mulmod1(LL a, LL b, LL m){
	if(a>m) a%=m;
	if(b>m) b%=m;
	LL k = (LL)((long double)a * b / m);
	LL r = a * b - m * k;
	while(r<0) r+=m;
	while(r>m) r-=m;
	return r;
}

LL mulmod2(LL a, LL b, LL m){
	if(a>m) a%=m;
	if(b>m) b%=m;
	LL t, x=0, y=a;
	while(b){
		if(b & 1){
			t = x + y;
			x = (t>m) ? t-m : t;
		}
		t = y << 1;
		y = (t>m) ? t-m : t;
		b >>= 1;
	}
	return x;
}

LL mulmod3(LL a, LL b, LL m){
	if(a>m) a%=m;
	if(b>m) b%=m;
	LL t;
	if(a<b){
		t=a; a=b; b=t;
	}
	LL x=0, y=a;
	while(b){
		if(b & 1){
			t = x + y;
			x = (t>m) ? t-m : t;
		}
		t = y << 1;
		y = (t>m) ? t-m : t;
		b >>= 1;
	}
	return x;
}

LL mulmod4(LL a, LL b, LL m){
	if(a>m) a%=m;
	if(b>m) b%=m;
	LL ret = 0;
	if(a<b) swap(a, b);
	while(b){
		while(a<m){
			if(b&1) ret += a;
			a <<= 1;
			b >>= 1;
		}
		a -= m;
		while(ret>m) ret -= m;
		if(a<b) swap(a, b);
	}
	return ret;
}
#define N 10000000
int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	srand(time(0));
	vector<LL> a, b, m;
	for(int i=0;i<N;++i){
		a.push_back((rand()*1LL<<31)|rand());
		b.push_back((rand()*1LL<<31)|rand());
		m.push_back((rand()*1LL<<31)|rand());
	}
	//cout<<a<<endl<<b<<endl<<m<<endl;

	clock_t t;
	LL sum;

	t=clock();
	sum=0;
	for(int i=0; i<(int)a.size(); ++i){
		sum += mulmod1(a[i], b[i], m[i]);
	}
	printf("mulmod1 : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	t=clock();
	sum=0;
	for(int i=0; i<(int)a.size(); ++i){
		sum += mulmod2(a[i], b[i], m[i]);
	}
	printf("mulmod2 : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	t=clock();
	sum=0;
	for(int i=0; i<(int)a.size(); ++i){
		sum += mulmod3(a[i], b[i], m[i]);
	}
	printf("mulmod3 : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	//t=clock();
	//sum=0;
	//for(int i=0; i<(int)a.size(); ++i){
		//sum += mulmod4(a[i], b[i], m[i]);
	//}
	//printf("mulmod4 : %lf %lld\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);

	return 0;
}

int cpp4cf_main()
{
	freopen("mulmod.cpp","r",stdin);

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

