#pragma once
#include <yvals.h>
#include <cmath>
/// <summary>
/// Performs a given operation along with a modifier value.
/// </summary>
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
	
namespace modmath 
{
	/// <summary>
	/// Template Vector class with definable dimension
	/// </summary>
	template <class T, int Dims>
	class Vector
	{
	public:
		/// <summary>
		/// Vector data containing elements of class T
		/// </summary>
		T data_[Dims] = { 0 };

		/// <summary>
		/// Empty constructor
		/// </summary>
		inline Vector() {}
		
		/// <summary>
		/// Constructs a Vector from 2 values.
		/// </summary>
		/// <param name="v1">First value.</param>
		/// <param name="v2">Second value.</param>
		inline Vector(T v1, T v2)
		{
			_STL_VERIFY(Dims == 2, "Size of vectors does not match");
			this->data_[0] = v1;
			this->data_[1] = v2;
		}
		
		/// <summary>
		/// Contructs a Vector from 3 values.	
		/// </summary>
		/// <param name="v1">First value.</param>
		/// <param name="v2">Second value.</param>
		/// <param name="v3">Third value.</param>
		inline Vector(T v1, T v2, T v3)
		{
			_STL_VERIFY(Dims == 3, "Size of vectors does not match");
			this->data_[0] = v1;
			this->data_[1] = v2;
			this->data_[2] = v3;
		}

		/// <summary>
		/// Contructs a Vector from 4 values.	
		/// </summary>
		/// <param name="v1">First value.</param>
		/// <param name="v2">Second value.</param>
		/// <param name="v3">Third value.</param>
		/// <param name="v4">Fourth value.</param>
		inline Vector(T v1, T v2, T v3, T v4)
		{
			_STL_VERIFY(Dims == 4, "Size of vectors does not match");
			this->data_[0] = v1;
			this->data_[1] = v2;
			this->data_[2] = v3;
			this->data_[3] = v4;
		}

		/// <summary>
		/// Access a value from the Vector.
		/// </summary>
		/// <param name="i">Index of the value to access.</param>
		/// <returns>Reference to the value.</returns>
		inline T& operator[](const int i)
		{
			return data_[i];
		}

		/// <summary>
		/// Access a value from the Vector.
		/// </summary>
		/// <param name="i">Index of the value to access.</param>
		/// <returns>Reference to the value.</returns>
		inline const T& operator[](const int i) const
		{
			return data_[i];
		}

		/// <summary>
		/// Alternative way of accessing the first value (x).
		/// </summary>
		/// <returns></returns>
		inline T x()
		{
			return data_[0];
		}

		/// <summary>
		/// Alternative way of accessing the second value (y).
		/// </summary>
		/// <returns></returns>
		inline T y()
		{
			_STL_VERIFY(Dims > 1, "Vector out of bounds");
			return data_[1];
		}

		/// <summary>
		/// Alternative way of accessing the third value (z).
		/// </summary>
		/// <returns></returns>	
		inline T z()
		{
			_STL_VERIFY(Dims > 2, "Vector out of bounds");
			return data_[2];
		}

		/// <summary>
		/// Alternative way of accessing the fourth value (w).
		/// </summary>
		/// <returns></returns>
		inline T w()
		{
			_STL_VERIFY(Dims > 3, "Vector out of bounds");
			return data_[3];
		}

		/// <summary>
		/// Copies values from another Vector to a new one.
		/// </summary>
		/// <param name="v">Vector to copy from.</param>
		inline Vector(const Vector<T, Dims> &v)
		{
			for (int i = 0; i < Dims; i++)
			{
				this->data_[i] = v.data_[i];
			}
		}

		template <class T, int Dims>
		/// <summary>
		/// Performs addition between two Vectors.
		/// </summary>
		/// <param name="v">Vector to add.</param>
		/// <returns>Vector containing the addition of two Vectors.</returns>
		inline Vector<T, Dims> operator+(const Vector<T, Dims> &v) const
		{
			MODMATH_VECTOR_OPERATOR(+, v.data_[i]);
		}

		template <class T, int Dims>
		/// <summary>
		/// Performs subtraction between two Vectors.
		/// </summary>
		/// <param name="v">Vector to subtract.</param>
		/// <returns>Vector containing the subtraction of two Vectors.</returns>
		inline Vector<T, Dims> operator-(const Vector<T, Dims>& v) const
		{
			MODMATH_VECTOR_OPERATOR(-, v.data_[i]);
		}

		template <class T, int Dims>
		/// <summary>
		/// Performs component-wise multiplication between two Vectors.
		/// </summary>
		/// <param name="v">Vector to multiply.</param>
		/// <returns>Vector containing the product of two Vectors.</returns>
		inline Vector<T, Dims> operator*(const Vector<T, Dims>& v) const
		{
			MODMATH_VECTOR_OPERATOR(*, v.data_[i]);
		}

