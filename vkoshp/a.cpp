#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, t;
	cin >> t;
	while(t--){
	    cin >> n >> m;
    	cout << m*n/(m-1) << " " << n/(m-1) << endl;
	}
	return 0;
}
