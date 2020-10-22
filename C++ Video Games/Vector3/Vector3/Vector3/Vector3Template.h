#pragma once

template <typename T>

class Vector3
{
public:
	Vector3() {
		x = y = z = 0;
	}

	Vector3(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3(const Vector3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	~Vector3() {

	}

	inline T getX() const {
		return x;
	}

	inline T getY() const {
		return y;
	}

	inline T getZ() const {
		return z;
	}

	inline T vectorMagnitude() const {
		return sqrt(x * x + y * y + z * z);
	}

	void normalize() {
		T magnitude = vectorMagnitude();

		if (magnitude != 0) {
			x = x / magnitude;
			y = y / magnitude;
			z = z / magnitude;
		}
	}

	T distanceTo(const Vector3& v) const {
		T dx = x - v.x;
		T dy = y - v.y;
		T dz = z - v.z;
		T distance = sqrt(dx * dx + dy * dy + dz * dz);

		return distance;
	}

	T angleBetween(const Vector3<T>& v) const {
		T vec1Magnitude = vectorMagnitude();
		T vec2Magnitude = v.vectorMagnitude();
		T product = dotProduct(v);
		T angle = T(acos(product / (vec1Magnitude * vec2Magnitude)));

		return angle;
	}

	T dotProduct(const Vector3& v) const {
		T prodX = x * v.x;
		T prodY = y * v.y;
		T prodZ = z * v.z;
		T productResult = prodX + prodY + prodZ;

		return productResult;
	}

	Vector3 crossProduct(const Vector3& v) const {
		T crossProdX = y * v.z - z * v.y;
		T crossProdY = z * v.x - x * v.z;
		T crossProdZ = x * v.y - y * v.x;

		return Vector3(crossProdX, crossProdY, crossProdZ);
	}

	Vector3 operator+(const Vector3& v) const {
		T x = this->x + v.x;
		T y = this->y + v.y;
		T z = this->z + v.z;

		return Vector3(x, y, z);
	}

	Vector3 operator-(const Vector3& v) const {
		T x = this->x - v.x;
		T y = this->y - v.y;
		T z = this->z - v.z;

		return Vector3(x, y, z);
	}

	Vector3 operator*(const Vector3& v) const {
		T x = this->x * v.x;
		T y = this->y * v.y;
		T z = this->z * v.z;

		return Vector3(x, y, z);
	}

private:
	T x;
	T y;
	T z;
};