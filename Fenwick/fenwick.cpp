#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <ctime>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define INF 2000000000

typedef long long LL;

using namespace std;

class Fenwick{
	int *m, N;
public:
	Fenwick(int n){
		N = n;
		m = new int[N];
		memset(m, 0, sizeof(int)*N);
	}
	Fenwick(int a[], int n){
		N = n;
		m = new int[N];
		memset(m, 0, sizeof(int)*N);
		for(int i=0;i<N;++i){
			m[i] += a[i];
			if((i|(i+1))<N) m[i|(i+1)] += m[i];
		}
	}
	Fenwick(vector<int> &a, int n){
		N = a.size();
		m = new int[N];
		memset(m, 0, sizeof(int)*N);
		for(int i=0;i<N;++i){
			m[i] += a[i];
			if((i|(i+1))<N) m[i|(i+1)] += m[i];
		}
	}
	void add(int i, int d){
		for(;i<N;i|=i+1) m[i] += d;
	}
	int sum(int i){
		int res = 0;
		for(;i>=0;i=(i&(i+1))-1) res += m[i];
		return res;
	}
	int sum(int l, int r){
		return sum(r) - sum(l-1);
	}
};

class FenwickAdd{
	int *m;
	int N, N2;
public:
	FenwickAdd(int n){
		N = n;
		N2 = N<<1;
		m = new int[N2];
		memset(m, 0, sizeof(int)*N2);
	}
	FenwickAdd(int a[], int n){
		N = n;
		N2 = N<<1;
		m = new int[N2];
		memset(m, 0, sizeof(int)*N2);
		for(int i=0;i<N;++i){
			m[i<<1] += a[i];
			if((i|(i+1))<N) m[(i|(i+1))<<1] += m[i<<1];
		}
	}
	FenwickAdd(vector<int> &a){
		N = a.size();
		N2 = N<<1;
		m = new int[N2];
		memset(m, 0, sizeof(int)*N2);
		for(int i=0;i<N;++i){
			m[i<<1] += a[i];
			if((i|(i+1))<N) m[(i|(i+1))<<1] += m[i<<1];
		}
	}
	void add(int i, int d){
		for(i<<=1;i<N2;i|=i+2) m[i] += d;
	}
	void add_range(int r, int d){
		if(r<0) return ;
		for(int i=(r<<1)|1;i>=0;i=(i&(i+2))-2) m[i] += d;
		for(int i=(r|(r+1))<<1;i<N2;i|=i+2) m[i] += d*(r-((i&(i+2))>>1)+1);
	}
	void add_range(int l, int r, int d){
		add_range(r, d);
		add_range(l-1, -d);
	}
	int sum(int r){
		if(r<0) return 0;
		int res = 0;
		for(int i=r<<1;i>=0;i=(i&(i+2))-2) res += m[i] + m[i|1]*((i-(i&(i+2))+2)>>1);
		for(int i=(r|(r+1))<<1;i<N2;i|=i+2) res += m[i|1]*(((r<<1)-(i&(i+2))+2)>>1);
		return res;
	}
	int sum(int l, int r){
		return sum(r) - sum(l-1);
	}
	void print(){
		cout<<"m:  ";
		for(int i=0;i<N2;i+=2) cout<<m[i]<<" ";
		cout<<"\nmt: ";
		for(int i=1;i<N2;i+=2) cout<<m[i]<<" ";
		cout<<endl;
	}
};

