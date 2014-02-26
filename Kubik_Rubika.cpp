#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

#define SIGN(a) ((a)<0?(-1):1)
#define ABS(a) ((a)<0?(-(a)):(a))

using namespace std;

char s[6][2][3];

stack<int> cur, res;
int R=12;

bool solved(){
	for(int i=0;i<6;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				if(s[i][j][k]!=s[i][0][0]) return false;
	return true;
}

void op1(){
	char c;
	c=s[0][0][0];
	s[0][0][0]=s[0][1][0];
	s[0][1][0]=s[0][1][1];
	s[0][1][1]=s[0][0][1];
	s[0][0][1]=c;
	c=s[1][0][1];
	s[1][0][1]=s[5][0][0];
	s[5][0][0]=s[3][1][0];
	s[3][1][0]=s[4][1][1];
	s[4][1][1]=c;
	c=s[1][1][1];
	s[1][1][1]=s[5][0][1];
	s[5][0][1]=s[3][0][0];
	s[3][0][0]=s[4][1][0];
	s[4][1][0]=c;
}

void op2(){
	char c;
	c=s[3][0][0];
	s[3][0][0]=s[3][1][0];
	s[3][1][0]=s[3][1][1];
	s[3][1][1]=s[3][0][1];
	s[3][0][1]=c;
	c=s[0][0][1];
	s[0][0][1]=s[5][0][1];
	s[5][0][1]=s[2][1][0];
	s[2][1][0]=s[4][0][1];
	s[4][0][1]=c;
	c=s[0][1][1];
	s[0][1][1]=s[5][1][1];
	s[5][1][1]=s[2][0][0];
	s[2][0][0]=s[4][1][1];
	s[4][1][1]=c;
}

void op3(){
	char c;
	c=s[4][0][0];
	s[4][0][0]=s[4][1][0];
	s[4][1][0]=s[4][1][1];
	s[4][1][1]=s[4][0][1];
	s[4][0][1]=c;
	c=s[0][0][0];
	s[0][0][0]=s[3][0][0];
	s[3][0][0]=s[2][0][0];
	s[2][0][0]=s[1][0][0];
	s[1][0][0]=c;
	c=s[0][0][1];
	s[0][0][1]=s[3][0][1];
	s[3][0][1]=s[2][0][1];
	s[2][0][1]=s[1][0][1];
	s[1][0][1]=c;
}

void op(int a){
	if(ABS(a)==1){
		if(a<0){
			op1();
			op1();
		}
		op1();
	}
	if(ABS(a)==2){
		if(a<0){
			op2();
			op2();
		}
		op2();
	}
	if(ABS(a)==3){
		if(a<0){
			op3();
			op3();
		}
		op3();
	}
}

void rec(){
	if(solved()){
		if((int)cur.size()<R){
			R = cur.size();
			res = cur;
		}
		return ;
	}
	if((int)cur.size()+1>=R) return ;
	for(int i=-3;i<4;++i){
		if(!i) continue ;
		if(cur.top()==-i) continue ;
		op(i);
		cur.push(i);
		rec();
		cur.pop();
		op(-i);
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i;
	for(i=0;i<6;++i) cin>>s[i][0];
	for(i=0;i<6;++i) cin>>s[i][1];

	char m[4]={' ','F','R','U'};

	cur.push(0);
	rec();
	if(R==1) cout<<"Solved";
	else {
		vector<int> v;
		while(!res.empty()){
			v.push_back(res.top());
			res.pop();
		}
		for(i=v.size()-2;i>=0;--i){
			cout<<m[ABS(v[i])];
			if(v[i]<0) cout<<"\'";
		}
	}
	return 0;
}
