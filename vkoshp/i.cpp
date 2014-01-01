#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	while(t--){
	    long long n, mn=(1LL<<62), mx=0;
	    cin >> n;
	    for(int i=0; i<63; ++i)
	        if(n&(1LL<<i)){
	            mn = min(mn, 1LL<<i);
	            mx = max(mx, 1LL<<i);
	        }
	    cout << mn << " " << mx << endl;
	}
    return 0;
}
