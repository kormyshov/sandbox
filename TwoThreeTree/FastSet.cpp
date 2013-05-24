#include <iostream>
#include <cstdio>
#include <ctime>
#include <set>
#include <vector>
#include <cstdlib>

using namespace std;

template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

template<class T>
class FastSet{
	struct w{
		int n0, n1, n2;
		T k0, k1, k2;
	};
	vector<w> v;
	int sz, next, reserve, root;
public:
	FastSet(){
		reserve = next = sz = 0;
		root = -1;
	}
	FastSet(int n){
		v.resize(n);
		for(int i=0;i<n;++i)
			v[i].n0 = i+1;
		sz = next = 0;
		reserve = n;
	}
	int CreateNode(T &k){
		int i = next;
		if(next == reserve){
			w t;
			t.n0 = t.n1 = t.n2 = -1;
			t.k0 = k;
			v.push_back(t);
			next = ++reserve;
		}else{
			next = v[i].n0;
			v[i].n0 = v[i].n1 = v[i].n2 = -1;
			v[i].k0 = k;
		}
		sz++;
		return i;
	}
	bool insert(T& k){
		if(!sz){
			root = CreateNode(k);
			int tmp = CreateNode(k);
			v[root].n0 = tmp;
			return true;
		}
		if(v[root].n1 < 0){
			if(v[root].k0 < k){
				int tmp = CreateNode(k);
				v[root].n1 = tmp;
				v[root].k1 = k;
				return true;
			}else if(v[root].k0 > k){
				v[root].n1 = v[root].n0;
				v[root].k1 = v[root].k0;
				int tmp = CreateNode(k);
				v[root].n0 = tmp;
				v[root].k0 = k;
				return true;
			}else return false;
		}
		int tbk = -1;
		bool f = insert(root, k, tbk);
		if(f && tbk>=0){
			int rnew = CreateNode(v[root].k0);
			v[rnew].n0 = root;
			v[rnew].n1 = tbk;
			v[rnew].k1 = v[tbk].k0;
			root = rnew;
		}
		return f;
	}
	bool insert(int &t, T& k, int &tnew){
		if(t<0 || t>=sz) cout<<"oppa"<<endl;
		if(sz != (int)v.size()) cout<<"ppc"<<endl;
		tnew = -1;
		if(v[t].n0 < 0){
			if(v[t].k0 == k) return false;
			else{
				int tmp = CreateNode(k);
				tnew = tmp;
				return true;
			}
		}
		int w = v[t].n0, tbk = -1;
		if(k >= v[t].k1) w = v[t].n1;
		if(v[t].n2>=0 && k >= v[t].k2) w = v[t].n2;
		bool f = insert(w, k, tbk);
		if(tbk >= sz) cout<<"fail"<<endl;
		if(f){
			v[t].k0 = v[v[t].n0].k0;
			v[t].k1 = v[v[t].n1].k0;
			if(v[t].n2 >= 0)
				v[t].k2 = v[v[t].n2].k0;
			if(tbk >= 0){
				if(v[t].n2 >= 0){
					int tmp = CreateNode(v[tbk].k0);
					tnew = tmp;
					v[tnew].n1 = v[t].n2;
					v[tnew].k1 = v[t].k2;
					v[tnew].n0 = tbk;
					v[t].n2 = -1;
					if(v[t].k1 > v[tnew].k0){
						swap(v[tnew].n0, v[t].n1);
						swap(v[tnew].k0, v[t].k1);
					}
					if(v[t].k0 > v[t].k1){
						swap(v[t].n0, v[t].n1);
						swap(v[t].k0, v[t].k1);
					}
					if(v[tnew].k0 > v[tnew].k1){
						swap(v[tnew].n0, v[tnew].n1);
						swap(v[tnew].k0, v[tnew].k1);
					}
				}else{
					v[t].n2 = tbk;
					v[t].k2 = v[tbk].k0;
					if(v[t].k2 < v[t].k1){
						swap(v[t].n2, v[t].n1);
						swap(v[t].k2, v[t].k1);
					}
					if(v[t].k0 > v[t].k1){
						swap(v[t].n0, v[t].n1);
						swap(v[t].k0, v[t].k1);
					}
				}
			}
		}
		return f;
	}
	void print(){
		if(root >= 0)
			print(root, 0);
		else cout<<"Empty\n";
	}
	void print(int r, int t=0){
		if(r < 0) return ;
		for(int i=0;i<t;++i) cout<<"\t";
		cout<<v[r].k0<<","<<v[r].n0<<" ";
		if(v[r].n1 >= 0) cout<<v[r].k1<<","<<v[r].n1<<" ";
		if(v[r].n2 >= 0) cout<<v[r].k2<<","<<v[r].n2<<" ";
		cout<<endl;
		print(v[r].n0, t+1);
		print(v[r].n1, t+1);
		print(v[r].n2, t+1);
	}
};

int main(){
	int n = 1000000;
	FastSet<int> fs;
	/*cin>>n;*/
	/*for(int i=0;i<n;++i){*/
		/*int a;*/
		/*cin>>a;*/
		/*fs.insert(a);*/
		/*fs.print();*/
	/*}*/
	/*cin>>n;*/
	/*for(int i=0;i<n;++i){*/
		/*int a;*/
		/*cin>>a;*/
		/*T23_Delete(tree, a);*/
		/*T23_Print(tree);*/
	/*}*/

	srand(time(0));
	vector<int> v;
	for(int i=0;i<n;++i)
		v.push_back(rand());

	set<int> s;

	time_t t=clock();
	for(int i=0;i<(int)v.size();++i)
		s.insert(v[i]);
	printf("Set %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);

	t=clock();
	for(int i=0;i<(int)v.size();++i){
		/*cout<<i<<endl;*/
		fs.insert(v[i]);
	}
	printf("T23 %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);

	/*int sum=0;*/
	/*t=clock();*/
	/*for(int i=0;i<10*n;++i)*/
		/*sum += s.count(i);*/
	/*printf("Set %.6lf %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);*/

	/*sum=0;*/
	/*t=clock();*/
	/*for(int i=0;i<10*n;++i)*/
		/*sum += T23_Find(tree, i);*/
	/*printf("T23 %.6lf %d\n", (clock()-t)/(double)CLOCKS_PER_SEC, sum);*/

	/*t=clock();*/
	/*for(int i=0;i<(int)v.size();++i)*/
		/*s.erase(v[i]);*/
	/*printf("Set %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);*/

	/*t=clock();*/
	/*for(int i=0;i<(int)v.size();++i)*/
		/*T23_Delete(tree, v[i]);*/
	/*printf("T23 %.6lf\n", (clock()-t)/(double)CLOCKS_PER_SEC);*/

	/*T23_Print(tree);*/

	return 0;
}
