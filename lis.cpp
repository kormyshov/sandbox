#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int rmq[1000500], d;
void rput(int i, int a){
	i += d;
	while(i){
		rmq[i] = max(rmq[i], a);
		i >>= 1;
	}
}
int rmax(int l, int r){
	l += d; r += d;
	int res = 0;
	while(l<r){
		if(l&1) res = max(res, rmq[l]);
		if(~r&1) res = max(res, rmq[r--]);
		l >>= 1;
		r >>= 1;
	}
	return max(res, rmq[l]);
}
void solve(){
	int n, a, k;
	scanf("%d%d", &n, &k);
	vector<pair<int,int> > v;
	for(int i=0;i<n;++i){
		scanf("%d", &a);
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	memset(rmq, 0, sizeof(rmq));
	d=1;
	int res=1;
	while(d<n)d<<=1;
	for(int i=0; i<(int)v.size(); ++i){
		int t = rmax(max(v[i].second-k, 0), v[i].second-1) + 1;
		if(t==1 && v[i].second>=k) t=0;
		else{
			rput(v[i].second, t);
			res = v[i].second;
		}
	}
	cout<<res+1<<endl;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
