#include <iostream>
#include <cstdio>

#define eps (1e-9)

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, f, m, a, t;
	cin>>t;
	while(t--){
		cin>>n>>f>>m;
    	double x = (100-f)/100.*n;

    	for(int i=0;i<m;++i){
        	cin>>a;
        	n += a;
    	}

    	cout<<n<<" "<<int((n-x)/n*100+0.5+eps)<<endl;
	}

    return 0;
}
