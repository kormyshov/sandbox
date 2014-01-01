#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int p, n, k;
	scanf("%d%d%d", &p, &n, &k);
    char str[39];
    cin.getline(str, 35);
    vector<string> vs;
    for(int i=0;i<p;++i){
        cin.getline(str, 35);
        string s(str);
        vs.push_back(s);
    }
    map<string, int> m;
    for(int i=0, j=0; i<p && j<n; ++i){
        int c = m[vs[i]];
        int a;
		scanf("%d", &a);
        if(c<k){
            m[vs[i]]++;
            cout<<vs[i]<<" #"<<a<<endl;
            ++j;
        }
    }
    return 0;
}
