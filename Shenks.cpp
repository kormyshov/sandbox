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

inline int sqr(int a){
	return a*a;
}

int shenks(LL n){
	int d = (int)sqrt(n+.0);
	if(d*1LL*d == n) return d;
	if(n mod 4 == 1) n <<= 1;
	d = (int)sqrt(n+.0);
	int P0=0, Q0=1, r0, P1, Q1=n-r0*r0, r1=2*r0/Q1;
	P1 = r0 = d;
	int Pk, Qk, rk;
	do{
		Pk = r1*Q1-P1;
		Qk = Q0+(P1-Pk)*r1;
		rk = (Pk+d)/Qk;
		P0 = P1; P1 = Pk;
		Q0 = Q1; Q1 = Qk;
		r0 = r1; r1 = rk;
	}while(sqr((int)sqrt(Qk+.0))-Qk);
	P0 = -Pk;
	Q0 = (int)sqrt(Qk+.0);
	r0 = (P0+d)/Q0;
	P1 = r0*Q0-P0;
	Q1 =
}

int main()
{
	//ios_base::sync_with_stdio(0);

	return 0;
}

int cpp4cf_main()
{
	freopen("Shenks.cpp","r",stdin);

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

