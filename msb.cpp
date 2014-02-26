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

#define PI (3.1415926535897932384626433832795)
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
void dout(){cout<<endl;} template<typename Head, typename... Tail> void dout(Head H, Tail... T){cout<<H<<" "; dout(T...);}




inline int nmsb(unsigned int x) {
	union { double a; int b[2]; };
	a = x;
	return (b[1] >> 20) - 1023;
}
int _nmsb_m[256];
inline int nmsb5(unsigned int x){
	static bool _f;
	if(!_f)
	{
		_nmsb_m[0] = -1; _nmsb_m[1] = 0;
		for(int _i = 2; _i < 256; ++_i)
			_nmsb_m[_i] = _nmsb_m[_i >> 1] + 1;
		_f = true;
	}

	if(x >> 24 != 0) return _nmsb_m[x >> 24] + 24;
	if(x >> 16 != 0) return _nmsb_m[x >> 16] + 16;
	if(x >>  8 != 0) return _nmsb_m[x >>  8] +  8;
	return _nmsb_m[x];
}

inline int msb1(unsigned int x){
	union { double a; int b[2]; };
	a = x;
	return 1<<((b[1] >> 20) - 1023);
}

inline int msb2(unsigned int x){
	int t = 1 << 30;
	while(x < t) t >>= 1;
	return t;
}

inline int msb3(unsigned int x){
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x ^ (x >> 1);
}

inline int msb4(unsigned int x){
	int t = 1;
	if(x >= t << 16) t <<= 16;
	if(x >= t << 8) t <<= 8;
	if(x >= t << 4) t <<= 4;
	if(x >= t << 2) t <<= 2;
	if(x >= t << 1) t <<= 1;
	return t;
}

int _msb_m[256];
inline int msb5(unsigned int x){
	static bool _f;
	if(!_f)
	{
		_msb_m[0] = 0; _msb_m[1] = 1;
		for(int _i = 2; _i < 256; ++_i)
			_msb_m[_i] = _msb_m[_i >> 1] << 1;
		_f = true;
	}

	if(x >> 24 != 0) return _msb_m[x >> 24] << 24;
	if(x >> 16 != 0) return _msb_m[x >> 16] << 16;
	if(x >>  8 != 0) return _msb_m[x >>  8] <<  8;
	return _msb_m[x];
}

const int N = 1e8;

int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	srand(time(0));
	vector<int> v;
	for(int i=0;i<N;++i)
		v.push_back(rand());

	clock_t t;
	int s;

	//t = clock();
	//s=0;
	//for(int i=0;i<N;++i)
		//s += msb1(v[i]);
	//printf("msb1 : %.6lf, s = %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	//t = clock();
	//s=0;
	//for(int i=0;i<N;++i)
		//s += msb2(v[i]);
	//printf("msb2 : %.6lf, s = %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	//t = clock();
	//s=0;
	//for(int i=0;i<N;++i)
		//s += msb3(v[i]);
	//printf("msb3 : %.6lf, s = %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	//t = clock();
	//s=0;
	//for(int i=0;i<N;++i)
		//s += msb4(v[i]);
	//printf("msb4 : %.6lf, s = %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	//t = clock();
	//s=0;
	//for(int i=0;i<N;++i)
		//s += msb5(v[i]);
	//printf("msb5 : %.6lf, s = %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	t = clock();
	s=0;
	for(int i=0;i<N;++i)
		s += nmsb(v[i]);
	printf("nmsb  : %.6lf, s = %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	t = clock();
	s=0;
	for(int i=0;i<N;++i)
		s += nmsb5(v[i]);
	printf("nmsb5 : %.6lf, s = %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	return 0;
}

int cpp4cf_main()
{
	freopen("msb.cpp","r",stdin);

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

