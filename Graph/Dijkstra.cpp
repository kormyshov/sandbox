#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
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
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

vector<pair<int,int> > g[100500];
int N;

vector<int> Dijkstra_emax(int s){
	vector<int> d(N, INF2);//,  p(N);
	d[s] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;

		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				//p[to] = v;
				q.push (make_pair (-d[to], to));
			}
		}
	}
	return d;
}
vector<int> dijkstra_heap, dijkstra_heap_p, dijkstra_d;
void dijkstra_pop(){
	dijkstra_heap_p[dijkstra_heap[1]] = 0;
	dijkstra_heap[1] = dijkstra_heap[dijkstra_heap[0]--];
	int t = dijkstra_heap[1], a = 1, mn;
	while(2*a <= dijkstra_heap[0]){
		mn = 2*a;
		if(mn+1<=dijkstra_heap[0] &&
		   dijkstra_d[dijkstra_heap[mn+1]] < dijkstra_d[dijkstra_heap[mn]])
			mn++;
		if(dijkstra_d[dijkstra_heap[mn]] < dijkstra_d[t]){
			dijkstra_heap[a] = dijkstra_heap[mn];
			dijkstra_heap_p[dijkstra_heap[a]] = a;
			a = mn;
		}else break;
	}
	dijkstra_heap[a] = t;
	dijkstra_heap_p[t] = a;
}
void dijkstra_relax(int v){
	if(dijkstra_heap_p[v] == 0)
		dijkstra_heap[++dijkstra_heap[0]] = v, dijkstra_heap_p[v] = dijkstra_heap[0];
	int a = dijkstra_heap_p[v];
	while(a>1)
		if(dijkstra_d[dijkstra_heap[a>>1]] > dijkstra_d[v]){
			dijkstra_heap[a] = dijkstra_heap[a>>1];
			dijkstra_heap_p[dijkstra_heap[a]] = a;
			a >>= 1;
		}else break;
	dijkstra_heap[a] = v;
	dijkstra_heap_p[v] = a;
}
vector<int> Dijkstra_cmp(int s){
	dijkstra_d.assign(N, INF2);
	dijkstra_d[s] = 0;
	dijkstra_heap.assign(N+1,0);
	dijkstra_heap[0] = 1;
	dijkstra_heap[1] = s;
	dijkstra_heap_p.assign(N, 0);
	dijkstra_heap_p[s] = 1;
	while(dijkstra_heap[0]){
		int v = dijkstra_heap[1];
		dijkstra_pop();
		for(int j=0;j<(int)g[v].size();++j){
			int to = g[v][j].first,
				len = g[v][j].second;
			if(dijkstra_d[v]+len < dijkstra_d[to]){
				dijkstra_d[to] = dijkstra_d[v] + len;
				dijkstra_relax(to);
			}
		}
	}
	return dijkstra_d;
}

vector<int> dijkstra_f, dijkstra_sqrt_d;
int dijkstra_sqrt_n;

void dijkstra_init(int v){
	dijkstra_sqrt_n = max(1., sqrt(N*0.5));
	dijkstra_sqrt_d.assign(N/dijkstra_sqrt_n+1, INF2);
	dijkstra_sqrt_d[v/dijkstra_sqrt_n] = 0;
}

int dijkstra_get(){
	int v = -1, i, t=0, dt;
	for(i=1;i<(int)dijkstra_sqrt_d.size();++i)
		if(dijkstra_sqrt_d[t] > dijkstra_sqrt_d[i]) t=i;
	int l = t*dijkstra_sqrt_n, r = min(l+dijkstra_sqrt_n, N);
	dt = dijkstra_sqrt_d[t];
	dijkstra_sqrt_d[t] = INF2;
	for(i=l; i<r; ++i)
		if(!dijkstra_f[i]){
		if(dt==dijkstra_d[i]) dijkstra_f[i]=1, --dt, v=i;
		else dijkstra_sqrt_d[t] = min(dijkstra_sqrt_d[t], dijkstra_d[i]);
	}
	return v;
}

vector<int> Dijkstra(int s){
	dijkstra_d.assign(N, INF2);
	dijkstra_f.assign(N, 0);
	dijkstra_d[s] = 0;
	dijkstra_init(s);
	int i, j, v, to, len;
	for(i=0;i<N;++i){
		v = dijkstra_get();
		if(v<0 || dijkstra_d[v] >= INF2) break;
		for(j=0; j<(int)g[v].size(); ++j){
			to = g[v][j].first;
			len = g[v][j].second;
			if(dijkstra_d[v] + len < dijkstra_d[to]){
				dijkstra_d[to] = dijkstra_d[v] + len;
				if(dijkstra_sqrt_d[to/dijkstra_sqrt_n] > dijkstra_d[to])
					dijkstra_sqrt_d[to/dijkstra_sqrt_n] = dijkstra_d[to];
			}
		}
	}
	return dijkstra_d;
}

#define Ntest 1000
int main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	cin >> N;
	double x;
	cin >> x;
	int i, j, c;
	for(i=0;i<N;++i)
		for(j=i+1;j<N;++j)
			if(rand() < x*RAND_MAX){
				c = rand() % 100 + 1;
				g[i].push_back(make_pair(j, c));
				g[j].push_back(make_pair(i, c));
			}
	printf("Start test\n");
	fflush(stdout);

	clock_t st;
	st = clock();
	vector<int> res1;
	for(i=0;i<Ntest;i++){
		res1 = Dijkstra_emax(i);
		//printf("%d ", res1[0]);// fflush(stdout);
	}
	printf("emax: %0.5lf\n", (clock()-st)/(double)CLOCKS_PER_SEC);

	st = clock();
	vector<int> res2;
	for(i=0;i<Ntest;i++){
		res2 = Dijkstra_cmp(i);
		//printf("%d ", res2[0]);// fflush(stdout);
	}
	printf("cmp:  %0.5lf\n", (clock()-st)/(double)CLOCKS_PER_SEC);

	st = clock();
	vector<int> res3;
	for(i=0;i<Ntest;i++){
		res3 = Dijkstra(i);
		//printf("%d ", res3[0]);// fflush(stdout);
	}
	printf("sqrt: %0.5lf\n", (clock()-st)/(double)CLOCKS_PER_SEC);

	int fail = 0;
	for(i=0;i<N;++i) if(res3[i] != res2[i]) fail++;
	printf("Fail: %d", fail);

	return 0;
}

int cpp4cf_main()
{
	freopen("Dijkstra.cpp","r",stdin);

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


