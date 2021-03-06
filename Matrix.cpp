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

#define $1 double

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

class Matrix{
	//vector<vector<${1:int}> > mm;
	vector<vector<$1> > mm;
	int N, M;
public:
	inline Matrix(int _N, int _M){
		N = _N; M = _M;
		mm.assign(N, vector<$1>(M, 0));
	}
	inline Matrix(const Matrix &a){
		N = a.get_N(); M = a.get_M();
		mm = a.get_mm();
	}

	inline int get_N() const {return N;}
	inline int get_M() const {return M;}
	inline vector<vector<$1> > get_mm() const {return mm;}
	inline $1 get_mm(int n, int m) const {return mm[n][m];}

	inline void set(const Matrix &a){
		N = a.get_N(); M = a.get_M();
		mm = a.get_mm();
	}
	inline void setE(int _N){
		N = M = _N;
		mm.assign(N, vector<$1>(M, 0));
		for(int i=0; i<N; ++i) mm[i][i] = 1;
	}

	inline Matrix& operator=(const Matrix &a){
		set(a);
		return *this;
	}

	inline Matrix T() const {
		Matrix r(M, N);
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				r[j][i] = mm[i][j];
		return r;
	}

	inline $1 det() const {
		if(N != M) return ($1)0;
		Matrix a(*this);
		$1 res = 1;
		for(int i=0; i<N; ++i){
			int j;
			if(!a[i][i]){
				for(j=i; j<N; ++j)
					if(a[j][i]){
						swap(a[i], a[j]);
						res = -res;
						break;
					}
				if(j == N) return 0;
			}
			for(j=i+1; j<N; ++j){
				if(j < N-1) res *= a[i][i];
				for(int k=N-1; k>=i; --k)
					a[j][k] = a[j][k] * a[i][i] - a[i][k] * a[j][i];
			}
		}
		return a[N-1][N-1] / res;
	}

	inline Matrix inverse() const {
		if(N != M) return *this;
		Matrix a(N, 2*N);
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j)
				a[i][j] = mm[i][j];
			a[i][i+N] = 1;
		}
		for(int i=0; i<N; ++i){
			int j;
			if(ABS(a[i][i]) < EPS){
				for(j=i; j<N; ++j)
					if(a[j][i]){
						swap(a[i], a[j]);
						break;
					}
				if(j == N) return *this;
			}
			for(j=2*N-1; j>=i; --j) a[i][j] /= a[i][i];
			for(j=i+1; j<N; ++j)
				for(int k=2*N-1; k>=i; --k)
					a[j][k] -= a[i][k] * a[j][i];
		}
		for(int i=N-1; i>0; --i)
			for(int j=i-1; j>=0; --j)
				for(int k=2*N-1; k>=i; --k)
					a[j][k] -= a[i][k] * a[j][i];

		Matrix res(N, N);
		for(int i=0; i<N; ++i)
			for(int j=0; j<N; ++j)
				res[i][j] = a[i][j+N];
		return res;
	}

	inline Matrix operator+=(const Matrix &a){
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				mm[i][j] += a.get_mm(i, j);
		return *this;
	}
	inline Matrix operator+(const Matrix &a) const {
		Matrix res(*this);
		res += a;
		return res;
	}

	inline Matrix operator-=(const Matrix &a){
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				mm[i][j] -= a.get_mm(i, j);
		return *this;
	}
	inline Matrix operator-(const Matrix &a) const {
		Matrix res(*this);
		res -= a;
		return res;
	}
	inline Matrix operator-() const {
		Matrix a(*this);
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				a[i][j] = -a[i][j];
		return a;
	}

	inline Matrix operator*(const Matrix &a) const {
		Matrix r(N, a.get_M());
		for(int i=0; i<N; ++i)
			for(int j=0; j<a.get_M(); ++j)
				for(int k=0; k<M; ++k)
					r[i][j] += mm[i][k] * a.get_mm(k, j);
		return r;
	}
	inline Matrix operator*=(const Matrix &a){
		set(*this * a);
		return *this;
	}

	inline Matrix operator*=(const $1 k){
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				mm[i][j] *= k;
		return *this;
	}
	inline Matrix operator*(const $1 k) const {
		Matrix res(*this);
		res *= k;
		return res;
	}

	inline Matrix operator&(const Matrix &a) const {
		Matrix r(N, a.get_M());
		for(int i=0; i<N; ++i)
			for(int j=0; j<a.get_M(); ++j)
				for(int k=0; k<M; ++k)
					r[i][j] = (LL)(r[i][j] + mm[i][k] * 1LL * a.get_mm(k, j)) % MOD;
		return r;
	}
	inline Matrix operator&=(const Matrix &a){
		set(*this * a);
		return *this;
	}

	inline Matrix operator%(const Matrix &a) const {
		Matrix r(N, a.get_M());
		for(int i=0; i<N; ++i)
			for(int j=0; j<a.get_M(); ++j){
				LL t = 0;
				for(int k=0; k<M; ++k)
					t += mm[i][k] * 1LL * a.get_mm(k, j);
				r[i][j] = t % MOD;
			}
		return r;
	}
	inline Matrix operator%=(const Matrix &a){
		set(*this * a);
		return *this;
	}

	inline vector<$1>& operator[](int n){
		return mm[n];
	}

	friend istream& operator>>(istream& in, Matrix &a){
		for(int i=0; i<a.get_N(); ++i)
			for(int j=0; j<a.get_M(); ++j)
				in>>a[i][j];
		return in;
	}
	friend ostream& operator<<(ostream& out, const Matrix &a){
		for(int i=0; i<a.get_N(); ++i){
			for(int j=0; j<a.get_M(); ++j)
				out<<a.get_mm(i, j)<<" ";
			out<<endl;
		}
		return out;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);

	Matrix a(3, 3);
	cin>>a;
	Matrix b(3, 3);
	b = a.inverse();
	cout<<a.det()<<endl;
	cout<<b;
	cout<<a*b;

	return 0;
}

int cpp4cf_main()
{
	freopen("Matrix.cpp","r",stdin);

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


