#pragma once
#include "vector.h"
#include "matrix.h"

namespace modmath
{
	/// <summary>
	/// Pre-defined vectors with class and dimension
	/// </summary>
	typedef Vector<float, 2> Vec2;
	typedef Vector<float, 3> Vec3;
	typedef Vector<float, 4> Vec4;
	typedef Vector<int, 2> Vec2i;
	typedef Vector<int, 3> Vec3i;
	typedef Vector<int, 4> Vec4i;
	/// <summary>
	/// Pre-defined matrices with class and dimensions
	/// </summary>
	typedef Matrix<float, 2, 2> Mat2;
	typedef Matrix<float, 3, 3> Mat3;
	typedef Matrix<float, 4, 4> Mat4;
	typedef Matrix<int, 2, 2> Mat2i;
	typedef Matrix<int, 3, 3> Mat3i;
	typedef Matrix<int, 4, 4> Mat4i;



}