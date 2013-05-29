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
vector<int> heap, heap_p;
void heap_pop(vector<int> &d){
	heap_p[heap[1]] = 0;
	heap[1] = heap[heap[0]];
	heap[0]--;
	int t = heap[1], a = 1, mn;
	while(2*a <= heap[0]){
		mn = 2*a;
		if(mn+1<=heap[0] && d[heap[mn+1]] < d[heap[mn]]) mn++;
		if(d[heap[mn]] < d[t]){
			heap[a] = heap[mn];
			heap_p[heap[a]] = a;
			a = mn;
		}else break;
	}
	heap[a] = t;
	heap_p[t] = a;
}
void heap_relax(int v, vector<int> &d){
	if(heap_p[v] == 0) heap[++heap[0]] = v, heap_p[v] = heap[0];
	int a = heap_p[v];
	while(a>1)
		if(d[heap[a>>1]] > d[v]){
			heap[a] = heap[a>>1];
			heap_p[heap[a]] = a;
			a >>= 1;
		}else break;
	heap[a] = v;
	heap_p[v] = a;
}
vector<int> Dijkstra_cmp(int s){
	vector<int> d(N, INF2);
	d[s] = 0;
	heap.assign(N+1,0); heap[0] = 1; heap[1] = s;
	heap_p.assign(N, 0); heap_p[s] = 1;
	while(heap[0]){
		int v = heap[1];
		heap_pop(d);
		for(int j=0;j<(int)g[v].size();++j){
			int to = g[v][j].first,
				len = g[v][j].second;
			if(d[v]+len < d[to]){
				d[to] = d[v] + len;
				heap_relax(to, d);
			}
		}
	}
	return d;
}

vector<int> sqrt_d;
int sqrt_n;
void sqrt_init(int v){
	sqrt_n = max(1., sqrt(N*0.5));
	sqrt_d.assign(N/sqrt_n+1, INF2);
	sqrt_d[v/sqrt_n] = 0;
}
int sqrt_get(vector<int> &d, vector<int> &f){
	int v = -1, i, t=0, dt;
	for(i=1;i<(int)sqrt_d.size();++i)
		if(sqrt_d[t] > sqrt_d[i]) t=i;
	int l = t*sqrt_n, r = min(l+sqrt_n, N);
	dt = sqrt_d[t];
	sqrt_d[t] = INF2;
	for(i=l; i<r; ++i)
		if(!f[i]){
			if(dt==d[i]) f[i]=1, --dt, v=i;
			else sqrt_d[t] = min(sqrt_d[t], d[i]);
		}
	return v;
}
vector<int> Dijkstra_sqrt(int s){
	vector<int> d(N, INF2), f(N, 0);
	d[s] = 0;
	sqrt_init(s);
	int i, j, v, to, len;
	for(i=0;i<N;++i){
		v = sqrt_get(d, f);
		if(v<0 || d[v] >= INF2) break;
		for(j=0; j<(int)g[v].size(); ++j){
			to = g[v][j].first;
			len = g[v][j].second;
			if(d[v] + len < d[to]){
				d[to] = d[v] + len;
				if(sqrt_d[to/sqrt_n] > d[to])
					sqrt_d[to/sqrt_n] = d[to];
			}
		}
	}
	return d;
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
		res3 = Dijkstra_sqrt(i);
		//printf("%d ", res3[0]);// fflush(stdout);
	}
	printf("sqrt: %0.5lf\n", (clock()-st)/(double)CLOCKS_PER_SEC);

	//int fail = 0;
	//for(i=0;i<N;++i) if(res3[i] != res2[i]) fail++;
	//printf("Fail: %d", fail);

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


