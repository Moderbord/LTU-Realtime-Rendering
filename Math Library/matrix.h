#pragma once
#include "vector.h"
/// <summary>
/// Performs a given operation along with a modifier value.
/// </summary>
#define MODMATH_MATRIX_OPERATOR(OP, Mod)					\
	{														\
		Matrix<T, Rows, Cols> result;						\
		for (int i = 0; i < Rows; i++)						\
		{													\
			result.data_[i] = this->data_[i] OP Mod;		\
		}													\
		return result;										\
	}

namespace modmath
{
	/// <summary>
	/// Template Matrix class with definable rows and columns.
	/// </summary>
	template<class T, int Rows, int Cols>
	class Matrix
	{
	public:
		/// <summary>
		/// Each row contains a Vector wich data.
		/// </summary>
		Vector<T, Rows> data_[Cols];

		/// <summary>
		/// Constructor
		/// </summary>
		inline Matrix() {};

		/// <summary>
		/// Constructs a Matrix from four values.
		/// </summary>
		/// <param name="v00">Value of firs row and first column.</param>
		/// <param name="v01">Value of second row and first column.</param>
		/// <param name="v10">Value of first row and second column.</param>
		/// <param name="v11">Value of second row and second column.</param>
		inline Matrix(T v00, T v01, T v10, T v11)
		{
			_STL_VERIFY(Rows == 2 && Cols == 2, "Size of matrix does not match");
			this->data_[0][0] = v00;
			this->data_[0][1] = v01;
			this->data_[1][0] = v10;
			this->data_[1][1] = v11;
		}

		/// <summary>
		/// Constructs a Matrix from 9 values.
		/// </summary>
		/// <param name="v00">Value of first row and first column.</param>
		/// <param name="v01">Value of second row and first column.</param>
		/// <param name="v02">Value of third row and first column.</param>
		/// <param name="v10">Value of first row and second column.</param>
		/// <param name="v11">Value of second row and second column.</param>
		/// <param name="v12">Value of third row and second column.</param>
		/// <param name="v20">Value of first row and third column.</param>
		/// <param name="v21">Value of second row and third column.</param>
		/// <param name="v22">Value of third row and third column.</param>
		inline Matrix(T v00, T v01, T v02, T v10, T v11, T v12, T v20, T v21, T v22)
		{
			_STL_VERIFY(Rows == 3 && Cols == 3, "Size of matrix does not match");
			this->data_[0][0] = v00;
			this->data_[0][1] = v01;
			this->data_[0][2] = v02;
			this->data_[1][0] = v10;
			this->data_[1][1] = v11;
			this->data_[1][2] = v12;
			this->data_[2][0] = v20;
			this->data_[2][1] = v21;
			this->data_[2][2] = v22;
		}
		
		/// <summary>
		/// Constructs a Matrix from 16 values;
		/// </summary>
		/// <param name="v00">Value of first row and first column.</param>
		/// <param name="v01">Value of second row and first column.</param>
		/// <param name="v02">Value of third row and first column.</param>
		/// <param name="v03">Value of fourth row and first column.</param>
		/// <param name="v10">Value of first row and second column.</param>
		/// <param name="v11">Value of second row and second column.</param>
		/// <param name="v12">Value of third row and second column.</param>
		/// <param name="v13">Value of fourth row and second column.</param>
		/// <param name="v20">Value of first row and third column.</param>
		/// <param name="v21">Value of second row and third column.</param>
		/// <param name="v22">Value of third row and third column.</param>
		/// <param name="v23">Value of fourth row and third column.</param>
		/// <param name="v30">Value of first row and fourth column.</param>
		/// <param name="v31">Value of second row and fourth column.</param>
		/// <param name="v32">Value of third row and fourth column.</param>
		/// <param name="v33">Value of fourth row and fourth column.</param>
		inline Matrix(T v00, T v01, T v02, T v03, T v10, T v11, T v12, T v13, T v20, T v21, T v22, T v23, T v30, T v31, T v32, T v33)
		{
			_STL_VERIFY(Rows == 4 && Cols == 4, "Size of matrix does not match");
			this->data_[0][0] = v00;
			this->data_[0][1] = v01;
			this->data_[0][2] = v02;
			this->data_[0][3] = v03;
			this->data_[1][0] = v10;
			this->data_[1][1] = v11;
			this->data_[1][2] = v12;
			this->data_[1][3] = v13;
			this->data_[2][0] = v20;
			this->data_[2][1] = v21;
			this->data_[2][2] = v22;
			this->data_[2][3] = v23;
			this->data_[3][0] = v30;
			this->data_[3][1] = v31;
			this->data_[3][2] = v32;
			this->data_[3][3] = v33;
		}

