#include <iostream>
#include <cmath>

using namespace std;

class Point{
	double x, y;
public:
	inline Point():
		x(.0), y(.0) {};
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
};

class Point3D{
	double x, y, z;
public:
	inline Point3D():
		x(.0), y(.0), z(.0) {};
	inline Point3D(double _x, double _y, double _z):
		x(_x), y(_y), z(_z) {};
	inline Point3D(const Point3D &a):
		x(a.get_x()), y(a.get_y()), z(a.get_z()) {};

	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline double get_z() const {return z;}

	inline void set(double _x, double _y, double _z){
		x = _x; y = _y; z = _z;
	}
	inline void set(const Point3D &a){
		x = a.get_x(); y = a.get_y(); z = a.get_z();
	}

	inline double length() const {
		return sqrt(x*x+y*y+z*z);
	}

	inline Point3D operator-=(const Point3D &a){
		x -= a.get_x(); y -= a.get_y(); z -= a.get_z();
		return *this;
	}
	inline Point3D operator-(const Point3D &a) const {
		Point3D res(*this);
		res -= a;
		return res;
	}

	inline Point3D operator-() const {
		return Point3D(-x, -y, -z);
	}

	inline Point3D operator+=(const Point3D &a){
		x += a.get_x(); y += a.get_y(); z += a.get_z();
		return *this;
	}
	inline Point3D operator+(const Point3D &a) const {
		Point3D res(*this);
		res += a;
		return res;
	}

	inline double scalar(const Point3D &a) const {
		return x*a.get_x() + y*a.get_y() + z*a.get_z();
	}
	inline double operator%(const Point3D &a) const {
		return scalar(a);
	}

	inline Point3D operator*(const Point3D &a) const {
		return Point3D(
				y*a.get_z() - z*a.get_y(),
				z*a.get_x() - x*a.get_z(),
				x*a.get_y() - y*a.get_x()
			);
	}
	inline Point3D operator*=(const Point3D &a){
		set(*this * a);
		return *this;
	}

	inline Point3D operator*(double k) const {
		return Point3D(x*k, y*k, z*k);
	}
	inline friend Point3D operator*(const double k, const Point3D &a){
		return a*k;
	}
	inline Point3D operator*=(double k){
		x *= k; y*=k; z*=k;
		return *this;
	}
};

class Quaternion{
	double x, y, z, w;
public:
	inline Quaternion():
		x(.0), y(.0), z(.0), w(1.) {};
	inline Quaternion(double _x, double _y, double _z, double _w):
		x(_x), y(_y), z(_z), w(_w) {};
	inline Quaternion(const Quaternion &a):
		x(a.get_x()), y(a.get_y()), z(a.get_z()), w(a.get_w()) {};
	inline Quaternion(const Point3D &a, double _w):
		x(a.get_x()), y(a.get_y()), z(a.get_z()), w(_w) {};

	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline double get_z() const {return z;}
	inline double get_w() const {return w;}

	inline double get_rotation() const {
		if(w < 0) return 2*atan2(-sqrt(x*x+y*y+z*z), -w);
		else return 2*atan2(sqrt(x*x+y*y+z*z), w);
	}
	inline Point3D get_vector() const {
		return Point3D(x, y, z);
	}

	inline void set(double _x, double _y, double _z, double _w){
		x = _x; y = _y; z = _z; w = _w;
	}
	inline void set(const Quaternion &a){
		x = a.get_x(); y = a.get_y(); z = a.get_z(); w = a.get_w();
	}

	inline void ident(){
		x = y = z = .0; w = 1.;
	}
	inline void conjugate(){
		x = -x; y = -y; z = -z;
	}
	inline Quaternion conjugated() const {
		return Quaternion(-x, -y, -z, w);
	}

	inline double norm() const {
		return x*x + y*y + z*z + w*w;
	}
	inline double magnitude() const {
		return sqrt(norm());
	}

	inline void invert(){
		double in = 1./norm();
		set(-x*in, -y*in, -z*in, w*in);
	}
	inline Quaternion inverted() const {
		double in = 1./norm();
		return Quaternion(-x*in, -y*in, -z*in, w*in);
	}

	inline Quaternion operator-() const {
		return Quaternion(-x, -y, -z, -w);
	}
	inline Quaternion operator+(const Quaternion &a) const {
		return Quaternion(x+a.get_x(), y+a.get_y(), z+a.get_z(), w+a.get_w());
	}
	inline Quaternion operator+=(const Quaternion &a){
		x += a.get_x(); y += a.get_y(); z += a.get_z(); w += a.get_w();
		return *this;
	}
	inline Quaternion operator-(const Quaternion &a) const {
		return Quaternion(x-a.get_x(), y-a.get_y(), z-a.get_z(), w-a.get_w());
	}
	inline Quaternion operator-=(const Quaternion &a){
		x -= a.get_x(); y -= a.get_y(); z -= a.get_z(); w -= a.get_w();
		return *this;
	}

	inline Quaternion operator*(const double &s) const {
		return Quaternion(x*s, y*s, z*s, w*s);
	}
	inline friend Quaternion operator*(const double &s, const Quaternion &a) {
		return a*s;
	}
	inline Quaternion operator*=(const double &s){
		x *= s; y *= s; z *= s; w *= s;
		return *this;
	}

	inline Quaternion operator*(const Quaternion &a) const {
		Quaternion res(*this);
		res *= a;
		return res;
	}
	inline Quaternion operator*=(const Quaternion &a){
		double r = w, i = x, j = y, k = z;
		double br = a.get_w(), bi = a.get_x(), bj = a.get_y(), bk = a.get_z();
		double t0 = (i-j)*(bj-bi);
		double t1 = (r+k)*(br+bk);
		double t2 = (r-k)*(bj+bi);
		double t3 = (i+j)*(br-bk);
		double t9 = (i-k)*(bk-bj), t;
		t = (i+k)*(bk+bj); t0 -= t; t1 -= t; t9 += t;
		t = (r+j)*(br-bi); t3 -= t; t1 -= t; t9 += t;
		t = (r-j)*(br+bi); t2 -= t; t1 -= t; t9 += t;
		t9 *= 0.5;
		set(t3+t9, t2+t9, t1+t9, t0+t9);
		return *this;
	}

};

int main(){

	Quaternion q;
	double s=2.0;
	Quaternion p = s*q;
	return 0;
}
