#pragma once
#include "vector.h"

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

	template<class T, int Rows, int Cols>
	class Matrix
	{
	public:
		Vector<T, Rows> data_[Cols];

		inline Matrix() {};

		inline Matrix(T v00, T v01, T v10, T v11)
		{
			_STL_VERIFY(Rows == 2 && Cols == 2, "Size of matrix does not match");
			this->data_[0][0] = v00;
			this->data_[0][1] = v01;
			this->data_[1][0] = v10;
			this->data_[1][1] = v11;
		}

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

		inline Vector<T, Rows>& operator[](const int i)
		{
			return data_[i];
		}

		inline const Vector<T, Rows>& operator[](const int i) const
		{
			return data_[i];
		}

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
		inline Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& m)
		{
			MODMATH_MATRIX_OPERATOR(+, m.data_[i]);
		}

		template<class T, int Rows, int Cols>
		inline Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& m)
		{
			MODMATH_MATRIX_OPERATOR(-, m.data_[i]);
		}

		template<class T, int Rows, int Cols>
		inline Matrix<T, Rows, Cols> operator*(const Matrix<T, Rows, Cols>& m)
		{
			Matrix<T, Rows, Cols> result;

			for (int i = 0; i < Cols; i++)
			{
				Vector<T, Rows> colVec = m.ColToVector(i);

				for (int  j = 0; j < Rows; j++)
				{
					result.data_[j][i] = modmath::Vector<T, Rows>().DotProduct(this->data_[j], colVec);
				}
			}
			return result;
		}

		Matrix<T, Rows, Cols> operator +(const T s)
		{
			MODMATH_MATRIX_OPERATOR(+, s);
		}

		Matrix<T, Rows, Cols> operator -(const T s)
		{
			MODMATH_MATRIX_OPERATOR(-, s);
		}

		Matrix<T, Rows, Cols> operator *(const T s)
		{
			MODMATH_MATRIX_OPERATOR(*, s);
		}

		Matrix<T, Rows, Cols> operator /(const T s)
		{
			MODMATH_MATRIX_OPERATOR(/, s);
		}

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

		inline Vector<T, Cols> operator* (const Vector<T, Cols>& v)
		{
			Vector<T, Cols> result;
			for (int i = 0; i < Cols; i++)
			{
				result[i] = modmath::Vector<T, Cols>().DotProduct(this->data_[i], v);
			}
			return result;
		}


		static inline Matrix<T, 4, 4> RotationX(const Vector<T, 2> & v)
		{
			return Matrix<T, 4, 4> (1,     0,     0,     0,
									0,   v[0],  v[1],    0,
									0,  -v[1],  v[0],    0,
									0,     0,     0,     1);
		}

		static inline Matrix<T, 4, 4> RotationY(const Vector<T, 2> & v)
		{
			return Matrix<T, 4, 4>(v[0],    0,   -v[1],    0,
								     0,     1,      0,     0,
								   v[1],    0,    v[0],    0,
								     0,     0,      0,     1);
		}

		static inline Matrix<T, 4, 4> RotationZ(const Vector<T, 2> & v)
		{
			return Matrix<T, 4, 4>(v[0],   v[1],    0,     0,
								  -v[1],   v[0],    0,     0,
								     0,      0,     1,     0,
								     0,      0,     0,     1);
		}

		static inline Matrix<T, 4, 4> RotationX(T angle)
		{
			return RotationX(Vector<T, 2>(cosf(angle), sinf(angle)));
		}

		static inline Matrix<T, 4, 4> RotationY(T angle)
		{
			return RotationY(Vector<T, 2>(cosf(angle), sinf(angle)));
		}

		static inline Matrix<T, 4, 4> RotationZ(T angle)
		{
			return RotationZ(Vector<T, 2>(cosf(angle), sinf(angle)));
		}


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



	};
}