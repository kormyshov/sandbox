#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int f(int a){
    int s=0;
    while(a){
        s += (a%10)*(a%10);
        a /= 10;
    }
    return s;
}

void solve(){
    int a, n, i, j;
    cin >> a >> n;
    vector<int> v;
    v.push_back(a);
    for(i=1; i<=n; ++i){
        a = f(a);
        for(j=0; j<v.size(); ++j)
            if(v[j] == a){
                cout << v[j+(n-j)%(i-j)] << endl;
                return ;
            }
        v.push_back(a);
    }
    cout << v.back() << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--) solve();

    return 0;
}
