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

bool perm_num(LL num, int *p, int n){
	if(num<1) return false;
	int i, j, k;
	bool m[100500];
	LL t = 1;
	memset(m, 1, sizeof(m));
	for(i=1; i<=n; ++i) {
		t *= i;
		if(t >= num){
			for(j=0; j<n-i; ++j) p[j]=j+1, m[j+1]=0;
			break;
		}
	}
	if(t<num) return false;
	--num;
	for(i=j; i<n; ++i){
		num -= t * (k = num / (t /= n-i));
		for(j=1; j<=n && k>=0; ++j) k -= m[j];
		m[ p[i] = --j ] = 0;
	}
	return true;
}

int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m[100500];
	LL r;
	cin>>n>>r;
	bool f = perm_num(r, m, n);
	if(f)
		for(int i=0;i<n;++i) cout<<m[i]<<' ';
	else
		cout<<-1;
	//for(int i=0;i<n;++i) cin>>m[i];

	//LL r=1, p=1;
	//for(int i=n-2, c=0;i>=0; p*=n-i--, c=0){
		//for(int j=i+1;j<n;++j) c += m[j] < m[i];
		//r += p*c;
	//}
	//cout<<r;
	return 0;
}

int cpp4cf_main()
{
	freopen("perm_num.cpp","r",stdin);

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