		template <class T, int Dims>
		/// <summary>
		/// Performs component-wise division between two Vectors.
		/// </summary>
		/// <param name="v">Vector to divide.</param>
		/// <returns>Vector containing the quota of two Vectors.</returns>
		inline Vector<T, Dims> operator/(const Vector<T, Dims>& v) const
		{
			MODMATH_VECTOR_OPERATOR(/ , v.data_[i]);
		}

		/// <summary>
		/// Performs addition between a Vector and a scalar.
		/// </summary>
		/// <param name="v">Scalar to add.</param>
		/// <returns>Vector with added scalar.</returns>
		Vector<T, Dims> operator+(const T s) const
		{
			MODMATH_VECTOR_OPERATOR(+, s);
		}

		/// <summary>
		/// Performs subtraction between a Vector and a scalar.
		/// </summary>
		/// <param name="v">Scalar to subtract.</param>
		/// <returns>Vector with subtracted scalar.</returns>
		Vector<T, Dims> operator-(const T s) const
		{
			MODMATH_VECTOR_OPERATOR(-, s);
		}

		/// <summary>
		/// Performs multiplication between a Vector and a scalar.
		/// </summary>
		/// <param name="v">Scalar to multiply.</param>
		/// <returns>Vector with multiplied scalar.</returns>
		Vector<T, Dims> operator*(const T s) const
		{
			MODMATH_VECTOR_OPERATOR(*, s);
		}

		/// <summary>
		/// Performs division between a Vector and a scalar.
		/// </summary>
		/// <param name="v">Scalar to divide.</param>
		/// <returns>Vector with divided scalar.</returns>
		Vector<T, Dims> operator/(const T s) const
		{
			MODMATH_VECTOR_OPERATOR(/, s);
		}

		/// <summary>
		/// Calculates the length of a Vector.
		/// </summary>
		/// <returns>Length of the Vector.</returns>
		inline T Length()
		{
			return LengthCalc(*this);
		}

		template<class T, int Dims>
		/// <summary>
		/// Calculates the length of a Vector.
		/// </summary>
		/// <param name="v">Vector to calculate.</param>
		/// <returns>Length of the Vector.</returns>
		inline T LengthCalc(const Vector<T, Dims>& v)
		{
			T sum = 0;
			for (int i = 0; i < Dims; i++)
			{
				sum += POW2(v.data_[i]);
			}
			return sqrt(sum);
		}

		/// <summary>
		/// Normalize this Vector in-place.
		/// </summary>
		/// <returns>Length of this Vector.</returns>
		inline T Normalize()
		{
			return NormalizeCalc(*this);
		}

		template<class T, int Dims>
		/// <summary>
		/// Normalize this Vector in-place.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <returns>Length of this Vector.</returns>
		inline T NormalizeCalc(Vector<T, Dims> &v)
		{
			const T length = LengthCalc(v);
			if (length == 0) { return 0.0f; }

			v = v / length;
			return length;
		}

		/// <summary>
		/// Calculates the normilized version of a Vector.
		/// </summary>
		/// <returns>Normalized Vector.</returns>
		inline Vector<T, Dims> Normalized()
		{
			return NormalizedCalc(*this);
		}

		template<class T, int Dims>
		/// <summary>
		/// Calculates the normilized version of a Vector.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <returns>Normalized Vector.</returns>
		inline Vector<T, Dims> NormalizedCalc(const Vector<T, Dims>& v)
		{
			if (LengthCalc(v) == 0) { return v * 0; }

			Vector<T, Dims> normalized = *this;
			return normalized / LengthCalc(v);
		}

		/// <summary>
		/// Calculates the distance between two Vectors.
		/// </summary>
		/// <param name="v1">First Vector.</param>
		/// <param name="v2">Second Vector.</param>
		/// <returns>Distance between the two Vectors.</returns>
		static inline T Distance(Vector<T, Dims>& v1, const Vector<T, Dims>& v2)
		{
			return (v1 - v2).Length();
		}

		template <class T, int Dims>
		/// <summary>
		/// Calculates the dot product between two Vectors.
		/// </summary>
		/// <param name="v1">First Vector.</param>
		/// <param name="v2">Second Vector.</param>
		/// <returns>Dot product of the two vectors.</returns>
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
		/// <summary>
		/// Calculates the cross product between two Vectors.
		/// </summary>
		/// <param name="v1">First Vector.</param>
		/// <param name="v2">Second Vector.</param>
		/// <returns>Cross product of the two Vectors.</returns>
		static inline Vector<T, 3> CrossProduct(const Vector<T, 3>& v1, const Vector<T, 3>& v2)
		{
			return Vector<T, 3>
				(v1.data_[1] * v2.data_[2] - v1.data_[2] * v2.data_[1],
				-(v1.data_[0] * v2.data_[2] - v1.data_[2] * v2.data_[0]),
				v1.data_[0] * v2.data_[1] - v1.data_[1] * v2.data_[0]);
		}
	};
}