		/// <summary>
		/// Access a Vector element from the Matrix.
		/// </summary>
		/// <param name="i">Index if the Vector to access.</param>
		/// <returns>Reference to the Vector.</returns>
		inline Vector<T, Rows>& operator[](const int i)
		{
			return data_[i];
		}

		/// <summary>
		/// Access a Vector element from the Matrix.
		/// </summary>
		/// <param name="i">Index if the Vector to access.</param>
		/// <returns>A const reference to the Vector.</returns>
		inline const Vector<T, Rows>& operator[](const int i) const
		{
			return data_[i];
		}

		/// <summary>
		/// Copies a Matrix from another Matrix of the same size.
		/// </summary>
		/// <param name="m">Matrix to copy from.</param>
		inline Matrix(const Matrix<T, Rows, Cols>& m)
		{
			for (int i = 0; i < Rows; i++)
			{
				for (int j = 0; j < Cols; j++)
				{
					this->data_[i][j] = m[i][j];
				}
			}
		}

		/// <summary>
		/// Creates a Vector from a column in a Matrix.
		/// </summary>
		/// <param name="c">Index of the column to create a Vector from.</param>
		/// <returns>Vector with size of the row length.</returns>
		inline Vector<T, Rows> ColToVector(const int c) const
		{
			_STL_VERIFY(c < Rows, "Column vector out of bounds");
			Vector<T, Rows> colVec;
			for (int j = 0; j < Rows; j++)
			{
				colVec[j] = this->data_[j][c];
			}
			return colVec;
		}

		template<class T, int Rows, int Cols>
		/// <summary>
		/// Performs addition between two Matrices.
		/// </summary>
		/// <param name="m">Matrix to add.</param>
		/// <returns>Matrix containing the sum of two matrices.</returns>
		inline Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& m)
		{
			MODMATH_MATRIX_OPERATOR(+, m.data_[i]);
		}