class FenwickAdd_{
	int *m, *mt;
	int N;
public:
	FenwickAdd_(int n){
		N = n;
		m = new int[N];
		mt = new int[N];
		memset(m, 0, sizeof(int)*N);
		memset(mt, 0, sizeof(int)*N);
	}
	FenwickAdd_(int a[], int n){
		N = n;
		m = new int[N];
		mt = new int[N];
		memset(m, 0, sizeof(int)*N);
		memset(mt, 0, sizeof(int)*N);
		for(int i=0;i<N;++i){
			m[i] += a[i];
			if((i|(i+1))<N) m[i|(i+1)] += m[i];
		}
	}
	FenwickAdd_(vector<int> &a){
		N = a.size();
		m = new int[N];
		mt = new int[N];
		memset(m, 0, sizeof(int)*N);
		memset(mt, 0, sizeof(int)*N);
		for(int i=0;i<N;++i){
			m[i] += a[i];
			if((i|(i+1))<N) m[i|(i+1)] += m[i];
		}
	}
	void add(int i, int d){
		for(;i<N;i|=i+1) m[i] += d;
	}
	void add_range(int r, int d){
		if(r<0) return ;
		for(int i=r;i>=0;i=(i&(i+1))-1) mt[i] += d;
		for(int i=r|(r+1);i<N;i|=i+1) m[i] += d*(r-(i&(i+1))+1);
	}
	void add_range(int l, int r, int d){
		add_range(r, d);
		add_range(l-1, -d);
	}
	int sum(int r){
		if(r<0) return 0;
		int res = 0;
		for(int i=r;i>=0;i=(i&(i+1))-1) res += m[i] + mt[i]*(i-(i&(i+1))+1);
		for(int i=r|(r+1);i<N;i|=i+1) res += mt[i]*(r-(i&(i+1))+1);
		return res;
	}
	int sum(int l, int r){
		return sum(r) - sum(l-1);
	}
	void print(){
		cout<<"m:  ";
		for(int i=0;i<N;++i) cout<<m[i]<<" ";
		cout<<"\nmt: ";
		for(int i=0;i<N;++i) cout<<mt[i]<<" ";
		cout<<endl;
	}
};

class FenwickMinAdd{
	int *md, *mu, *ad, *au, N;
public:
	FenwickMinAdd(int n){
		N = n;
		md = new int[N];
		mu = new int[N];
		ad = new int[N];
		au = new int[N];
		memset(md, 127, sizeof(int)*N);
		memset(mu, 127, sizeof(int)*N);
		memset(au, 0, sizeof(int)*N);
		memset(ad, 0, sizeof(int)*N);
	}
	FenwickMinAdd(int a[], int n){
		N = n;
		md = new int[N];
		mu = new int[N];
		ad = new int[N];
		au = new int[N];
		memset(md, 127, sizeof(int)*N);
		memset(mu, 127, sizeof(int)*N);
		memset(ad, 0, sizeof(int)*N);
		memset(au, 0, sizeof(int)*N);
		for(int i=N-1, t=i&(i-1);i>0;--i, t=i&(i-1)){
			if(md[i]>a[i]) md[i]=a[i];
			if(t>0 && md[t]>md[i]) md[t]=md[i];
		}
		for(int i=0, t=i|(i+1);i<N;++i, t=i|(i+1)){
			if(mu[i]>a[i]) mu[i]=a[i];
			if(t<N && mu[t]>mu[i]) mu[t]=mu[i];
		}
	}
	FenwickMinAdd(vector<int> &a){
		N = a.size();
		md = new int[N];
		mu = new int[N];
		ad = new int[N];
		au = new int[N];
		memset(md, 127, sizeof(int)*N);
		memset(mu, 127, sizeof(int)*N);
		memset(ad, 0, sizeof(int)*N);
		memset(au, 0, sizeof(int)*N);
		for(int i=N-1, t=i&(i-1);i>0;--i, t=i&(i-1)){
			if(md[i]>a[i]) md[i]=a[i];
			if(t>0 && md[t]>md[i]) md[t]=md[i];
		}
		for(int i=0, t=i|(i+1);i<N;++i, t=i|(i+1)){
			if(mu[i]>a[i]) mu[i]=a[i];
			if(t<N && mu[t]>mu[i]) mu[t]=mu[i];
		}
	}
	void relax(int n, int d){
		int s = 0;
		for(int i=n;i<N;i|=i+1) s += au[i];
		for(int i=n;i<N;i|=i+1){
			if(mu[i]+s > d) mu[i] = d-s;
			s -= au[i];
		}
		s = 0;
		for(int i=n;i>0;i&=i-1) s += ad[i];
		for(int i=n;i>0;i&=i-1){
			if(md[i]+s > d) md[i] = d-s;
			s -= ad[i];
		}
	}
	int min(int l, int r){
		int ru=INF, rd=INF, to;
		if(!l){
			for(int j=r;r>=0;r=to-1){
				if(ru>mu[r]+au[r]) ru=mu[r]+au[r];
				to = (r&(r+1));
				while(j<N && to<=(j&(j+1))){
					ru += au[j];
					j |= j+1;
				}
			}
			return ru;
		}
		for(int j=r;(r&(r+1))>=l;r=to-1){
			if(ru>mu[r]+au[r]) ru=mu[r]+au[r];
			to = (r&(r+1));
			while(j<N && to<=(j&(j+1))){
				ru += au[j];
				j |= j+1;
			}
		}
		for(int j=l;(l|(l-1))<=r;l=to+1){
			if(rd>md[l]+ad[l]) rd=md[l]+ad[l];
			to = (l|(l-1));
			while(j>0 && to>=(j|(j-1))){
				rd += ad[j];
				j &= j-1;
			}
		}
		return std::min(ru, rd);
	}
	void addu(int r, int d){
		int to, m = INF, i, j;
		for(i=j=r;i<N;i=to){
			to = i|(i+1);
			for(;j>(to&(to+1))-1;j=(j&(j+1))-1){
				au[j] += d;
				if(m>mu[j]+au[j]) m = mu[j]+au[j];
			}
			if(to<N) mu[to] = MIN(m, md[i+1]+ad[i+1])-au[to];
		}
		for(;j>=0;j=(j&(j+1))-1) au[j] += d;
	}
	void addd(int l, int d){
		int to, m = INF, i, j;
		for(i=j=l;i>0;i=to){
			to = i&(i-1);
			for(;j<(to|(to-1))+1;j=(j|(j-1))+1){
				ad[j] += d;
				if(m>md[j]+ad[j]) m = md[j]+ad[j];
			}
			if(to>0) md[to] = MIN(m, mu[i-1]+au[i-1])-ad[to];
		}
	}
	void add(int l, int r, int d){
		addu(r, d);
		addd(r+1, -d);
		addu(l-1, -d);
		addd(l, d);
	}
	void add(int n, int d){
		if(d<0){
			d += (n&1 ? md[n] : mu[n]);
			relax(n, d);
			return ;
		}
		int t, to, tmp;
		if(n&1){
			md[n] += d;
			t = md[n];
			to = (n&(n+1))-1;
			for(int i=n-1; i>=0 && i>to; i=(i&(i+1))-1)
				if(t>mu[i]) t = mu[i];
			mu[n] = t;
		}else{
			mu[n] += d;
			t = mu[n];
			to = (n|(n-1))+1;
			for(int i=n+1; i<N && i<to; i=(i|(i-1))+1)
				if(t>md[i]) t = md[i];
			md[n] = t;
		}
		t = mu[n];
		for(int i=n, j=n; i<N; i=to){
			if(i+1<N && t>md[i+1]) t = md[i+1];
			to = i|(i+1);
			tmp = (to&(to+1))-1;
			for(;j>tmp;j=(j&(j+1))-1)
				if(t>mu[j]) t = mu[j];
			if(to<N && mu[to]<t) mu[to] = t;
			else break;
		}
		t = md[n];
		for(int i=n, j=n; i>0; i=to){
			if(t>mu[i-1]) t = mu[i-1];
			to = i&(i-1);
			tmp = (to|(to-1))+1;
			for(;j<tmp;j=(j|(j-1))+1)
				if(j<N && t>md[j]) t = md[j];
			if(to>0 && md[to]<t) md[to] = t;
			else break;
		}
	}
};

