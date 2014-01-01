#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct w{
    string f, i, d;
    int c;
    char b;
};

bool cmp(w a, w b){
   return a.c < b.c || (a.c == b.c && (a.b < b.b || (a.b == b.b && a.f < b.f)));
}

void solve(){
    int n;
    cin>>n;
    vector<w> v;
    w t;
    for(int i=0;i<n;++i){
        cin>>t.f>>t.i>>t.c>>t.b>>t.d;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0;i<n;++i)
        cout<<v[i].c<<v[i].b<<" "<<v[i].f<<" "<<v[i].i<<" "<<v[i].d<<endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int t;
	cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case "<<i<<":\n";
		solve();
	}

    return 0;
}
