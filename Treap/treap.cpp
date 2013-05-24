#include <iostream>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct w{
	int x, y, n;
	w *l, *r, *p;
};
typedef w* pw;

void merge(pw &t, pw l, pw r){
	if(!l || !r) t = l ? l : r;
	else if(l->y < r->y)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
}

pw build(vector<pair<pair<int,int>,int> > &v){
	pw t, last, tmp;
	t = new w;
	t->x = v[0].first.first;
	t->y = v[0].first.second;
	t->n = v[0].second;
	t->l = t->r = t->p = NULL;
	last = t;
	for(int i=1;i<(int)v.size();++i){
		tmp = new w;
		tmp->x = v[i].first.first;
		tmp->y = v[i].first.second;
		tmp->n = v[i].second;
		tmp->l = tmp->r = tmp->p = NULL;
		while(last && last->y > tmp->y) last = last->p;
		if(!last){
			tmp->l = t;
			t->p = tmp;
			last = t = tmp;
		}else{
			tmp->l = last->r;
			if(last->r) last->r->p = tmp;
			last->r = tmp;
			tmp->p = last;
			last = tmp;
		}
	}
	return t;
}


vector<pair<int,pair<int,pw> > > res;
void print(pw t, int p){
	if(!t) return ;
	res.push_back(make_pair(t->n, make_pair(p, t)));
	print(t->l, t->n);
	print(t->r, t->n);
}

int main(){
	int N, a, b;
	scanf("%d", &N);
	pw t;
	vector<pair<pair<int,int>,int> > v;
	v.reserve(N);
	res.reserve(N);
	for(int i=0; i<N; ++i){
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(make_pair(a, b), i+1));
	}
	sort(v.begin(), v.end());
	t = build(v);

	cout<<"YES\n";

	print(t, 0);
	sort(res.begin(), res.end());
	for(int i=0;i<N;++i) {
		printf("%d ", res[i].second.first);
		t = res[i].second.second;
		if(t->l) printf("%d ", t->l->n); else printf("0 ");
		if(t->r) printf("%d ", t->r->n); else printf("0 ");
		cout<<endl;
	}

	return 0;
}