		template<class T, int Rows, int Cols>
		/// <summary>
		/// Performs subtraction between two matrices.
		/// </summary>
		/// <param name="m">Matrix to subtract from.</param>
		/// <returns>Matrix containing the difference of two matrices.</returns>
		inline Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& m)
		{
			MODMATH_MATRIX_OPERATOR(-, m.data_[i]);
		}

		template<class T, int Rows, int Cols>
		/// <summary>
		/// Performs Matrix multiplikation between two matrices.
		/// </summary>
		/// <param name="m">Matrix to be multiplied by.</param>
		/// <returns>Matrix containing the product of two matrices.</returns>
		inline Matrix<T, Rows, Cols> operator*(const Matrix<T, Rows, Cols>& m)
		{
			Matrix<T, Rows, Cols> result;
			for (int i = 0; i < Cols; i++)
			{
				// Creates a column Vector
				Vector<T, Rows> colVec = m.ColToVector(i);
				for (int  j = 0; j < Rows; j++)
				{
					// Performs Dot Product operation between row and column Vector
					result.data_[j][i] = modmath::Vector<T, Rows>().DotProduct(this->data_[j], colVec);
				}
			}
			return result;
		}

		/// <summary>
		/// Addition between a Matrix and a scalar.
		/// </summary>
		/// <param name="s">Scalar to add.</param>
		/// <returns>Matrix with added scalar.</returns>
		Matrix<T, Rows, Cols> operator +(const T s)
		{
			MODMATH_MATRIX_OPERATOR(+, s);
		}

		/// <summary>
		/// Subtraction between a Matrix and a scalar.
		/// </summary>
		/// <param name="s">Scalar to subtract.</param>
		/// <returns>Matrix with subtracted scalar.</returns>
		Matrix<T, Rows, Cols> operator -(const T s)
		{
			MODMATH_MATRIX_OPERATOR(-, s);
		}

		/// <summary>
		/// Multiplicaiton between a Matrix and a scalar.
		/// </summary>
		/// <param name="s">Scalar to multiply by.</param>
		/// <returns>Matrix with multiplied scalar.</returns>
		Matrix<T, Rows, Cols> operator *(const T s)
		{
			MODMATH_MATRIX_OPERATOR(*, s);
		}

		/// <summary>
		/// Division between a Matrix and a scalar.
		/// </summary>
		/// <param name="s">Scalar to divide by.</param>
		/// <returns>Matrix with divided scalar.</returns>
		Matrix<T, Rows, Cols> operator /(const T s)
		{
			MODMATH_MATRIX_OPERATOR(/, s);
		}

		/// <summary>
		/// Multiplication between a 4x4 Matrix and a 3-element Vector.
		/// </summary>
		/// <param name="v">Vector to multiply by.</param>
		/// <returns>A 3-element Vector.</returns>
		inline Vector<T, 3> operator* (const Vector<T, 3>& v)
		{
			Vector<T, 4> increasedV(v[0], v[1], v[2], 1);
			Vector<T, 3> result;
			for (int i = 0; i < 3; i++)
			{
				result[i] = modmath::Vector<T, 4>().DotProduct(this->data_[i], increasedV);
			}
			return result;
		}

		/// <summary>
		/// Multiplication between a 4x4 Matrix and a 4-element Vector.
		/// </summary>
		/// <param name="v">Vector to multiply by.</param>
		/// <returns>A 4-element Vector.</returns>
		inline Vector<T, 4> operator* (const Vector<T, 4>& v)
		{
			Vector<T, 4> result;
			for (int i = 0; i < 4; i++)
			{
				result[i] = modmath::Vector<T, 4>().DotProduct(this->data_[i], v);
			}
			return result;
		}

		/// <summary>
		/// Rotation around X-axis with a normalized directional Vector.
		/// </summary>
		/// <param name="v">Normalized directional Vector.</param>
		/// <returns>Matrix containing rotation.</returns>
		static inline Matrix<T, 4, 4> RotationX(const Vector<T, 2> & v)
		{
			return Matrix<T, 4, 4> (1,     0,     0,     0,
									0,   v[0],  v[1],    0,
									0,  -v[1],  v[0],    0,
									0,     0,     0,     1);
		}

		/// <summary>
		/// Rotation around Y-axis with a normalized directional Vector
		/// </summary>
		/// <param name="v">Normalized directional Vector.</param>
		/// <returns>Matrix containing rotation.</returns>
		static inline Matrix<T, 4, 4> RotationY(const Vector<T, 2> & v)
		{
			return Matrix<T, 4, 4>(v[0],    0,   -v[1],    0,
								     0,     1,      0,     0,
								   v[1],    0,    v[0],    0,
								     0,     0,      0,     1);
		}

		/// <summary>
		/// Rotation around Z-axis with a normalized directional Vector
		/// </summary>
		/// <param name="v">Normalized directional Vector.</param>
		/// <returns>Matrix containing rotation.</returns>
		static inline Matrix<T, 4, 4> RotationZ(const Vector<T, 2> & v)
		{
			return Matrix<T, 4, 4>(v[0],   v[1],    0,     0,
								  -v[1],   v[0],    0,     0,
								     0,      0,     1,     0,
								     0,      0,     0,     1);
		}

		/// <summary>
		/// Rotation around X-axis with an angle.
		/// </summary>
		/// <param name="angle">Angle in radians.</param>
		/// <returns>Matrix containing rotation.</returns>
		static inline Matrix<T, 4, 4> RotationX(T angle)
		{
			return RotationX(Vector<T, 2>(cosf(angle), sinf(angle)));
		}

		/// <summary>
		/// Rotation around Y-axis with an angle.
		/// </summary>
		/// <param name="angle">Angle in radians.</param>
		/// <returns>Matrix containing rotation.</returns>
		static inline Matrix<T, 4, 4> RotationY(T angle)
		{
			return RotationY(Vector<T, 2>(cosf(angle), sinf(angle)));
		}

		/// <summary>
		/// Rotation around Z-axis with an angle.
		/// </summary>
		/// <param name="angle">Angle in radians.</param>
		/// <returns>Matrix containing rotation.</returns>
		static inline Matrix<T, 4, 4> RotationZ(T angle)
		{
			return RotationZ(Vector<T, 2>(cosf(angle), sinf(angle)));
		}

		/// <summary>
		/// Rotation using Rodrigues rotation formula.
		/// </summary>
		/// <param name="angle"></param>
		/// <param name="v"></param>
		/// <returns></returns>
		static inline Matrix<T, 4, 4> RotationMatrixXYZ(T angle, Vector<T, 3> & v)
		{
			const Vector<T, 3> u(v.Normalized());
			T x = u[0];
			T y = u[1];
			T z = u[2];
			float cos = cosf(angle);
			float cosm = 1.0f - cos;
			float sin = sinf(angle);

			return Matrix<T, 4, 4>(cos+POW2(x)*cosm,   x*y*cosm-z*sin,	     x*z*cosm+y*sin,	  0,							
								   y*x*cosm+z*sin,	   cos+POW2(y)*cosm,	 y*z*cosm-x*sin,	  0,						
								   z*x*cosm-y*sin,	   z*y*cosm+x*sin,		 cos+POW2(z)*cosm,    0,							
								   0,				   0,				     0,				      1);							
		}


		inline Matrix<T, Rows, Cols> Transponate()
		{
			Matrix<T, Rows, Cols> tMat;
			for (int i = 0; i < Rows; i++)
			{
				tMat[i] = this->ColToVector(i);
			}
			return tMat;
		}

		inline T Determinant()
		{
			return DeterminantCalc(*this);
		}

		template<class T>
		inline T DeterminantCalc(const Matrix<T, 3, 3> &m)
		{
			return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1]
				- m[2][0] * m[1][1] * m[0][2] - m[2][1] * m[1][2] * m[0][0] - m[2][2] * m[1][0] * m[0][1];
		}

		template<class T>
		inline T DeterminantCalc(const Matrix<T, 4, 4> & m)
		{
			Matrix<T, 3, 3> subMat1(m[1][1], m[1][2], m[1][3],
									m[2][1], m[2][2], m[2][3],
									m[3][1], m[3][2], m[3][3]);

			Matrix<T, 3, 3> subMat2(m[0][1], m[0][2], m[0][3],
									m[2][1], m[2][2], m[2][3],
									m[3][1], m[3][2], m[3][3]);

			Matrix<T, 3, 3> subMat3(m[0][1], m[0][2], m[0][3],
									m[1][1], m[1][2], m[1][3],
									m[3][1], m[3][2], m[3][3]);

			Matrix<T, 3, 3> subMat4(m[0][1], m[0][2], m[0][3],
									m[1][1], m[1][2], m[1][3],
									m[2][1], m[2][2], m[2][3]);


			return m[0][0] * subMat1.Determinant() - m[1][0] * subMat2.Determinant() + m[2][0] * subMat3.Determinant() - m[3][0] * subMat4.Determinant();
		}


		inline Matrix<T, Rows, Cols> Inverse()
		{
			return InverseCalc(*this);
		}

		template<class T>
		inline Matrix<T, 4, 4> InverseCalc(Matrix<T, 4, 4> & m)
		{
			T det = m.Determinant();

			if (det == 0)
			{
				return m * 0;
			}

			return m.Adjugat() * (1 / det) ;
		}


		inline Matrix<T, Rows, Cols> Adjugat()
		{
			return AdjugatCalc(*this);
		}

		template<class T>
		inline Matrix<T, 4, 4> AdjugatCalc(Matrix<T, 4, 4> &m)
		{
			Vector<T, 4> v0 = m[0];
			Vector<T, 4> v1 = m[1];
			Vector<T, 4> v2 = m[2];
			Vector<T, 4> v3 = m[3];

			Matrix<T, 3, 3> subMat00(v1[1], v1[2], v1[3],
									 v2[1], v2[2], v2[3],
									 v3[1], v3[2], v3[3]);

			Matrix<T, 3, 3> subMat01(v1[0], v1[2], v1[3],
									 v2[0], v2[2], v2[3],
									 v3[0], v3[2], v3[3]);

			Matrix<T, 3, 3> subMat02(v1[0], v1[1], v1[3],
									 v2[0], v2[1], v2[3],
									 v3[0], v3[1], v3[3]);

			Matrix<T, 3, 3> subMat03(v1[0], v1[1], v1[2],
									 v2[0], v2[1], v2[2],
									 v3[0], v3[1], v3[2]);


			Matrix<T, 3, 3> subMat10(v0[1], v0[2], v0[3],
									 v2[1], v2[2], v2[3],
									 v3[1], v3[2], v3[3]);

			Matrix<T, 3, 3> subMat11(v0[0], v0[2], v0[3],
									 v2[0], v2[2], v2[3],
									 v3[0], v3[2], v3[3]);

			Matrix<T, 3, 3> subMat12(v0[0], v0[1], v0[3],
									 v2[0], v2[1], v2[3],
									 v3[0], v3[1], v3[3]);

			Matrix<T, 3, 3> subMat13(v0[0], v0[1], v0[2],
									 v2[0], v2[1], v2[2],
									 v3[0], v3[1], v3[2]);


			Matrix<T, 3, 3> subMat20(v0[1], v0[2], v0[3],
									 v1[1], v1[2], v1[3],
									 v3[1], v3[2], v3[3]);

			Matrix<T, 3, 3> subMat21(v0[0], v0[2], v0[3],
									 v1[0], v1[2], v1[3],
									 v3[0], v3[2], v3[3]);

			Matrix<T, 3, 3> subMat22(v0[0], v0[1], v0[3],
									 v1[0], v1[1], v1[3],
									 v3[0], v3[1], v3[3]);

			Matrix<T, 3, 3> subMat23(v0[0], v0[1], v0[2],
									 v1[0], v1[1], v1[2],
									 v3[0], v3[1], v3[2]);


			Matrix<T, 3, 3> subMat30(v0[1], v0[2], v0[3],
									 v1[1], v1[2], v1[3],
									 v2[1], v2[2], v2[3]);

			Matrix<T, 3, 3> subMat31(v0[0], v0[2], v0[3],
									 v1[0], v1[2], v1[3],
									 v2[0], v2[2], v2[3]);

			Matrix<T, 3, 3> subMat32(v0[0], v0[1], v0[3],
									 v1[0], v1[1], v1[3],
									 v2[0], v2[1], v2[3]);

			Matrix<T, 3, 3> subMat33(v0[0], v0[1], v0[2],
									 v1[0], v1[1], v1[2],
									 v2[0], v2[1], v2[2]);

			return Matrix<T, 4, 4>(subMat00.Determinant(), -subMat01.Determinant(), subMat02.Determinant(), -subMat03.Determinant(),
								   -subMat10.Determinant(), subMat11.Determinant(), -subMat12.Determinant(), subMat13.Determinant(),
								   subMat20.Determinant(), -subMat21.Determinant(), subMat22.Determinant(), -subMat23.Determinant(),
								   -subMat30.Determinant(), subMat31.Determinant(), -subMat32.Determinant(), subMat33.Determinant()).Transponate();
		}
	};
}