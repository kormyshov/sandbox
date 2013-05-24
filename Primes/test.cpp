#include <iostream>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <cmath>
#define tm varible_of_time
using namespace std;

int n = 10000000;
int pr[9000006], m;
int d[100000008];
bool p[100000008];

void pr_simple(){
	int i, j;

	m = 1;
	pr[0] = 2;
	for(i=3; i<=n; i+=2){
		bool mp = true;
		for(j=0; pr[j]*pr[j]<=i; ++j) if(i%pr[j]==0){
			mp = false;
			break;
		}
		if(mp) pr[m++] = i;
	}
}

void pr_erato(){
	memset(p, true, n+1);

	int i, j;
	m = 0;
	for(i=2; i<=n; ++i) if(p[i]){
		for(j=i*2; j<=n; j+=i) p[j] = false;
		pr[m++] = i;
	}
}

void pr_erato_fast(){
	memset(p, true, (n+1)/2+1);

	int i, j;
	m = 1;
	pr[0] = 2;
	for(i=3; i*i<=n; i+=2) if(p[i>>1]){
		for(j=i*i; j<=n; j+=i*2) p[j>>1] = false;
		pr[m++] = i;
	}
	for(; i<=n; i+=2) if(p[i>>1]) pr[m++] = i;
}

void pr_erato_divs(){
	memset(d, 0, 4*(n+1));

	int i, j;
	m = 1;
	pr[0] = 2;
	for(i=3; i<=n; i+=2){
		if(d[i]==0) d[i] = pr[m++] = i;
		for(j=0;j<m && pr[j]<=i && i*pr[j]<=n; ++j) d[i*pr[j]] = pr[j];
	}
}

void pr_erato_block(){
	int i, j, k, N, m2, M;
	for(N=1; (N+1)*(N+1)<=n; ++N);
	N += N&1;
	memset(p, true, N+1);
	memset(d, 0, 4*(N+1));
	m = 1;
	pr[0] = 2;
	for(i=3; i<=N; i+=2) if(p[i]){
		for(j=i*i; j<=N; j+=i*2) p[j] = false;
		d[m] = i*i;
		pr[m++] = i;
	}
	m2 = m;
	M = n/N;
	m = 1;
	for(k=0; k<=M; ++k){
		memset(p, true, N+1);
		for(i=1; i<m2; ++i){
			int &l = d[i];
			for(; l<N; l+=pr[i]*2) p[l] = false;
			l-=N;
		}
		if(!k) p[0] = p[1] = false;
		for(i=1; i<N && N*k+i<=n; i+=2) if(p[i]) pr[m++] = N*k + i;
	}
}

void pr_sundaram(){
	int n2 = (n-1)/2;
	memset(p, true, n2+1);

	int i, j;
	for(i=1; i*2+i*i*2<=n2; ++i)
	for(j=i*2+i*i*2; j<=n2; j+=2*i+1) p[j] = false;
	m = 1;
	pr[0] = 2;
	for(i=1; i<=n2; ++i) if(p[i]) pr[m++] = i*2+1;
}

void pr_sundaram_block(){
	int i, j, n2, N, M, q, k;
	n2 = (n-1)/2;
	for(N=1; (N+1)*(N+1)<=n2; ++N);
	memset(d, 0, 4*(N+1));

	for(q=1; q*2+q*q*2<=n2; ++q) d[q] = q*2+q*q*2;

	M = n2/N;
	m = 1;
	pr[0] = 2;
	for(k=0; k<=M; ++k){
		memset(p, true, N+1);
		for(i=1; i<q; ++i){
			int &l = d[i];
			for(; l<N; l+=i*2+1) p[l] = false;
			l-=N;
		}
		if(!k) p[0] = false;
		for(i=0;i<N && N*k+i<=n2;++i) if(p[i]) pr[m++] = (N*k+i)*2+1;
	}
}

void pr_atkin(){
	memset(p, false, n+1);
	int _sqrt, _i, _j, _i2 = 0, _a, _n=n;
	_sqrt = 2*(int)sqrt(_n);
	//for(_i=0; _i < _n; ++_i) p[_i] = 0;
	p[2] = p[3] = 1;
	for(_i=1; _i < _sqrt; _i+=2){
		_i2 += _i;
		_a = 4*_i2;
		for(_j=1; _a < _n; _j+=2){
			//if(_a%12 == 1 || _a%12 == 5)
				p[_a] ^= 1;
			_a += _j;
		}
		_a = 3*_i2;
		for(_j=1; _a < _n; _j+=2){
			if(_a%12 == 7)
				p[_a] ^= 1;
			_a += _j;
		}
		_a = 3*_i2;
		for(_j=1; _j < _i; _j+=2){
			_a -= _j;
			if(_a < _n)
				p[_a] ^= 1;
		}
	}
	_sqrt >>= 1;
	m = 2;
	pr[0] = 2;
	pr[1] = 3;
	int i,j,k;
	for(i=5, k=2; i<_sqrt; i+=k, k^=6) if(p[i]){
		pr[m++] = i;
		_a=i*i;
		for(j = _a; j<=n; j+=_a) p[j] = 0;
	}
	for(; i<=n; i+=k, k^=6) if(p[i]) pr[m++] = i;
}

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

	char pt[] = "1";
	long tm=0;
	int i;

	n=1e8;
	for(i=0;pt[i];i++){
		tm = clock();
		if(pt[i]=='1') pr_atkin(); else
		if(pt[i]=='2') pr_sundaram(); else
		if(pt[i]=='3') pr_sundaram_block(); else
		if(pt[i]=='4') pr_erato(); else
		if(pt[i]=='5') pr_erato_fast(); else
		if(pt[i]=='6') pr_erato_block(); else
		if(pt[i]=='7') pr_erato_divs();

		cout<<" == "<<clock()-tm<<" == "<<endl;
		cout<<m<<endl<<endl;
	}

	for(i=0;i<101;++i) cout<<i<<": "<<p[i]<<endl;

	return 0;
}
