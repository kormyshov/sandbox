#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
    	if(2*n%(n-2) == 0) cout << "YES\n";
    	else cout << "NO\n";
	}
	return 0;
}
