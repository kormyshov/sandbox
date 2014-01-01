#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

void solve(){
    int n, m, y, x;
    cin >> n >> m >> y >> x;
    int mm[1009][1009];
    char s[1009];
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<m;++j)
            mm[i][j] = s[j]-'0'-1;
    }
    queue<pair<int,int> > q;
    q.push(make_pair(y-1, x-1));

    int dx[2][6] = {{-1, 0, -1, 1, -1, 0},{ 0, 1, -1, 1, 0, 1}};
    int dy[2][6] = {{-1, -1, 0, 0,  1, 1},{-1, -1, 0, 0, 1, 1}};

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        if(!x || !y || x==m-1 || y==n-1){
            cout << mm[y][x]+1;
            return ;
        }
        q.pop();
        for(int i=0;i<6;++i)
            if(!mm[y+dy[y&1][i]][x+dx[y&1][i]]){
                mm[y+dy[y&1][i]][x+dx[y&1][i]] = mm[y][x]+1;
                q.push(make_pair(y+dy[y&1][i], x+dx[y&1][i]));
            }
    }
    cout << "No solution";
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}

    return 0;
}
