#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <iomanip>
#include <pthread.h>
#include <semaphore.h>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <algorithm>

#define ABS(a) ((a)<0?(-(a)):(a))
#define SIGN(a) (((a)>0)-((a)<0))
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define PI (3.1415926)
#define INF (2147483647)
#define LLINF (9223372036854775807LL)
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> &t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> &t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }

class Point{
	double x, y;
public:
	inline Point():
		x((double)0), y((double)0) {};
	inline Point(double _x, double _y):
		x(_x), y(_y) {};
	inline Point(const Point &a):
		x(a.get_x()), y(a.get_y()) {};

	inline double get_x() const {return x;}
	inline double get_y() const {return y;}

	inline void set(double _x, double _y){
		x = _x; y = _y;
	}
	inline void set(const Point &a){
		x = a.get_x(); y = a.get_y();
	}

	inline double length() const {
		return sqrt(x*x+y*y+.0);
	}

	inline double length2() const {
		return x*x+y*y;
	}

	inline Point rotate(double angle) const {
		double s = sin(angle), c = cos(angle);
		Point res(x*c-y*s, x*s+y*c);
		return res;
	}

	inline Point operator-=(const Point &a){
		x -= a.get_x(); y -= a.get_y();
		return *this;
	}
	inline Point operator-(const Point &a) const {
		Point res(*this);
		res -= a;
		return res;
	}

	inline Point operator-() const {
		return Point(-x, -y);
	}

	inline Point operator+=(const Point &a){
		x += a.get_x(); y += a.get_y();
		return *this;
	}
	inline Point operator+(const Point &a) const {
		Point res(*this);
		res += a;
		return res;
	}

	inline double scalar(const Point &a) const {
		return x*a.get_x() + y*a.get_y();
	}
	inline double operator%(const Point &a) const {
		return scalar(a);
	}

	inline double operator*(const Point &a) const {
		return x*a.get_y() - y*a.get_x();
	}

	inline Point operator*(double k) const {
		return Point(x*k, y*k);
	}
	inline friend Point operator*(const double k, const Point &a){
		return a*k;
	}
	inline Point operator*=(double k){
		x *= k; y *= k;
		return *this;
	}

	inline Point operator/(double k) const {
		return Point(x/k, y/k);
	}
	inline Point operator/=(double k){
		x /= k; y /= k;
		return *this;
	}

	inline Point& operator=(const Point &a){
		set(a);
		return *this;
	}

	friend istream& operator>>(istream& in, Point &a){
		double x, y;
		in>>x>>y;
		a.set(x, y);
		return in;
	}
	friend ostream& operator<<(ostream& out, const Point &a){
		return out<<a.get_x()<<" "<<a.get_y();
	}
};
class Line{
protected:
	Point A, a;
public:
	inline Line():
		A(), a() {};
	inline Line(const Point &_A, const Point &_a):
		A(_A), a(_a) {};
	inline Line(double x1, double y1, double dx, double dy):
		A(x1, y1), a(dx, dy) {};
	inline Line(const Line &l):
		A(l.get_A()), a(l.get_a()) {};

	inline Point get_A() const {return A;}
	inline Point get_a() const {return a;}

	inline void set_A(double x, double y){
		A.set(x, y);
	}
	inline void set_A(const Point &p){
		A.set(p);
	}
	inline void set_a(double x, double y){
		a.set(x, y);
	}
	inline void set_a(const Point &p){
		a.set(p);
	}
	inline void set(double x1, double y1, double dx, double dy){
		A.set(x1, y1);
		a.set(dx, dy);
	}
	inline void set(const Point &_A, const Point &_a){
		A.set(_A);
		a.set(_a);
	}
	inline void set(const Line &l){
		A = l.get_A();
		a = l.get_a();
	}

	inline Line rotate(double angle) const {
		Line res(A, a.rotate(angle));
		return res;
	}

	inline double onLine(const Point &p) const {
		return a*(p-A);
	}

	inline double distance(const Point &p) const {
		double l = a.length2();
		if(l < EPS) return (p-A).length();
		return fabs(onLine(p)/sqrt(l+.0));
	}

	inline bool intersect(const Line &l, Point &p) const {
		double t = a*l.get_a();
		if(fabs(t) < EPS) return false;
		t = (l.get_A()-A)*l.get_a() / t;
		p = A + a * t;
		return true;
	}
	inline pair<bool,Point> intersect(const Line &l) const {
		pair<bool,Point> p;
		p.first = intersect(l, p.second);
		return p;
	}

	inline Line& operator=(const Line &l){
		set(l);
		return *this;
	}

	friend istream& operator>>(istream& in, Line &l){
		Point a, b;
		in>>a>>b;
		l.set(a, b-a);
		return in;
	}
	friend ostream& operator<<(ostream& out, const Line &l){
		return out<<"A : "<<l.get_A()<<"; a : "<<l.get_a();
	}
};
class Segment : public Line {
public:
	inline bool onSeg(const Point &p){
		double t = onLine(p);
		if(ABS(t) > EPS) return false;
		return (p.get_x()-A.get_x())*(A.get_x()+a.get_x()-p.get_x())>=0 && (p.get_y()-A.get_y())*(A.get_y()+a.get_y()-p.get_y())>=0;
	}
	inline double distance(const Point &p) const {
		double la = a.length2();
		double lb = (A-p).length2();
		double lc = (A+a-p).length2();
		if(la < EPS) return sqrt(lb+.0);
		if(lb >= la+lc) return sqrt(lc+.0);
		else
		if(lc >= la+lb) return sqrt(lb+.0);
		return fabs(onLine(p)/sqrt(la+.0));
	}
};

int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	Line a;
	Segment b;
	cin>>a>>b;
	Point c, d, e;
	cin>>c>>d>>e;
	cout<<a.distance(c)<<" "<<a.distance(d)<<" "<<a.distance(e)<<endl;
	cout<<b.distance(c)<<" "<<b.distance(d)<<" "<<b.distance(e)<<endl;

	return 0;
}
