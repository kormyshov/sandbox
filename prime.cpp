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

bool prime1(int n){
	int c=0;
	for(int i=1; i<=n; ++i)
		if(n % i == 0) ++c;
	return (c==2);
}
bool prime2(int n){
	int i;
	for(i=2; i<=sqrt(n); ++i)
		if(n % i == 0) break;
	return (n>1 && i>sqrt(n));
}
bool prime2_1(int n){
	int i;
	for(i=2; i*i <= n; ++i)
		if(n % i == 0) break;
	return (n>1 && i*i>n);
}
bool prime3(int n){
	bool f = (n>1 && (n&1)) || (n==2);
	for(int i=3; i*i <= n && f; i+=2)
		if(n % i == 0) f = false;
	return f;
}
bool prime4(int n){
	bool f = (n>1 && (n&1) && n%3) || (n==2) || (n==3);
	for(int i=5, k=4; i*i <= n && f; i+=k^=6)
		if(n % i == 0) f = false;
	return f;
}
int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	srand(time(0));
	clock_t t;
	vector<int> v;
	int s;
	for(int i=0;i<1000000;++i)
		v.push_back(rand()%1000000+1000000000);

	//t = clock();
	//s = 0;
	//for(int i=0; i<(int)v.size(); ++i){
		//s += prime1(v[i]) * v[i];
	//}
	//printf("Prime1 : %lf, sum : %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	t = clock();
	s = 0;
	for(int i=0; i<(int)v.size(); ++i){
		s += prime2(v[i]) * v[i];
	}
	printf("Prime2 : %lf, sum : %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	t = clock();
	s = 0;
	for(int i=0; i<(int)v.size(); ++i){
		s += prime2_1(v[i]) * v[i];
	}
	printf("Prime21: %lf, sum : %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	t = clock();
	s = 0;
	for(int i=0; i<(int)v.size(); ++i){
		s += prime3(v[i]) * v[i];
	}
	printf("Prime3 : %lf, sum : %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	t = clock();
	s = 0;
	for(int i=0; i<(int)v.size(); ++i){
		s += prime4(v[i]) * v[i];
	}
	printf("Prime4 : %lf, sum : %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, s);

	return 0;
}

int cpp4cf_main()
{
	freopen("prime.cpp","r",stdin);

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

