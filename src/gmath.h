#pragma once

#include <cmath>
#include <iostream>

/*
	Stupidly simple maths library.
*/

template<typename T>
struct vec2 {

	// Constructors

	vec2(T _x, T _y)
	{ 
		x = _x;
		y = _y;
	}

	// Scalar operation
	vec2(T a)
	{ 
		x = a;
		y = a;
	}

	// Methods

	T length()
	{
		return sqrt(x * x + y * y);
	}

	vec2<T> normalized()
	{
		vec2<T> vector(*this / length());
		return vector;
	}

	// Static methods

	static T dot(const vec2<T>& a, const vec2<T>& b)
	{
		return a.x * b.x + a.y * b.y;
	}

	// Operator overloads

	vec2<T>& operator+ (const vec2<T>& a)
	{
		vec2<T> vector(x + a.x, y + a.y);
		return vector;
	}

	// Scalar operation
	vec2<T>& operator+ (const T& a)
	{
		vec2<T> vector(x + a, y + a);
		return vector;
	}

	vec2<T>& operator- (const vec2<T>& a)
	{
		vec2<T> vector(x - a.x, y - a.y);
		return vector;
	}

	// Scalar operation
	vec2<T>& operator- (const T& a)
	{
		vec2<T> vector(x - a, y - a);
		return vector;
	}

	vec2<T>& operator/ (const vec2<T>& a)
	{
		vec2<T> vector(x / a.x, y / a.y);
		return vector;
	}

	// Scalar operation
	vec2<T>& operator/ (const T& a)
	{
		vec2<T> vector(x / a, y / a);
		return vector;
	}

	vec2<T>& operator* (const vec2<T>& a)
	{
		vec2<T> vector(x * a.x, y * a.y);
		return vector;
	}

	// Scalar operation
	vec2<T>& operator* (const T& a)
	{
		vec2<T> vector(x * a, y * a);
		return vector;
	}

	friend std::ostream& operator<< (std::ostream& stream, const vec2<T>& a)
	{
		return stream << "(" << a.x << ", " << a.y << ")";
	}

	T x; T y;
};

template<typename T>
struct vec3 {

	// Constructors 

	vec3(T _x, T _y, T _z)
	{ 
		x = _x;
		y = _y;
		z = _z;
	}

	// Scalar operation
	vec3(T a)
	{ 
		x = a;
		y = a;
		z = a;
	}

	// Methods

	T length()
	{
		return sqrt(x * x + y * y + z * z);
	}

	vec3<T> normalized()
	{
		vec3<T> vector(*this / length());
		return vector;
	}

	// Static methods

	static T dot(const vec3<T>& a, const vec3<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	// Operator overloads

	vec3<T>& operator+ (const vec3<T>& a)
	{
		vec3<T> vector(x + a.x, y + a.y, z + a.z);
		return vector;
	}

	// Scalar operation
	vec3<T>& operator+ (const T& a)
	{
		vec3<T> vector(x + a, y + a, z + a);
		return vector;
	}

	vec3<T>& operator- (const vec3<T>& a)
	{
		vec3<T> vector(x - a.x, y - a.y, z - a.z);
		return vector;
	}

	// Scalar operation
	vec3<T>& operator- (const T& a)
	{
		vec3<T> vector(x - a, y - a, z - a);
		return vector;
	}

	vec3<T>& operator/ (const vec3<T>& a)
	{
		vec3<T> vector(x / a.x, y / a.y, z / a.z);
		return vector;
	}

	// Scalar operation
	vec3<T>& operator/ (const T& a)
	{
		vec3<T> vector(x / a, y / a, z / a);
		return vector;
	}

	vec3<T>& operator* (const vec3<T>& a)
	{
		vec3<T> vector(x * a.x, y * a.y, z * a.z);
		return vector;
	}

	// Scalar operation
	vec3<T>& operator* (const T& a)
	{
		vec3<T> vector(x * a, y * a, z * a);
		return vector;
	}

	friend std::ostream& operator<< (std::ostream& stream, const vec3<T>& a)
	{
		return stream << "(" << a.x << ", " << a.y << ", " << a.z << ")";
	}

	T x; T y; T z;
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

typedef vec3<int> vec3i;
typedef vec3<float> vec3f;
typedef vec3<double> vec3d;