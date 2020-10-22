#pragma once
template <typename T>

class Vector3
{
public:
	Vector3();

	Vector3(T x, T y, T z);

	Vector3(const Vector3& v);

	~Vector3();

	inline T getX() const;

	inline T getY() const;

	inline T getZ() const;

	inline T vectorMagnitude() const;

	void normalize();

	T distanceTo(const Vector3& v) const;

	T angleBetween(const Vector3<T>& v) const;

	T dotProduct(const Vector3& v) const;

	Vector3 crossProduct(const Vector3& v) const;

	Vector3 operator+(const Vector3& v) const;

	Vector3 operator-(const Vector3& v) const;

	Vector3 operator*(const Vector3& v) const;

private:
	T x;
	T y;
	T z;
};
