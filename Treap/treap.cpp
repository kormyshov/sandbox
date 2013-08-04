#include <iostream>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct ct_node{
	int x, y;
	ct_node *l, *r;
    //ct_node *p;
};
typedef ct_node* p_ct_node;

void merge(p_ct_node &_t, p_ct_node _l, p_ct_node _r){
	if(!_l || !_r) _t = _l ? _l : _r;
	else if(_l->y < _r->y)
		merge(_l->r, _l->r, _r), _t = _l;
	else
		merge(_r->l, _l, _r->l), _t = _r;
}

void split(p_ct_node _t, int _x, p_ct_node &_l, p_ct_node &_r) {
	if (!_t)
		_l = _r = NULL;
	else if (_x < _t->x)
		split(_t->l, _x, _l, _t->l),  _r = _t;
	else
		split(_t->r, _x, _t->r, _r),  _l = _t;
}

p_ct_node search(p_ct_node &_t, int _x){
	if(!_t) return NULL;
	p_ct_node res;
	if(_x < _t->x){
		res = search(_t->l, _x);
		if(!res) return _t;
		else return res;
	}
	if(_x > _t->x) return search(_t->r, _x);
	return _t;
}

void insert(p_ct_node &_t, p_ct_node _it){
	if(!_t){
		_t = _it;
	}else if(_it->y > _t->y){
		split(_t, _it->x, _it->l, _it->r);
		_t = _it;
	}else
		insert(_it->x < _t->x ? _t->l : _t->r, _it);
}

void insert(p_ct_node &_t, int _x, int _y){
	p_ct_node _it = new ct_node;
	_it->x = _x; _it->y = _y;
	_it->l = _it->r = NULL;
	insert(_t, _it);
}

void insert(p_ct_node &_t, int _x){
	insert(_t, _x, rand());
}

//p_ct_node build(vector<pair<int,int> > &_v){
	//p_ct_node _t, _last, _tmp;
	//_t = new ct_node;
	//_t->x = _v[0].first;
	//_t->y = _v[0].second;
	//_t->l = _t->r = _t->p = NULL;
	//_last = _t;
	//for(int i=1;i<(int)_v.size();++i){
		//_tmp = new ct_node;
		//_tmp->x = _v[i].first;
		//_tmp->y = _v[i].second;
		//_tmp->l = _tmp->r = _tmp->p = NULL;
		//while(_last && _last->y > _tmp->y)
			//_last = _last->p;
		//if(!_last){
			//_tmp->l = _t;
			//_t->p = _tmp;
			//_last = _t = _tmp;
		//}else{
			//_tmp->l = _last->r;
			//if(_last->r) _last->r->p = _tmp;
			//_last->r = _tmp;
			//_tmp->p = _last;
			//_last = _tmp;
		//}
	//}
	//return _t;
//}
int main(){
	ios_base::sync_with_stdio(0);

	int n;
	cin>>n;
	char c;
	int a, p=0, tmp;
	p_ct_node ct = NULL;
	for(int i=0; i<n; ++i){
		cin>>c>>a;
		if(c=='?'){
			p_ct_node t = search(ct, a);
			if(!t) printf("-1\n"), p=-1;
			else printf("%d\n", t->x), p=t->x;
		}else{
			tmp = (a+p)%1000000000;
			p_ct_node t = search(ct, tmp);
			if(!t || t->x != tmp) insert(ct, tmp);
			p=0;
		}
	}

	return 0;
}
