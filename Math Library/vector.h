#pragma once
#include <yvals.h>
#include <cmath>

#define MODMATH_VECTOR_OPERATOR(OP, Mod)					\
	{														\
		Vector<T, Dims> result;								\
		for (int i = 0; i < Dims; i++)						\
		{													\
			result.data_[i] = this->data_[i] OP Mod;		\
		}													\
		return result;										\
	}

#define POW2(x) ((x)*(x))
	
namespace modmath {

	template <class T, int Dims>
	class Vector
	{
	public:
		/**
		*
		*
		* @param Dims Number of elements in the vector
		*/
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

		inline T& operator[](const int i)
		{
			return data_[i];
		}

		inline const T& operator[](const int i) const
		{
			return data_[i];
		}

		inline T x()
		{
			return data_[0];
		}

		inline T y()
		{
			_STL_VERIFY(Dims > 1, "Vector out of bounds");
			return data_[1];
		}

		inline T z()
		{
			_STL_VERIFY(Dims > 2, "Vector out of bounds");
			return data_[2];
		}

		inline T w()
		{
			_STL_VERIFY(Dims > 3, "Vector out of bounds");
			return data_[3];
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

		template <class T, int Dims>
		inline Vector<T, Dims> operator*(const Vector<T, Dims>& v)
		{
			MODMATH_VECTOR_OPERATOR(*, v.data_[i]);
		}

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

		// Compute vector length
		inline T Length()
		{
			return LengthCalc(*this);
		}

		template<class T, int Dims>
		inline T LengthCalc(const Vector<T, Dims>& v)
		{
			T sum = 0;
			for (int i = 0; i < Dims; i++)
			{
				sum += POW2(v.data_[i]);
			}
			return sqrt(sum);
		}

		// Normalize this vector in-place
		inline T Normalize()
		{
			return NormalizeCalc(*this);
		}

		template<class T, int Dims>
		inline T NormalizeCalc(Vector<T, Dims> &v)
		{
			const T length = LengthCalc(v);
			v = v / length;
			return length;
		}

		// Compute normalized version of this vector
		inline Vector<T, Dims> Normalized()
		{
			return NormalizedCalc(*this);
		}

		template<class T, int Dims>
		inline Vector<T, Dims> NormalizedCalc(const Vector<T, Dims>& v)
		{
			Vector<T, Dims> normalized = *this;
			return normalized / LengthCalc(v);
		}


		static inline T Distance(Vector<T, Dims>& v1, const Vector<T, Dims>& v2)
		{
			return (v1 - v2).Length();
		}


		template <class T, int Dims>
		static inline T DotProduct(const Vector<T, Dims>& v1, const Vector<T, Dims>& v2)
		{
			T sum = 0;
			for (int i = 0; i < Dims; i++)
			{
				sum += v1.data_[i] * v2.data_[i];
			}
			return sum;
		}


		template<class T>
		static inline Vector<T, 3> CrossProduct(const Vector<T, 3>& v1, const Vector<T, 3>& v2)
		{
			return Vector<T, 3>
				(v1.data_[1] * v2.data_[2] - v1.data_[2] * v2.data_[1],
				-(v1.data_[0] * v2.data_[2] - v1.data_[2] * v2.data_[0]),
				v1.data_[0] * v2.data_[1] - v1.data_[1] * v2.data_[0]);
		}

	};
}