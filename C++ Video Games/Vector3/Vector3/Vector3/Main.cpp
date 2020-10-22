#include <iostream>
#include "Vector3.cpp"
#include "Vector3.h"
using namespace std;


int main() {
	Vector3<float> a = Vector3<float>();
	Vector3<float> b = Vector3<float>(1, 0, 1);
	Vector3<float> c = Vector3<float>(b);
	Vector3<float> d = b + c;
	Vector3<float> f = Vector3<float>(-3.3f, 12.3f, 2.1);


	d.normalize();
	cout << "Vector D normalized: (" << d.getX() << "," << d.getY() << "," << d.getZ() << ")" << endl;

	cout << "Distance vector (d) to (b): " << d.distanceTo(b) << endl;

	cout << "Dot product (d,b): " << d.dotProduct(b) << endl;

	Vector3<float> e = d.crossProduct(b);
	cout << "Cross product (d,b): (" << e.getX() << "," << e.getY() << "," << e.getZ() << ")" << endl;

	cout << "Angle (d,b): " << f.angleBetween(b) << endl;
}