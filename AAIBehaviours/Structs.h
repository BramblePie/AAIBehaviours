#pragma once

template<class T>
struct Matrix
{
	T arr[9] = {};

	// Default constructor creates an indetity matrix
	Matrix()
	{
		(*this)(0, 0) = static_cast<T>(1);
		(*this)(1, 1) = static_cast<T>(1);
		(*this)(2, 2) = static_cast<T>(1);
	}

	inline const T& operator()(const size_t r, const size_t c) const { return arr[r * 3u + c]; }

	inline T& operator()(const size_t r, const size_t c) { return arr[r * 3 + c]; }
};

template<class T>
struct Vec
{
	T x = {};
	T y = {};
	T w = static_cast<T>(1);
};

template<class T>
Vec<T> operator*(const Matrix<T>& m, const Vec<T>& v)
{
	//return Vec<T>{
	//	m(0, 0)* v.x + m(1, 0) * v.y + m(2, 0) * v.w,
	//		m(0, 1)* v.x + m(1, 1) * v.y + m(2, 1) * v.w,
	//		m(0, 2)* v.x + m(1, 2) * v.y + m(2, 2) * v.w,
	//};
}
