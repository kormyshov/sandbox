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

template<typename T>
class PersistentStack{
	vector<T> v;
	vector<int> p;
	T null;
public:
	PersistentStack(T _null){
		null = _null;
		v.push_back(null);
		p.push_back(-1);
	}
	PersistentStack(int n, T _null){
		null = _null;
		v.reserve(n);
		p.reserve(n);
		v.push_back(null);
		p.push_back(-1);
	}

	bool empty(int n){
		return p[n] == -1;
	}
	T top(int n){
		return v[n];
	}
	void push(int n, const T& x){
		v.push_back(x);
		p.push_back(n);
	}
	void pop(int n){
		int t = p[n];
		if(t >= 0)
			v.push_back(v[t]),
			p.push_back(p[t]);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	PersistentStack<int> ps(-1);
	cin>>n;
	for(int i=0;i<n;++i){
		int a, b, c;
		cin>>a;
		if(a){
			cin>>b>>c;
		   	ps.push(b, c);
		}
		else {
			cin>>b;
			ps.pop(b);
		}
	}
	return 0;
}

int cpp4cf_main()
{
	freopen("PersistentStack.cpp","r",stdin);

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


