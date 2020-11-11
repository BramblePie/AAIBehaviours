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

	Vec() = default;
	Vec(T x, T y) : x(x), y(y) {}
};

namespace transform
{
	// Gets a translation matrix with a translation of the given vector
	template<class T>
	Matrix<T> translate(const Vec<T>& vertices)
	{
		return translate(Matrix<T>(), vertices);
	}

	// Gets the translation of the given matrix by given vector
	template<class T>
	Matrix<T> translate(const Matrix<T>& m, const Vec<T>& vertices)
	{
		Matrix<T> r = m;
		r(0, 2) += r(0, 0) * vertices.x + r(0, 1) * vertices.y;
		r(1, 2) += r(1, 0) * vertices.x + r(1, 1) * vertices.y;
		r(2, 2) += r(2, 0) * vertices.x + r(2, 1) * vertices.y;
		return r;
	}

	template<class T>
	Matrix<T> scale(const Matrix<T>& m, const Vec<T>& s)
	{
		Matrix<T> r = m;
		r(0, 0) *= s.x;
		r(1, 0) *= s.x;
		r(2, 0) *= s.x;
		r(0, 1) *= s.y;
		r(1, 1) *= s.y;
		r(2, 1) *= s.y;
		return r;
	}
}
