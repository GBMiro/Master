#include "Vector3.h"
#include "Vector3.h"
#include <cmath>


template<typename T>
Vector3<T>::Vector3()
{
	x = y = z = 0;
}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z) {
	this->x = x;
	this->y = y;
	this->z = z;
}


template<typename T>
Vector3<T>::Vector3(const Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

template<typename T>
Vector3<T>::~Vector3() {

}

template<typename T>
inline T Vector3<T>::getX() const {
	return x;
}

template<typename T>
inline T Vector3<T>::getY() const {
	return y;
}

template<typename T>
inline T Vector3<T>::getZ() const {
	return z;
}

template<typename T>
T Vector3<T>::vectorMagnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

template<typename T>
void Vector3<T>::normalize() {
	T magnitude = vectorMagnitude();
	if (magnitude != 0) {
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;
	}
}

template<typename T>
T Vector3<T>::distanceTo(const Vector3& v) const {
	T dx = x - v.x;
	T dy = y - v.y;
	T dz = z - v.z;
	T distance = sqrt(dx * dx + dy * dy + dz * dz);
	return distance;
}

template<typename T>
T Vector3<T>::angleBetween(const Vector3& v) const {
	T vec1Magnitude = vectorMagnitude();
	T vec2Magnitude = v.vectorMagnitude();
	T product = dotProduct(v);
	T cosB = product / (vec1Magnitude * vec2Magnitude);
	return acos(cosB);
}

template<typename T>
T Vector3<T>::dotProduct(const Vector3& v) const {
	T prodX = x * v.x;
	T prodY = y * v.y;
	T prodZ = z * v.z;
	T productResult = prodX + prodY + prodZ;
	return productResult;
}

template<typename T>
Vector3<T> Vector3<T>::crossProduct(const Vector3& v) const {
	T crossProdX = y * v.z - z * v.y;
	T crossProdY = z * v.x - x * v.z;
	T crossProdZ = x * v.y - y * v.x;
	return Vector3(crossProdX, crossProdY, crossProdZ);
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3& v) const {
	T x = this->x + v.x;
	T y = this->y + v.y;
	T z = this->z + v.z;

	return Vector3(x, y, z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3& v) const {
	T x = this->x - v.x;
	T y = this->y - v.y;
	T z = this->z - v.z;

	return Vector3(x, y, z);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(const Vector3& v) const {
	T x = this->x * v.x;
	T y = this->y * v.y;
	T z = this->z * v.z;

	return Vector3(x, y, z);
}