class RSQAdd{
	int *m, *mt;
	int N;
public:
	RSQAdd(int n){
		N = n;
		m = new int[4*N];
		mt = new int[4*N];
		memset(m, 0, sizeof(int)*4*N);
		memset(mt, 0, sizeof(int)*4*N);
	}
	RSQAdd(int a[], int n){
		N = n;
		m = new int[4*N];
		mt = new int[4*N];
		init(a, 1, 0, N-1);
		memset(mt, 0, sizeof(int)*4*N);
	}
	RSQAdd(vector<int> &v){
		N = v.size();
		m = new int[4*N];
		mt = new int[4*N];
		init(v, 1, 0, N-1);
		memset(mt, 0, sizeof(int)*4*N);
	}
	void init(int a[], int v, int vl, int vr){
		if(vl==vr){
			m[v] = a[vl];
			return ;
		}
		int mid = (vl+vr)>>1;
		init(a, v<<1, vl, mid);
		init(a, v<<1|1, mid+1, vr);
		m[v] = m[v<<1] + m[v<<1|1];
	}
	void init(vector<int> &a, int v, int vl, int vr){
		if(vl==vr){
			m[v] = a[vl];
			return ;
		}
		int mid = (vl+vr)>>1;
		init(a, v<<1, vl, mid);
		init(a, v<<1|1, mid+1, vr);
		m[v] = m[v<<1] + m[v<<1|1];
	}
	void add(int i, int d){
		int mid, v=1, vl=0, vr=N-1;
		while(vl!=i || vr!=i){
			m[v] += d;
			mid = (vl+vr)>>1;
			if(i<=mid) v<<=1, vr=mid;
			else v=v<<1|1, vl=mid+1;
		}
		m[v] += d;
	}
	void add(int l, int r, int d){
		add(l, r, d, 1, 0, N-1);
	}
	void add(int l, int r, int d, int v, int vl, int vr){
		if(l>r) return ;
		if(l<=vl && r>=vr){
			mt[v] += d;
			m[v] += d*(r-l+1);
			return ;
		}
		int mid = (vl+vr)>>1;
		add(l, MIN(r, mid), d, v<<1, vl, mid);
		add(MAX(l, mid+1), r, d, v<<1|1, mid+1, vr);
		m[v] += d*(r-l+1);
	}
	int sum(int l, int r){
		return sum(l, r, 1, 0, N-1);
	}
	int sum(int l, int r, int v, int vl, int vr){
		if(l>r) return 0;
		if(l<=vl && r>=vr) return m[v];
		int mid = (vl+vr)>>1;
		return sum(l, MIN(r, mid), v<<1, vl, mid)
			 + sum(MAX(l, mid+1), r, v<<1|1, mid+1, vr)
			 + mt[v]*(r-l+1);
	}
	int ind_with_sum(int s){
		int v=1, vl=0, vr=N-1, mid;
		while(vl < vr){
			mid = (vl+vr)>>1;
			v<<=1;
			if(m[v] >= s) vr=mid;
			else s-=m[v], v|=1, vl=mid+1;
		}
		return vl;
	}
};

