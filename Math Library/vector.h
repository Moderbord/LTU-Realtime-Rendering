#pragma once
#include <yvals.h>

#define MODMATH_VECTOR_OPERATOR(OP, Mod)					\
	{														\
		Vector<T, Dims> result;								\
		for (int i = 0; i < Dims; i++)						\
		{													\
			result.data_[i] = this->data_[i] OP Mod;		\
		}													\
		return result;										\
	}
	
namespace modmath {

	template <class T, int Dims>
	class Vector
	{
	public:
		// Field
		T data_[Dims];

		// Constructors
		inline Vector(){}
		// Create a vector from 2 elements
		inline Vector(T v1, T v2)
		{
			_STL_VERIFY(Dims == 2, "Size of vectors does not match");
			this->data_[0] = v1;
			this->data_[1] = v2;
		}
		// Create a vector from 3 values
		inline Vector(T v1, T v2, T v3)
		{
			_STL_VERIFY(Dims == 3, "Size of vectors does not match");
			this->data_[0] = v1;
			this->data_[1] = v2;
			this->data_[2] = v3;
		}
		// Create a vector from 4 values
		inline Vector(T v1, T v2, T v3, T v4)
		{
			_STL_VERIFY(Dims == 4, "Size of vectors does not match");
			this->data_[0] = v1;
			this->data_[1] = v2;
			this->data_[2] = v3;
			this->data_[3] = v4;
		}

		// Create a vector from another vector
		inline Vector(const Vector<T, Dims> &v)
		{
			for (int i = 0; i < Dims; i++)
			{
				this->data_[i] = v.data_[i];
			}
		}

		// Addition between two vectors
		template <class T, int Dims>
		inline Vector<T, Dims> operator+(const Vector<T, Dims> &v)
		{
			MODMATH_VECTOR_OPERATOR(+, v.data_[i]);
		}

		// Subtraction between two vectors
		template <class T, int Dims>
		inline Vector<T, Dims> operator-(const Vector<T, Dims>& v)
		{
			MODMATH_VECTOR_OPERATOR(-, v.data_[i]);
		}

		// Multiplication between two vectors
		template <class T, int Dims>
		inline Vector<T, Dims> operator*(const Vector<T, Dims>& v)
		{
			MODMATH_VECTOR_OPERATOR(*, v.data_[i]);
		}

		// Division between two vectors
		template <class T, int Dims>
		inline Vector<T, Dims> operator/(const Vector<T, Dims>& v)
		{
			MODMATH_VECTOR_OPERATOR(/ , v.data_[i]);
		}

		// Addition between a vector and a scalar
		Vector<T, Dims> operator+(const T s)
		{
			MODMATH_VECTOR_OPERATOR(+, s);
		}

		// Subtraction between a vector and a scalar
		Vector<T, Dims> operator-(const T s)
		{
			MODMATH_VECTOR_OPERATOR(-, s);
		}

		// Multiplication between a vector and a scalar
		Vector<T, Dims> operator*(const T s)
		{
			MODMATH_VECTOR_OPERATOR(*, s);
		}

		// Division between a vector and a scalar
		Vector<T, Dims> operator/(const T s)
		{
			MODMATH_VECTOR_OPERATOR(/, s);
		}

	};
}