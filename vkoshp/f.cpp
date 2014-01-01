#include <iostream>
#include <cstdio>
#include <cmath>

#define eps (1e-9)

using namespace std;

double f(double x){
    return x*x-sqrt(x);
}

double bin_search(double l, double r, double c){
    double m;
    int t=0;
    while(fabs(l-r)>eps && t<200){
        ++t;
        m = (l+r)*.5;
        if(f(m)>c) l=m;
        else r=m;
    }
    return r;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int t;
	cin>>t;
	while(t--){
	    double c;
	    cin>>c;

	    double xm = 0.396850263;

	    if(c<eps && c>f(xm)+eps) printf("%.6lf ", bin_search(0., xm, c));
	    if(c>f(xm)-eps) printf("%.6lf", bin_search(1e6, xm, c));
	    if(c<f(xm)-eps) printf("No solution");
		printf("\n");
	}

    return 0;
}