#define NMAX 10000000
#define NQuery 10000000

int main(){
	vector<int> l, r;
	int a, b;
	srand(100886);
	for(int i=0;i<NQuery;++i){
		a = rand()%NMAX;
		b = rand()%NMAX;
		if(a>b) swap(a, b);
		l.push_back(a);
		r.push_back(b);
	}

	time_t st;
	st = clock();
	RSQAdd R(l);
	printf("RSQ OK, time = %.8lf\n", (double)(clock()-st)/CLOCKS_PER_SEC);
	st = clock();
	FenwickAdd_ F(l);
	printf("Fen OK, time = %.8lf\n", (double)(clock()-st)/CLOCKS_PER_SEC);
	st = clock();
	FenwickAdd f(l);
	printf("Fen OK, time = %.8lf\n", (double)(clock()-st)/CLOCKS_PER_SEC);

	st = clock();
	for(int i=0;i<NQuery;++i)
		R.add(l[i], r[i], 1);
	printf("RSQ OK, time = %.8lf\n", (double)(clock()-st)/CLOCKS_PER_SEC);

	st = clock();
	for(int i=0;i<NQuery;++i)
		F.add_range(l[i], r[i], 1);
	printf("Fen OK, time = %.8lf\n", (double)(clock()-st)/CLOCKS_PER_SEC);

	st = clock();
	for(int i=0;i<NQuery;++i)
		f.add_range(l[i], r[i], 1);
	printf("Fen OK, time = %.8lf\n", (double)(clock()-st)/CLOCKS_PER_SEC);

	l.clear();
	r.clear();
	for(int i=0;i<NQuery;++i){
		a = rand()%NMAX;
		b = rand()%NMAX;
		if(a>b) swap(a, b);
		l.push_back(a);
		r.push_back(b);
	}

	LL sum=0;
	st = clock();
	for(int i=0;i<NQuery;++i)
		sum += R.sum(l[i], r[i]);
	printf("RSQ OK, time = %.8lf, sum = %lld\n", (double)(clock()-st)/CLOCKS_PER_SEC, sum);

	sum=0;
	st = clock();
	for(int i=0;i<NQuery;++i)
		sum += F.sum(l[i], r[i]);
	printf("Fen OK, time = %.8lf, sum = %lld\n", (double)(clock()-st)/CLOCKS_PER_SEC, sum);

	sum=0;
	st = clock();
	for(int i=0;i<NQuery;++i)
		sum += f.sum(l[i], r[i]);
	printf("Fen OK, time = %.8lf, sum = %lld\n", (double)(clock()-st)/CLOCKS_PER_SEC, sum);

	return 0;
}
